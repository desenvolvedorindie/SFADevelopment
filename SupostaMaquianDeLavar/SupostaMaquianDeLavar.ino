/**
  *  Suposta máquina de lavar (conceito de estados)
  *
  *  @autor Welsiton Ferreira (www.youtube.com/wfcreations)
  */

// Declaração de estados
typedef enum {
  STATE_CONFIG, // Estado de configuração
  STATE_WASH, // Estado de Lavagem
  STATE_RINSING, // Estado de Enxague
  STATE_SPINNING, // Estado de Centrifugação
  END_STATE // Estado final
} state;

// Declarações de funções
void configStep();
void washStep();
void rinsingStep();
void spinningStep();

// Declarações de variávies
state currentState;
int rinsingQuantity;
int rinsingCount;

void setup() {
  Serial.begin(9600);
  
  // Configuração inicial da máquina
  currentState = STATE_CONFIG;
  rinsingCount = 0;
}

void loop() {
  if(currentState == STATE_CONFIG) {
    configStep();
    currentState = STATE_WASH;
  }
  else if (currentState == STATE_WASH) {
    washStep();
    currentState = STATE_RINSING;
  }
  else if (currentState == STATE_RINSING) {
    if(rinsingCount < rinsingQuantity) {
      rinsingStep(rinsingCount);
      rinsingCount++;
    } else {
      currentState = STATE_SPINNING; 
    }
  }
  else if (currentState == STATE_SPINNING) {
    spinningStep();
    currentState = END_STATE;
  }
}

void configStep() {
   Serial.println("----- Iniciando o processo de configuracao -----");
   Serial.println("Digite quantos enxagues: ");
   while(true) {
     if(Serial.available() > 0) { 
       rinsingQuantity = Serial.read() - 48;
       break;
     }
   }
   Serial.print("Numeros de exagues definido: ");
   Serial.println(rinsingQuantity);
   Serial.println("----- Finalizado o processo de configuracao -----");
   Serial.println();
}

void washStep() {
  Serial.println("----- Iniciando o processo de lavagem -----");
  Serial.println("Acionando valvula de selenoide, ate atingir 5 litros");
  delay(2000);
  Serial.println("Desligando valvula de selenoide");
  delay(2000);
  Serial.println("Aciona micro-bomba para drenagem do sabao, por 30 segundos");
  delay(2000);
  Serial.println("Desligando micro-bomba");
  delay(2000);
  Serial.println("Aciona motor por 45 minutos");
  delay(9000);
  Serial.println("Desliga o motor");
  delay(2000);
  Serial.println("Aciona bomba de drenagem, ate esvaziar o tanque");
  delay(4000);
  Serial.println("Desliga bomba de drenagem");
  Serial.println("----- Finalizando o processo de lavagem -----");
  Serial.println();
  delay(5000);
}

void rinsingStep(int rinsingCount) {
  Serial.println("----- Iniciando o processo de enxague -----");
  Serial.print("Enxague de numero : ");
  Serial.println(rinsingCount + 1);
  Serial.println("Acionando valvula de selenoide, ate atingir 5 litros");
  delay(2000);
  Serial.println("Desliga vavula");
  delay(2000);
  Serial.println("Aciona motor por 45 minutos");
  delay(4500);
  Serial.println("Desliga o motor");
  delay(2000);
  Serial.println("Aciona bomba de drenagem, ate esvaziar o tanque");
  delay(3000);
  Serial.println("Desliga bomba de drenagem");
  Serial.println("----- Finalizando o processo de enxague -----");
  Serial.println();
  delay(5000);
}

void spinningStep() {
  Serial.println("----- Iniciando o processo de centrifugacao -----");
  Serial.println("Acionando bomba de drenagem");
  delay(2000);
  Serial.println("Aciona motor por 20 minutos");
  delay(2000);
  Serial.println("Desliga o motor");
  delay(3000);
  Serial.println("Desliga bomba de drenagem");
  Serial.println("----- Finalizando o processo de centrifugacao -----");
  Serial.println();
  delay(5000);
}
