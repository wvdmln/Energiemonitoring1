#include <Arduino.h>
#include <Bounce2.h>

Bounce DebounceDrukknop = Bounce(); //maak een instantie van het Bounce object

const int drukknop = 10; // constante bespaart geheugenplaats tov gewoon int (wijzigt toch niet)
const int ledPin = 13;
bool ledState = LOW;
bool buttonState;
bool lastButtonState;

void setup()
{
    pinMode(ledPin, OUTPUT);
    pinMode(drukknop, INPUT_PULLUP);
    DebounceDrukknop.attach(drukknop); //Koppel de pin aan de instantie
    DebounceDrukknop.interval(5);      //Set interval
}

void loop()
{
    DebounceDrukknop.update();              //update de instantie
    buttonState = !DebounceDrukknop.read(); //lees de updated instantie
    if (buttonState == HIGH && lastButtonState == LOW)
        ledState = !ledState;       // Button ingedrukt, draai ledState om
    lastButtonState = buttonState;  // Onthoud de vorige toestand van de button
    digitalWrite(ledPin, ledState); // Zet de led nu in ledState.
}
