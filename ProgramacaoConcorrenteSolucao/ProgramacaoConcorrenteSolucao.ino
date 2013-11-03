/**
 *  Suposta máquina de lavar (conceito de concorrência, solução 1)
 *
 *  @autor Welsiton Ferreira (www.youtube.com/wfcreations)
 */

// Declarações de funções
void invertLedState(); 
void verifyDoor();

// Declarações de variáveis
boolean ledOn = false;

long timestamp = 0;
const long DELAY = 1000;

void setup() {
  Serial.begin(9600);
}

void loop() {
  long difference = millis() - timestamp;
  if(difference >= DELAY) {
    invertLedState();
    timestamp = millis();
  }
  verifyDoor();
}

void invertLedState() {
  ledOn = !ledOn;
  if(ledOn) {
    Serial.println("Acende led da porta 13"); // digitalWrite(13, HIGH);
  } 
  else {
    Serial.println("Apaga led da porta 13"); //digitalWrite(13, LOW);
  }
}

void verifyDoor() {
  Serial.println("Verificando porta...");
  delay(100);
}

