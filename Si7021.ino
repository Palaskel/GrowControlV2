#include "Adafruit_Si7021.h"
#include <LiquidCrystal.h>

Adafruit_Si7021 sensor = Adafruit_Si7021();
LiquidCrystal lcd(2, 3, 4, 5, 6, 7);

void setup() {
  lcd.print("Si7021 test!");
  
  if (!sensor.begin()) {
    lcd.print("Did not find Si7021 sensor!");
    while (true);
  }
}

void loop() {
  lcd.setCursor(0, 0);
  lcd.print("Temp: "); 
  lcd.print(sensor.readTemperature(), 2);
  lcd.setCursor(0,  1);
  lcd.print("Hum: "); 
  lcd.print(sensor.readHumidity(), 2);
  delay(1000);
}

