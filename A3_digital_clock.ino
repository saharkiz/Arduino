#include <LiquidCrystal.h>

LiquidCrystal lcd(12, 11, 5, 4, 3, 2);
uint8_t heart[8] = {0x0,0xa,0x1f,0x1f,0xe,0x4,0x0};

int hour = 8;
int minute = 46;
int second = 50;
String day = "PM";

void setup() {
  Serial.begin(9600);
  lcd.clear();
  lcd.createChar(0, heart);
  lcd.begin(16, 2);  
  lcd.write(byte(0));
  lcd.print("   Welcome    "); //1st line
  lcd.write(byte(0));
  lcd.setCursor(0, 1); //go to next line
  lcd.print(" Initial  Setup");
  delay(3000);
}

void loop() {

    lcd.clear();
    lcd.setCursor(2,0);
    lcd.print("Manila Time");
    lcd.setCursor(2,1);
    if (hour < 10) {
      lcd.print(0);
    }
    lcd.print(hour);
    lcd.print(":");
    if (minute < 10) {
      lcd.print(0);
    }
    lcd.print(minute);
    lcd.print(":");
    if (second < 10) {
      lcd.print(0);
    }
    lcd.print(second);

    lcd.print(" "+ day);
    delay(1000);
    second = second + 1;
    if (second == 60)
    {
      second = 0;
      minute = minute + 1;
    }
    if (minute == 60)
    {
      minute = 0;
      hour = hour + 1;
    }
    if (hour == 13){
      if (day == "AM")
      {
        day = "PM";
      }
      else
      {
        day = "AM";
      }
      hour = 1;
    }
}
