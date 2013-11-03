/**
 *  Suposta máquina de lavar (conceito de evento)
 *  Baseado em: http://arduino.cc/en/Tutorial/Debounce
 *
 *  @autor Welsiton Ferreira (www.youtube.com/wfcreations)
 */

const int door = 2;

void highEvent();
void lowEvent();

int doorState;
int lastDoorState;

long lastDebounceTime = 0;
const long debounceDelay = 50;

void setup() {
  Serial.begin(9600);
  pinMode(door, INPUT);
  lastDoorState = digitalRead(door);
}

void loop() {
  int reading = digitalRead(door);

  if (reading != lastDoorState) {
    lastDebounceTime = millis();
  }

  if ((millis() - lastDebounceTime) >= debounceDelay) {
    if (reading != doorState) {
      doorState = reading;
      
      if (doorState == HIGH) {
        highEvent();
      } 
      else {
        lowEvent();
      }
    }
  }
  lastDoorState = reading;
}

void highEvent() {
  Serial.println("Continua");
}
   
void lowEvent() {
  Serial.println("Pausa Maquina");  
}

