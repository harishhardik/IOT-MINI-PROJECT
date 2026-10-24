#include <Wire.h>
#include <LiquidCrystal_I2C.h>

LiquidCrystal_I2C lcd(0x3F, 16, 2);

const int mqPin = A0;
const int greenLED = 7;
const int redLED = 8;
const int MIN_VALUE = 0;
const int MAX_VALUE = 500; // Adjust after testing

void setup() 
{
    Serial.begin(9600);
    pinMode(greenLED, OUTPUT);
    pinMode(redLED, OUTPUT);
    lcd.init();
    lcd.backlight();
    lcd.clear();
    Serial.println("================================");
    Serial.println(" GAS LEVEL MONITORING SYSTEM");
    Serial.println("================================");
}

void loop() 
{
    int gasValue = analogRead(mqPin);

    // Normalize raw reading to a 0-100% display scale
    int gasPercent = map(gasValue, MIN_VALUE, MAX_VALUE, 0, 100);

    gasPercent = constrain(gasPercent, 0, 100);

    Serial.print("Raw Sensor Value: ");
    Serial.print(gasValue);
    Serial.print(" | Gas Level: ");
    Serial.print(gasPercent);
    Serial.println("%");

    if (gasPercent < 30) 
    {
        Serial.println("Status: LOW - NORMAL");
        digitalWrite(greenLED, HIGH);
        digitalWrite(redLED, LOW);
        lcd.setCursor(0, 1);
        lcd.print("Level: LOW ");
    } 
    else if (gasPercent < 60) 
    {
        Serial.println("Status: MODERATE - CAUTION");
        digitalWrite(greenLED, HIGH);
        digitalWrite(redLED, LOW);
        lcd.setCursor(0, 1);
        lcd.print("Level: MODERATE ");
    } 
    else 
    {
        Serial.println("Status: HIGH - ALERT!");
        digitalWrite(greenLED, LOW);
        digitalWrite(redLED, HIGH);
        lcd.setCursor(0, 1);
        lcd.print("GAS LEVEL HIGH ");
    }
    
    Serial.println("--------------------------------");
    lcd.setCursor(0, 0);
    lcd.print("Gas Level: ");
    lcd.print(gasPercent);
    lcd.print("% ");
    delay(1000);
}
