#include <LiquidCrystal_I2C.h>

LiquidCrystal_I2C lcd(0x27, 16 ,2);


byte bar_gauge_empty[8] = {
  0b11111,
  0b00000,
  0b00000,
  0b00000,
  0b00000,
  0b00000,
  0b00000,
  0b11111,
};

byte bar_gauge_empty1[8] = {
  0b11100,
  0b00010,
  0b00001,
  0b00001,
  0b00001,
  0b00001,
  0b00010,
  0b11100,
};

byte bar_gauge_empty2[8] = {
  0b00111,
  0b01000,
  0b10000,
  0b10000,
  0b10000,
  0b10000,
  0b01000,
  0b00111,
};

byte bar_gauge3[8] = {
  0b00111,
  0b01000,
  0b10011,
  0b10111,
  0b10111,
  0b10011,
  0b01000,
  0b00111,
};

byte bar_gauge4[8] = {
  0b11111,
  0b00000,
  0b11111,
  0b11111,
  0b11111,
  0b11111,
  0b00000,
  0b11111,
};

byte bar_gauge5[8] = {
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

  lcd.createChar(0, bar_gauge_empty);
  lcd.createChar(1, bar_gauge_empty1);
  lcd.createChar(2, bar_gauge_empty2);
  
  lcd.createChar(3, bar_gauge3);
  lcd.createChar(4, bar_gauge4);
  lcd.createChar(5, bar_gauge5);
  
  
 
  lcd.setCursor(0, 1);
  lcd.write((byte)3);

  lcd.setCursor(1, 1);
  lcd.write((byte)4);

  lcd.setCursor(2, 1);
  lcd.write((byte)4);

  lcd.setCursor(3, 1);
  lcd.write((byte)4);

  lcd.setCursor(4, 1);
  lcd.write((byte)0);

  lcd.setCursor(5, 1);
  lcd.write((byte)0);

  lcd.setCursor(6, 1);
  lcd.write((byte)0);

  lcd.setCursor(7, 1);
  lcd.write((byte)1);


  lcd.setCursor(0, 0);
  lcd.print("Moisture 50%");

  lcd.setCursor(9, 1);
  lcd.print("level=2");
};

void loop() {
  
}
