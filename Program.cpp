// --- DEFINIÇÕES DO BLYNK (AS SUAS CREDENCIAIS CORRETAS) ---
#define BLYNK_TEMPLATE_ID "#YOUR_TEMPLATE"
#define BLYNK_TEMPLATE_NAME "#YOUR_TEMPLATE_NAME"
#define BLYNK_AUTH_TOKEN "#YOUR_BLYNK"

// --- DEFINIÇÕES DE HARDWARE E BIBLIOTECAS ---
#define BLYNK_PRINT Serial
#include <WiFi.h>
#include <WiFiMulti.h>
#include <BlynkSimpleEsp32.h>

// --- PINOS DO SENSOR (OS QUE FUNCIONARAM) ---
const int pinoTrig = 26;  // Fio Laranja (Saída)
const int pinoEcho = 25; // Fio Amarelo (Entrada)

// --- PINOS VIRTUAIS DO BLYNK ---
#define VPIN_DISTANCIA V0
#define VPIN_STATUS V1

// --- SEU WI-FI ---
char ssid[] = "#";
char pass[] = "#";

// --- VARIÁVEIS GLOBAIS ---
BlynkTimer timer; // O timer do Blynk
float distancia;
String statusLixeira;

// --- LIMITES DA LIXEIRA ---
const int LIMITE_CHEIA = 10;       
const int LIMITE_QUASE_CHEIA = 30; 

// ESTA FUNÇÃO RODA A CADA 2 SEGUNDOS
void sendSensorData() {
  // Dispara o pulso ultrassônico
  digitalWrite(pinoTrig, LOW);
  delayMicroseconds(2);
  digitalWrite(pinoTrig, HIGH);
  delayMicroseconds(10);
  digitalWrite(pinoTrig, LOW);

  // Lê o tempo de retorno (eco)
  long duracao = pulseIn(pinoEcho, HIGH, 30000); 
  distancia = duracao * 0.0343 / 2;

  // --- LÓGICA PRINCIPAL ---
  if (distancia == 0) {
    statusLixeira = "Falha no sensor";
  } else if (distancia <= LIMITE_CHEIA) {
    statusLixeira = "LIXEIRA CHEIA!";
  } else if (distancia <= LIMITE_QUASE_CHEIA) {
    statusLixeira = "Quase cheia...";
  } else {
    statusLixeira = "Vazia";
  }

  // --- ENVIAR PARA O BLYNK ---
  Blynk.virtualWrite(VPIN_DISTANCIA, distancia); 
  Blynk.virtualWrite(VPIN_STATUS, statusLixeira);   

  // Imprimir no Serial Monitor para checar
  Serial.print("Enviando para o Blynk -> Distancia: ");
  Serial.print(distancia);
  Serial.print(" cm | Status: ");
  Serial.println(statusLixeira);
}

void setup() {
  Serial.begin(115200);
  
  pinMode(pinoTrig, OUTPUT);
  pinMode(pinoEcho, INPUT);
  
  // Inicia a conexão Wi-Fi e Blynk
  Serial.println("Conectando ao Wi-Fi...");
  Blynk.begin(BLYNK_AUTH_TOKEN, ssid, pass);
  Serial.println("Conectado ao Blynk!");

  // Configura o timer
  timer.setInterval(2000L, sendSensorData);
}

void loop() {
  Blynk.run(); 
  timer.run(); 
}