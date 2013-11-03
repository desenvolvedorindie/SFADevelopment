/**
 *  Suposta máquina de lavar (conceito de evento)
 *  Baseado em: http://arduino.cc/en/Tutorial/Button
 *
 *  @autor Welsiton Ferreira (www.youtube.com/wfcreations)
 */

const int door = 2;

void highEvent();
void lowEvent();

int doorState;
int lastDoorState;

void setup() {
  Serial.begin(9600);
  pinMode(door, INPUT);
  lastDoorState = digitalRead(door);
}

void loop() {
  int doorState = digitalRead(door);

  if (doorState != lastDoorState) {
    if (doorState == HIGH) { 
      highEvent();
    } 
    else {
      lowEvent();
    }
    lastDoorState = doorState;
  }
}

void highEvent() {
  Serial.println("Continua");
}

void lowEvent() {
  Serial.println("Pausa Maquina");  
}


