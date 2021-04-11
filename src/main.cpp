#include <Arduino.h>
#include <LiquidCrystal.h>
#include <time.h>
uint8_t countSec = 0;
uint8_t countMin = 0;
const short BUTTON_PIN = 2;
LiquidCrystal lcd(8,7,6,5,4,3);
void setup()
{
    lcd.begin(16,2);
    Serial.begin(9600);
    pinMode(BUTTON_PIN,INPUT);
    for(short i=1;i<4;i++){
        lcd.clear();
        lcd.print("Starting");
        for (size_t j = 0; j < i; j++)
        {
            lcd.print(".");
        }
        
        delay(500);
    }
}
void resetCounter(){
    for(short i=1;i<4;i++){
        lcd.clear();
        lcd.print("Resetting");
        for (size_t j = 0; j < i; j++)
        {
            lcd.print(".");
        }
        
        delay(500);
    }
    countSec = 0;
    countMin = 0;
}
void loop()
{
    lcd.clear();
    countSec++;
    if(digitalRead(BUTTON_PIN) == HIGH){
        resetCounter();
    }
    if(countSec >= 60){
        countSec = 0;
        countMin++;
    }
    if(countMin >= 60){
        countMin = 0;
        countSec = 0;
    }

    lcd.clear();
    lcd.print(countMin < 10 ? "0" : "");
    lcd.print(countMin);
    lcd.print(":");
    lcd.print(countSec < 10 ? "0" : "");
    lcd.print(countSec);
    delay(1000); 
}
