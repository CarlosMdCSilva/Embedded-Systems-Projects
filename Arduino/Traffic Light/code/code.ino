#define greenWait 1000
#define changeLight 2000
#define redLedPin 4
#define yellowLedPin 3
#define greenLedPin 2
#define redLedPedestrianPin 12
#define BUTTON 13
#define A 10
#define B 11
#define C 7
#define D 6
#define E 5
#define F 9
#define G 8
int buttonStatus = 0;

void clrLed() {
  digitalWrite(A, HIGH);
  digitalWrite(B, HIGH);
  digitalWrite(C, HIGH);
  digitalWrite(D, HIGH);
  digitalWrite(E, HIGH);
  digitalWrite(F, HIGH);
  digitalWrite(G, HIGH);
}

void one() {
  digitalWrite(A, HIGH);
  digitalWrite(B, LOW);
  digitalWrite(C, LOW);
  digitalWrite(D, HIGH);
  digitalWrite(E, HIGH);
  digitalWrite(F, HIGH);
  digitalWrite(G, HIGH);
  delay(greenWait);
}

void two() {
  digitalWrite(A, LOW);
  digitalWrite(B, LOW);
  digitalWrite(C, HIGH);
  digitalWrite(D, LOW);
  digitalWrite(E, LOW);
  digitalWrite(F, HIGH);
  digitalWrite(G, LOW);
  delay(greenWait);
}

void three() {
  digitalWrite(A, LOW);
  digitalWrite(B, LOW);
  digitalWrite(C, LOW);
  digitalWrite(D, LOW);
  digitalWrite(E, HIGH);
  digitalWrite(F, HIGH);
  digitalWrite(G, LOW);
  delay(greenWait);
}

void four() {
  digitalWrite(A, HIGH);
  digitalWrite(B, LOW);
  digitalWrite(C, LOW);
  digitalWrite(D, HIGH);
  digitalWrite(E, HIGH);
  digitalWrite(F, LOW);
  digitalWrite(G, LOW);
  delay(greenWait);
}

void five() {
  digitalWrite(A, LOW);
  digitalWrite(B, HIGH);
  digitalWrite(C, LOW);
  digitalWrite(D, LOW);
  digitalWrite(E, HIGH);
  digitalWrite(F, LOW);
  digitalWrite(G, LOW);
  delay(greenWait);
}

void six() {
  digitalWrite(A, LOW);
  digitalWrite(B, HIGH);
  digitalWrite(C, LOW);
  digitalWrite(D, LOW);
  digitalWrite(E, LOW);
  digitalWrite(F, LOW);
  digitalWrite(G, LOW);
  delay(greenWait);
}

void seven() {
  digitalWrite(A, LOW);
  digitalWrite(B, LOW);
  digitalWrite(C, LOW);
  digitalWrite(D, HIGH);
  digitalWrite(E, HIGH);
  digitalWrite(F, HIGH);
  digitalWrite(G, HIGH);
  delay(greenWait);
}

void eight() {
  digitalWrite(A, LOW);
  digitalWrite(B, LOW);
  digitalWrite(C, LOW);
  digitalWrite(D, LOW);
  digitalWrite(E, LOW);
  digitalWrite(F, LOW);
  digitalWrite(G, LOW);
  delay(greenWait);
}

void nine() {
  Serial.println("Dentro 9");
  digitalWrite(A, LOW);
  digitalWrite(B, LOW);
  digitalWrite(C, LOW);
  digitalWrite(D, LOW);
  digitalWrite(E, HIGH);
  digitalWrite(F, LOW);
  digitalWrite(G, LOW);
  delay(greenWait);
}

void zero() {
  digitalWrite(A, LOW);
  digitalWrite(B, LOW);
  digitalWrite(C, LOW);
  digitalWrite(D, LOW);
  digitalWrite(E, LOW);
  digitalWrite(F, LOW);
  digitalWrite(G, HIGH);
  delay(greenWait);
}

void greenCountDown() {
  digitalWrite(redLedPedestrianPin, LOW);
  nine();
  eight();
  seven();
  six();
  five();
  four();
  three();
  two();
  one();
  zero();
  digitalWrite(redLedPedestrianPin, HIGH);
  clrLed();
  delay(changeLight);
}

void setup() {
  // Seting Led output port
  pinMode(redLedPin, OUTPUT);
  pinMode(yellowLedPin, OUTPUT);
  pinMode(greenLedPin, OUTPUT);
  pinMode(redLedPedestrianPin, OUTPUT);
  pinMode(BUTTON, INPUT);
  pinMode(A, OUTPUT);
  pinMode(B, OUTPUT);
  pinMode(C, OUTPUT);
  pinMode(D, OUTPUT);
  pinMode(E, OUTPUT);
  pinMode(F, OUTPUT);
  pinMode(G, OUTPUT);
}

void loop() {

  buttonStatus = digitalRead(BUTTON);

  if (buttonStatus == HIGH) {
    delay(3000);
    digitalWrite(yellowLedPin, HIGH);
    digitalWrite(greenLedPin, LOW);
    delay(changeLight);
    digitalWrite(yellowLedPin, LOW);
    digitalWrite(redLedPin, HIGH);
    delay(changeLight);
    greenCountDown();
    digitalWrite(yellowLedPin, HIGH);
    delay(changeLight);
    buttonStatus = 0;
  } else {
    digitalWrite(redLedPedestrianPin, HIGH);
    digitalWrite(greenLedPin, HIGH);
    digitalWrite(yellowLedPin, LOW);
    digitalWrite(redLedPin, LOW);
    clrLed();
  }
}
