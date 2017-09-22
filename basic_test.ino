/* Slide Pot 10K Module [S061] : http://rdiot.tistory.com/192 [RDIoT] */

#include <Wire.h> 
#include <LiquidCrystal_I2C.h>
 
LiquidCrystal_I2C lcd(0x27,20,4);  // LCD2004
int pot1Pin = A0;
int pot2Pin = A1;
 
int val;
 
void setup()
{
  lcd.init();  // initialize the lcd 
  lcd.backlight();
  lcd.print("start LCD2004");
 
  delay(1000);
  lcd.clear();
}
 
void loop()
{
  lcd.setCursor(0,0);
  lcd.print("S061:Slide Pot");
 
  lcd.setCursor(0,1);
  lcd.print("OTA=" + (String)analogRead(pot1Pin) + " -> " + (String)map(analogRead(pot1Pin), 0, 1021, 0, 100)  + "     " );
 
  lcd.setCursor(0,2);
  lcd.print("OTB=" + (String)analogRead(pot2Pin) + " -> " + (String)map(analogRead(pot2Pin), 0, 1021, 0, 100)  + "     ");
 
  delay(10);
}
