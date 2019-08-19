#include <Arduino.h>

#define PIN_LED 3
#define TIME_DELAY_MICROSEC 1000

void setup()
{
	pinMode(PIN_LED, OUTPUT);
	digitalWrite(PIN_LED, LOW);
}

void loop()
{
	digitalWrite(PIN_LED, HIGH);
	delay(TIME_DELAY_MICROSEC);
	digitalWrite(PIN_LED, LOW);
	delay(TIME_DELAY_MICROSEC);
}