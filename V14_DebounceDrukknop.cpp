#include <Arduino.h>

const int drukknop = 10; // constante bespaart geheugenplaats tov gewoon int (wijzigt toch niet)
const int ledPin = 13;
bool ledState = LOW;
bool buttonState;
bool lastButtonState;

void setup()
{
    pinMode(ledPin, OUTPUT);
    pinMode(drukknop, INPUT_PULLUP);
}

boolean Debounce(int pin)
{
    boolean state;
    boolean previousState;
    previousState = digitalRead(pin);              // Lees de drukknop voor de 1e keer in.
    for (int counter = 0; counter < 10; counter++) // Lees nu 10 ms lang steeds opnieuw de button in.
    {
        delay(1);                      //wacht 1 milliseconde
        state = digitalRead(drukknop); //lees de drukknop
        if (state != previousState)    // Als in die 10 ms de buttonstate verandert, gaat opnieuw 10 ms in
        {
            counter = 0;           //reset the counter
            previousState = state; //onthoud de vorige toestand.
        }
    }
    return state; // Geef nu aan het programma de status van de button terug.
}

void loop()
{
    buttonState = !Debounce(drukknop); // Vanwege de Pull-up keren we de status om.
    if (buttonState == HIGH && lastButtonState == LOW)
        ledState = !ledState;       // Button ingedrukt, draai ledState om
    lastButtonState = buttonState;  // Onthoud de vorige toestand van de button
    digitalWrite(ledPin, ledState); // Zet de led nu in ledState.
}
