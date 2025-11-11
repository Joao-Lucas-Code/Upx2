// --- PINOS 100% SEGUROS (D26 e D25) ---
const int pinoTrig = 26;  // Fio Laranja (Trig) no pino D26
const int pinoEcho = 25; // Fio Amarelo (Echo) no pino D25

// --- VARIÁVEIS GLOBAIS ---
long duracao;
float distancia; 
const int LIMITE_CHEIA = 10;       
const int LIMITE_QUASE_CHEIA = 30; 

void setup() {
  Serial.begin(115200); 
  
  pinMode(pinoTrig, OUTPUT); // D26 como SAÍDA
  pinMode(pinoEcho, INPUT);  // D25 como ENTRADA

  Serial.println(">>> Lixeira Automática - Teste do Zero <<<");
  Serial.println("Testando com Trig no D26 e Echo no D25...");
}

void loop() {
  // Dispara o pulso ultrassônico (O "Grito")
  digitalWrite(pinoTrig, LOW);
  delayMicroseconds(2);
  digitalWrite(pinoTrig, HIGH);
  delayMicroseconds(10);
  digitalWrite(pinoTrig, LOW);

  // Lê o tempo de retorno (O "Eco")
  // Colocamos um timeout de 30000 microssegundos para evitar leituras 0.00
  duracao = pulseIn(pinoEcho, HIGH, 30000); 

  // Calcula a distância
  distancia = duracao * 0.0343 / 2;

  // --- LÓGICA PRINCIPAL ---
  Serial.print("Distancia: ");
  Serial.print(distancia);
  Serial.print(" cm | Status: ");

  if (distancia == 0) {
    Serial.println("Falha na leitura (Timeout)"); // Mensagem de erro clara
  }
  else if (distancia <= LIMITE_CHEIA) {
    Serial.println("LIXEIRA CHEIA!");
  } 
  else if (distancia <= LIMITE_QUASE_CHEIA) {
    Serial.println("Quase cheia...");
  } 
  else {
    Serial.println("Vazia.");
  }

  delay(1000); 
}