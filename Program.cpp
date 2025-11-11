#include <Arduino.h>
// --- PINOS CORRIGIDOS PARA A SUA MONTAGEM ---
const int pinoTrig = 27;  // Pino D27 (que pode ser Saída)
const int pinoEcho = 35; // Pino D35 (que é Entrada, perfeito!)

// --- VARIÁVEIS GLOBAIS ---
long duracao;
float distancia; 
const int LIMITE_CHEIA = 10;       
const int LIMITE_QUASE_CHEIA = 30; 

void setup() {
  Serial.begin(115200); 
  
  pinMode(pinoTrig, OUTPUT); // D27 configurado como SAÍDA
  pinMode(pinoEcho, INPUT);  // D35 configurado como ENTRADA

  Serial.println(">>> Lixeira Automática - Monitor de Status (Real) <<<");
  Serial.println("Testando com Trig no D27 e Echo no D35...");
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