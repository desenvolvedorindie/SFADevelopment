/**
  *  Suposta máquina de lavar (conceito de concorrência)
  *
  *  @autor Welsiton Ferreira (www.youtube.com/wfcreations)
  */

// Declarações de funções
void invertLedState(); 
void verifyDoor();

// Declarações de variáveis
boolean ledOn = false;

void setup() {
  Serial.begin(9600);
}

void loop() {
  invertLedState();
  delay(1000);
  invertLedState();
  delay(1000);
}

void invertLedState() {
  ledOn = !ledOn;
  if(ledOn) {
    Serial.println("Acende led da porta 13"); // digitalWrite(13, HIGH);
  } else {
    Serial.println("Apaga led da porta 13"); //digitalWrite(13, LOW);
  }
}

void verifyDoor() {
  Serial.println("Verificando porta...");
  delay(100);
}
