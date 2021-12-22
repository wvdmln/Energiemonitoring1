#include <Arduino.h>
#include "TekstenEnBerekeningen.h" // header file met definities van variabelen en functieblokken

const int drukknop = 10; // constante bespaart geheugenplaats tov gewoon int (wijzigt toch niet)
bool button;
bool vergrendel = LOW;
int result;
float floatresult;
int getal1;
int getal2;

void setup()
{
    Serial.begin(9600);
    Serial.println("Hier ben ik !");
    pinMode(drukknop, INPUT_PULLUP);
    randomSeed(analogRead(0)); // start de toevalsgenerator
}

void loop()
{
    button = digitalRead(drukknop);
    if (button == LOW && vergrendel == LOW)
    {
        getal1 = random(1, 10); // genereer een getal tussen 1-8
        getal2 = random(1, 5);  // genereer een getal tussen 1-4

        Serial.print("getal1 = ");
        Serial.print(getal1);
        Serial.print("      getal2 = ");
        Serial.print(getal2);
        Serial.println();

        vergrendel = HIGH; // belet dat meerdere berekeningen snel na mekaar gestart worden

        for (int i = 0; i <= 3; i++)
        {

            if (i == 0)
            {
                result = add(getal1, getal2);
                Serial.print(tekstSom);
                Serial.println(result);
            }
            else if (i == 1)
            {
                result = sub(getal1, getal2);
                Serial.print(tekstVerschil);
                Serial.println(result);
            }
            else if (i == 2)
            {
                result = mul(getal1, getal2);
                Serial.print(tekstProduct);
                Serial.println(result);
            }
            else if (i == 3)
            {
                floatresult = pythagoras(getal1, getal2);
                Serial.print(tekstWortelKwadraatsom);
                Serial.println(floatresult);
            }
        }
        Serial.println();
        delay(1000);      //wacht even voordat je een nieuwe berekening kan starten
        vergrendel = LOW; // nieuwe berekening is terug mogelijk
    }
}
