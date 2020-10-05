#include <LiquidCrystal_I2C.h>

LiquidCrystal_I2C lcd(0x27, 16 ,2);

byte water_level[8] = {
  0b00100,
  0b00100,
  0b00100,
  0b00100,
  0b00100,
  0b00100,
  0b00100,
  0b11111,
};

byte water_level1[8] = {
  0b00100,
  0b00100,
  0b00100,
  0b00100,
  0b00100,
  0b00100,
  0b11111,
  0b11111,
};

byte water_level2[8] = {
  0b00100,
  0b00100,
  0b00100,
  0b00100,
  0b00100,
  0b11111,
  0b11111,
  0b11111,
};

byte water_level3[8] = {
  0b00100,
  0b00100,
  0b00100,
  0b00100,
  0b11111,
  0b11111,
  0b11111,
  0b11111,
};

byte bar_gauge4[8] = {
  0b00111,
  0b01000,
  0b10011,
  0b10111,
  0b10111,
  0b10011,
  0b01000,
  0b00111,
};

byte bar_gauge5[8] = {
  0b11111,
  0b00000,
  0b11111,
  0b11111,
  0b11111,
  0b11111,
  0b00000,
  0b11111,
};

byte bar_gauge6[8] = {
  0b11100,
  0b00010,
  0b11001,
  0b11101,
  0b11101,
  0b11001,
  0b00010,
  0b11100,
};



void setup() {
  lcd.init();
  lcd.backlight();

  lcd.createChar(0, water_level);
  lcd.createChar(1, water_level1);
  lcd.createChar(2, water_level2);
  lcd.createChar(3, water_level3);
  lcd.createChar(4, bar_gauge4);
  lcd.createChar(5, bar_gauge5);
  lcd.createChar(6, bar_gauge6);
  
  
 
  lcd.setCursor(0, 1);
  lcd.write((byte)4);

  lcd.setCursor(1, 1);
  lcd.write((byte)5);

  lcd.setCursor(2, 1);
  lcd.write((byte)5);

  lcd.setCursor(3, 1);
  lcd.write((byte)5);

  lcd.setCursor(4, 1);
  lcd.write((byte)5);

  lcd.setCursor(5, 1);
  lcd.write((byte)5);

  lcd.setCursor(6, 1);
  lcd.write((byte)5);

  lcd.setCursor(7, 1);
  lcd.write((byte)5);

  lcd.setCursor(8, 1);
  lcd.write((byte)6);


  lcd.setCursor(0, 0);
  lcd.print("Moisture 100%");
};

void loop() {
  lcd.setCursor(15, 1);
  lcd.write((byte)0);
  
  delay(700);
  
  lcd.setCursor(15, 1);
  lcd.write((byte)1);

  delay(700);

  lcd.setCursor(15, 1);
  lcd.write((byte)2);

  delay(700);

  lcd.setCursor(15, 1);
  lcd.write((byte)3);

  delay(700);
 
}
