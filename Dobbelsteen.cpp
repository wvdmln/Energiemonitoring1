#include <Arduino.h>

int pinLed1 = 3;
int pinLed2 = 5;
int pinLed3 = 4;
int pinLed4 = 8;
int pinLed5 = 7;
int pinLed6 = 9;
int pinLed7 = 6;
int buttonPin = 10;

void setup()
{
  pinMode(pinLed1, OUTPUT);
  //enz.enz.
  pinMode(buttonPin, INPUT_PULLUP);
  randomSeed(analogRead(0)); //Om het toevalsproces van de functie random te starten
}

void loop()
{
  int value;
  if (digitalRead(buttonPin) == LOW)
  {                       // Ja! De schakelaar is ingedrukt.
    value = random(1, 7); //Kies een getal van 1 t/m 6, 7 telt niet mee
    if (value == 1)
      digitalWrite(pinLed7, HIGH);
    if (value == 2)
    {
      digitalWrite(pinLed3, HIGH);
      digitalWrite(pinLed4, HIGH);
    }
    if (value == 3)
    {
      digitalWrite(pinLed3, HIGH);
      digitalWrite(pinLed4, HIGH);
      digitalWrite(pinLed7, HIGH);
    }
    if (value == 4)
    {
      digitalWrite(pinLed1, HIGH);
      digitalWrite(pinLed3, HIGH);
      digitalWrite(pinLed4, HIGH);
      digitalWrite(pinLed6, HIGH);
    }
    if (value == 5)
    {
      digitalWrite(pinLed1, HIGH);
      digitalWrite(pinLed3, HIGH);
      digitalWrite(pinLed4, HIGH);
      digitalWrite(pinLed6, HIGH);
      digitalWrite(pinLed7, HIGH);
    }
    if (value == 6)
    {
      digitalWrite(pinLed1, HIGH);
      //enz.enz.
    }
    delay(1000); // Zet de Led's na 1 seconde weer uit
    digitalWrite(pinLed1, LOW);
    //enz. enz.
  }
}
