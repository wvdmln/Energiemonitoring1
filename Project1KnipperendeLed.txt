#include <Arduino.h>

int ledPin = 12;

void setup()
{
  // put your setup code here, to run once:
  pinMode(ledPin, OUTPUT);
  Serial.begin(9600);
}

void loop()
{
  // put your main code here, to run repeatedly:
  digitalWrite(ledPin, HIGH);
  Serial.println("LED is aan");
  delay(200);
  digitalWrite(ledPin, LOW);
  Serial.println("LED is uit");
  delay(800);
}