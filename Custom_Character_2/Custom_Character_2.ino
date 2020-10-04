#include <LiquidCrystal_I2C.h>

LiquidCrystal_I2C lcd(0x27, 16, 2);

byte customChar[8] = {
  0b00100,
  0b00100,
  0b00100,
  0b00100,
  0b00100,
  0b00100,
  0b11111,
  0b11111,
};

byte customChar1[8] = {
  0b00100,
  0b00100,
  0b00100,
  0b00100,
  0b00100,
  0b11111,
  0b11111,
  0b11111,
};

byte customChar2[8] = {
  0b00100,
  0b00100,
  0b00100,
  0b00100,
  0b11111,
  0b11111,
  0b11111,
  0b11111,
};


void setup() 
{
  lcd.init();
  lcd.backlight();
  
  lcd.createChar(0, customChar);
  lcd.createChar(1, customChar1);
  lcd.createChar(2, customChar2);
}

void loop() 
{
 
  lcd.setCursor(2, 0);
  lcd.write((byte)0);
  
  delay(500);
  
  lcd.setCursor(2, 0);
  lcd.write((byte)1);

  delay(500);

  lcd.setCursor(2, 0);
  lcd.write((byte)2);

  delay(500);
  
}
