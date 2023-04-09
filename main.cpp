#include <Wire.h>
#include <LiquidCrystal_I2C.h>
LiquidCrystal_I2C lcd(0x27, 16, 2);  // I2C adresa koju smo skenirali , broj slova, broj redova

int trigPin = 11;  // Trigger
int echoPin = 12;  // Echo
long duration, cm, inches;

void setup() {
  Serial.begin(9600);

  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);

  lcd.begin();      // pocetak rada display-a
  lcd.backlight();  // paljenje pozadinskog svjetla
}

void loop() {
  digitalWrite(trigPin, LOW);
  delayMicroseconds(5);
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);

  pinMode(echoPin, INPUT);
  duration = pulseIn(echoPin, HIGH);

  // Konverzija vremena u udaljenost

  // Podijeliti sa 29.1 ili pomnožiti sa 0.0343
  cm = (duration / 2) * 0.0343;

  //Podijeliti sa 74 ili pomnožiti 0.0135
  inches = (duration / 2) / 74;  // izbrisite ako ne zelite ince

  lcd.setCursor(0, 0);
  lcd.print("Udaljen.cm ");
  lcd.print(cm);
  lcd.setCursor(0, 1);
  lcd.print("Udaljen. in ");
  lcd.print(inches);
  //lcd.clear();
  delay(1000);
}
