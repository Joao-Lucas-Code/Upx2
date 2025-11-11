#include <Arduino.h>
// --- PINOS CORRIGIDOS PARA O NOVO TESTE ---
const int pinoTrig = 26;  // Pino D26 (Saída)
const int pinoEcho = 25; // Pino D25 (Entrada)

// --- VARIÁVEIS GLOBAIS ---
long duracao;
float distancia; 
const int LIMITE_CHEIA = 10;       
const int LIMITE_QUASE_CHEIA = 30; 

void setup() {
  Serial.begin(115200); 
  
  pinMode(pinoTrig, OUTPUT); // D26 configurado como SAÍDA
  pinMode(pinoEcho, INPUT);  // D25 configurado como ENTRADA

  Serial.println(">>> Lixeira Automática - Monitor de Status (Real) <<<");
  Serial.println("Testando com Trig no D26 e Echo no D25...");
}

void loop() {
  // Dispara o pulso ultrassônico
  digitalWrite(pinoTrig, LOW);
  delayMicroseconds(2);
  digitalWrite(pinoTrig, HIGH);
  delayMicroseconds(10);
  digitalWrite(pinoTrig, LOW);

  // Lê o tempo de retorno
  duracao = pulseIn(pinoEcho, HIGH);

  // Calcula a distância
  distancia = duracao * 0.0343 / 2;

  // --- LÓGICA PRINCIPAL ---
  Serial.print("Distancia: ");
  Serial.print(distancia);
  Serial.print(" cm | Status: ");

  if (distancia <= LIMITE_CHEIA) {
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