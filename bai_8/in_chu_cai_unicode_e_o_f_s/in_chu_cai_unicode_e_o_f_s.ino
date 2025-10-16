#include<LiquidCrystal.h>
LiquidCrystal lcd(7,6,5,4,3,2);
unsigned long pre_time = 0;
int x = 0;
int y = 0;
int btn_e = 11;
int btn_o = 10;
int btn_f = 8;
int btn_s = 9;
int pre_btn_e = LOW;
int pre_btn_o = LOW;
int pre_btn_s = LOW;
int pre_btn_f = LOW;
char pre_char = '\0';
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
byte ES[8] ={
B00010,
B00100,
B11111,
B10000,
B11111,
B10000,
B11111,
B00000
};
byte EF[8] ={
B01000,
B00100,
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
byte OF[8] ={
B01000,
B00100,
B01110,
B10001,
B10001,
B10001,
B01110,
B00000
};
byte OS[8] ={
B00010,
B00100,
B01110,
B10001,
B10001,
B10001,
B01110,
B00000
};
void setup() {
  lcd.begin(16,2);
  lcd.createChar(0,EE);
  lcd.createChar(1,ES);
  lcd.createChar(2,EF);
  lcd.createChar(3,OO);
  lcd.createChar(4,OF);
  lcd.createChar(5,OS);
  pinMode(btn_e,INPUT);
  pinMode(btn_o,INPUT);
  pinMode(btn_f,INPUT);
  pinMode(btn_s,INPUT);
}

void loop() {
  
  int cur_btn_e = digitalRead(btn_e);
  int cur_btn_o = digitalRead(btn_o);
  int cur_btn_s = digitalRead(btn_s);
  int cur_btn_f = digitalRead(btn_f);
  if(cur_btn_e == LOW && pre_btn_e == HIGH)
  {
    if(pre_char == 'e')
    {
      x--;
      lcd.setCursor(x,y);
      lcd.print("");
      lcd.write(byte(0));
      pre_char = '\0';
    }
    else
    {
      lcd.setCursor(x,y);
      lcd.print("E");
      pre_char = 'e';
    }
    x++;
  }

  if(cur_btn_o == LOW && pre_btn_o == HIGH)
  {
    if(pre_char == 'o')
    {
      x--;
      lcd.setCursor(x,y);
      lcd.print("");
      lcd.write(byte(3));
      pre_char = '\0';
    }
    else
    {
      lcd.setCursor(x,y);
      lcd.print("O");
      pre_char = 'o';
    }
    x++;
  }

  if(cur_btn_s == LOW && pre_btn_s == HIGH)
  {
    if(pre_char == 'o')
    {
      x--;
      lcd.setCursor(x,y);
      lcd.print("");
      lcd.write(byte(5));
    }
    else if(pre_char == 'e')
    {
      x--;
      lcd.setCursor(x,y);
      lcd.print("");
      lcd.write(byte(1));
    }
    else
    {
      lcd.setCursor(x,y);
      lcd.print("S");
    }
    pre_char = '\0';
    x++;
  }

   if(cur_btn_f == LOW && pre_btn_f == HIGH)
  {
    if(pre_char == 'o')
    {
      x--;
      lcd.setCursor(x,y);
      lcd.print("");
      lcd.write(byte(4));
    }
    else if(pre_char == 'e')
    {
      x--;
      lcd.setCursor(x,y);
      lcd.print("");
      lcd.write(byte(2));
    }
    else
    {
      lcd.setCursor(x,y);
      lcd.print("F");
    }
    pre_char = '\0';
    x++;
  }

  if(x > 15){
    x = 0;
    y++;
  }
  if(y > 1){
    x = 0;
    y = 0;
    lcd.clear();
  }
  pre_btn_e = cur_btn_e;
  pre_btn_o = cur_btn_o;
  pre_btn_s = cur_btn_s;
   pre_btn_f = cur_btn_f;
}