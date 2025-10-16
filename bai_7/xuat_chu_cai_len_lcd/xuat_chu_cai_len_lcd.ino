#include<LiquidCrystal.h>
LiquidCrystal lcd(7,6,5,4,3,2);
unsigned long pre_time = 0;
byte AW[8] ={
B10001,
B00100,
B00000,
B00100,
B01010,
B10101,
B10001,
B10001
};

byte AA[8] ={
B00100,
B10001,
B00100,
B01010,
B10001,
B10101,
B10001,
B10001
};

byte DD[8] ={
B01110,
B01001,
B01001,
B11101,
B01001,
B01001,
B01110,
B00000
};
byte EE[8] ={
B00100,
B01010,
B11111,
B10000,
B11111,
B10000,
B11111,
B00000
};
byte OO[8] ={
B00100,
B10001,
B01110,
B10001,
B10001,
B10001,
B01110,
B00000
};
byte OW[8] ={
B00011,
B00001,
B01110,
B10001,
B10001,
B10001,
B01110,
B00000
};
byte UW[8] ={
B00011,
B00001,
B10010,
B10010,
B10010,
B10010,
B01100,
B00000
};
void setup() {
  lcd.begin(16,2);
  lcd.createChar(0,AW);
  lcd.createChar(1,AA);
  lcd.createChar(2,DD);
  lcd.createChar(3,EE);
  lcd.createChar(4,OO);
  lcd.createChar(5,OW);
  lcd.createChar(6,UW);
}

void loop() {
  unsigned long cur_time = millis();
  if(cur_time == 0)
  {
    pre_time = 0;
  }
    if(cur_time - pre_time >= 500)
    {
       lcd.clear();
      for(int i = 0; i < 7; i++)
      {
        lcd.setCursor(i,0);
        lcd.write(byte(i));
      }
      pre_time = cur_time;
    }
}