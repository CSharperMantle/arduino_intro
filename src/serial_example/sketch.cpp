#include <Arduino.h>

void setup()
{
    Serial.begin(9600);
}

void loop()
{
    Serial.println("This is a string.");
    Serial.println("The next one is an int:");
    Serial.println(2019);
    Serial.println("This string has a tab \t character.");
    Serial.print("A string...");
    Serial.println("This string will come out directly after the last one!");
    Serial.println();
    Serial.println("That's it. Go and continue reading.");
    delay(10000); // wait for 10 seconds.
}