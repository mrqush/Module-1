#include <Arduino.h>

#define BLUE_LED_PIN 15
#define RED_LED_PIN 16
#define INNER_BUTTON_PIN 0
#define BUTTON_PIN 17

void setup() {
  Serial.begin(115200);
  pinMode(RED_LED_PIN, OUTPUT);
  pinMode(BLUE_LED_PIN, OUTPUT);
  pinMode(INNER_BUTTON_PIN, INPUT_PULLUP);
  pinMode(BUTTON_PIN, INPUT);
}

void blink(int pin1, int pin2, int ms) {
  digitalWrite(pin1, HIGH);
  digitalWrite(pin2, LOW);
  delay(ms);
  
  digitalWrite(pin1, LOW);
  digitalWrite(pin2, HIGH);
  delay(ms);
}

void loop() {
  int buttonState = digitalRead(BUTTON_PIN);
  int innerButtonState = digitalRead(INNER_BUTTON_PIN);

  if(buttonState == HIGH && innerButtonState == LOW) {
    Serial.println("Both buttons pressed - special mode activated");
    blink(RED_LED_PIN, BLUE_LED_PIN, 200);
    blink(RED_LED_PIN, BLUE_LED_PIN, 1000);
    blink(RED_LED_PIN, BLUE_LED_PIN, 200);
  } else if(buttonState == HIGH) {
    blink(RED_LED_PIN, BLUE_LED_PIN, 200);
    Serial.println("Outer button pressed - fast mode activated");
  } else if(innerButtonState == LOW) {
    blink(RED_LED_PIN, BLUE_LED_PIN, 800);
    Serial.println("Inner button pressed - slow mode activated");
  }

  delay(20);  
}