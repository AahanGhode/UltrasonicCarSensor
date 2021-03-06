const int trigPin = 2;
const int echoPin = 3;
const int LEDRed = 4;
const int LEDGreen = 5;
const int LEDBlue = 6;
const int buzzer = 7;
int sound = 500;

void setup() {
Serial.begin (9600);
pinMode(trigPin, OUTPUT);
pinMode(echoPin, INPUT);
pinMode(LEDRed, OUTPUT);
pinMode(LEDGreen, OUTPUT);
pinMode(LEDBlue, OUTPUT);
pinMode(buzzer, OUTPUT);
}
void loop() {
long durationindigit, distanceincm;
digitalWrite(trigPin, LOW);
delayMicroseconds(2);
digitalWrite(trigPin, HIGH);
delayMicroseconds(10);
digitalWrite(trigPin, LOW);
durationindigit = pulseIn(echoPin, HIGH);
distanceincm = (durationindigit * 0.034) / 2;

if (distanceincm > 50) {
digitalWrite(LEDBlue, LOW);
digitalWrite(LEDGreen, LOW);
digitalWrite(LEDRed, LOW);
noTone(buzzer);
}
else if (distanceincm <= 50 && distanceincm > 20) {
digitalWrite(LEDGreen, HIGH);
digitalWrite(LEDBlue, LOW);
digitalWrite(LEDRed, LOW);
noTone(buzzer);
}
else if (distanceincm <= 20 && distanceincm > 10) {
digitalWrite(LEDBlue, LOW);
digitalWrite(LEDGreen, HIGH);
digitalWrite(LEDRed, HIGH);
tone(buzzer, 500);
}

else if (distanceincm <= 10) {
tone(buzzer, 1000);
digitalWrite(LEDRed, HIGH);

}

Serial.print(distanceincm);
Serial.println(" cm");

delay(300);
}
