#include <Arduino.h>

#define ADC_PIN 15
#define LED1_PIN 16
#define LED2_PIN 17
#define LED3_PIN 18

#define THRESHOLD_LOW  1300
#define THRESHOLD_HIGH 2600
#define HYSTERESIS 100

void setup()
{
  Serial.begin(115200);
  pinMode(LED1_PIN, OUTPUT);
  pinMode(LED2_PIN, OUTPUT);
  pinMode(LED3_PIN, OUTPUT);
}

//Всего 3 уровня освещенности, 1 - низкий, 2 - средний, 3 - высокий
int currentLevel = 1;

void loop()
{
  int analogValue = analogRead(ADC_PIN);

  Serial.printf("ADC value %d, Level: %d\n", analogValue, currentLevel);

  //Переход на уровень выше -> используется верхний порог
  if (currentLevel == 1 && analogValue > THRESHOLD_LOW + HYSTERESIS) {
    currentLevel = 2;
  } else if (currentLevel == 2 && analogValue > THRESHOLD_HIGH + HYSTERESIS) {
    currentLevel = 3;
  } 
  //Переход на уровень ниже -> используется нижний порог
  else if (currentLevel == 3 && analogValue < THRESHOLD_HIGH - HYSTERESIS) {
    currentLevel = 2;
  } else if (currentLevel == 2 && analogValue < THRESHOLD_LOW - HYSTERESIS) {
    currentLevel = 1;
  }

  //Управление светодиодами
  digitalWrite(LED1_PIN, currentLevel >= 1 ? HIGH : LOW);
  digitalWrite(LED2_PIN, currentLevel >= 2 ? HIGH : LOW);
  digitalWrite(LED3_PIN, currentLevel >= 3 ? HIGH : LOW);

  delay(200);
}