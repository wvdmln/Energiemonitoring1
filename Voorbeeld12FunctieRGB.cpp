#include <Arduino.h>

int meetpin = A0;
int meetwaarde = 0;
int PWMwaarde = 0;

int redLed = 9;
int greenLed = 10;
int blueLed = 11;

int R = 0;
int G = 0;
int B = 0;

void setup()
{
    Serial.begin(9600);
}

int Omrekening(int Kleurwaarde)
{
    if (Kleurwaarde < 85)
    {
        R = 255 - Kleurwaarde * 3;
        G = Kleurwaarde * 3;
        B = 0;
    }
    else if (Kleurwaarde < 170)
    {
        Kleurwaarde = Kleurwaarde - 85;
        R = 0;
        G = 255 - Kleurwaarde * 3;
        B = Kleurwaarde * 3;
    }
    else
    {
        Kleurwaarde = Kleurwaarde - 170;
        R = Kleurwaarde * 3;
        G = 0;
        B = 255 - Kleurwaarde * 3;
    }
}
void loop()
{
    meetwaarde = analogRead(meetpin);             // lees de meetwaarde:
    PWMwaarde = map(meetwaarde, 0, 1023, 0, 255); // Zet de meetwaarde om tussen 0 en 255
    Omrekening(PWMwaarde);
    analogWrite(redLed, R);
    analogWrite(greenLed, G);
    analogWrite(blueLed, B);

    Serial.print("PWMwaarde = ");
    Serial.print(PWMwaarde);
    Serial.print("      R = ");
    Serial.print(R);
    Serial.print("      G = ");
    Serial.print(G);
    Serial.print("      B = ");
    Serial.print(B);
    Serial.print("    \r"); //Cursor terug in het begin van dezelfde lijn zetten

    delay(100);
}
