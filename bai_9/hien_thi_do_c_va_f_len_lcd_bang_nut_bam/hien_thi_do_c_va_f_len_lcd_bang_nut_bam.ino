#include<LiquidCrystal.h>
LiquidCrystal lcd(7,6,5,4,3,2);
unsigned long pre_time = 0;
int btn_f = 8;
int btn_c = 9;
int lm_35 = A0;
int pre_btn_c = LOW;
int pre_btn_f = LOW;
int choose = 0;
void setup() {
  lcd.begin(16,2);
  pinMode(lm_35,INPUT);
  pinMode(btn_f,INPUT);
  pinMode(btn_c,INPUT);
}

void loop() {
  unsigned long cur_time = millis();
  //Xử lý khi cur_time reset về 0
  if(cur_time == 0)
  {
    pre_time = 0;
  }
  float reading = analogRead(lm_35);
  float voltage = reading * 5.0 / 1024.0;
  float temp_c = voltage * 100;
  float temp_f = (temp_c * 1.8) + 32;
  int cur_btn_c = digitalRead(btn_c);
  int cur_btn_f = digitalRead(btn_f);
  lcd.setCursor(0,0);
  if(cur_btn_c == HIGH && pre_btn_c == LOW)
  {
    choose = 0;
  }
  if(cur_btn_f == HIGH && pre_btn_f == LOW)
  {
    choose = 1;
  }
  if(cur_time - pre_time >= 500)
  {
    if(choose == 0)
    {
      lcd.clear();
      lcd.print("Temp: ");
      lcd.print(temp_c);
      lcd.print(" C");
    }
    else
    {
      lcd.clear();
      lcd.print("Temp: ");
      lcd.print(temp_f);
      lcd.print(" F");
    }
    pre_time = cur_time;
  }
  pre_btn_f = cur_btn_f;
  pre_btn_c = cur_btn_c;
}