#include <Arduino.h>

#define LED_RED_PIN 15 
#define LED_BLUE_PIN 16

void setup()
{
  Serial.begin(115200);
  pinMode(LED_RED_PIN, OUTPUT);
  pinMode(LED_BLUE_PIN, OUTPUT);
}

void loop()
{
  digitalWrite(LED_RED_PIN, HIGH);
  digitalWrite(LED_BLUE_PIN, LOW);
  delay(1000);
  digitalWrite(LED_RED_PIN, LOW);
  digitalWrite(LED_BLUE_PIN, HIGH);
  delay(1000);
}