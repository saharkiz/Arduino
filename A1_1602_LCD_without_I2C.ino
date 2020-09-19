#include <LiquidCrystal.h>

LiquidCrystal lcd(12, 11, 5, 4, 3, 2);
uint8_t heart[8] = {0x0,0xa,0x1f,0x1f,0xe,0x4,0x0};

void setup() {
  Serial.begin(9600);
  lcd.clear();
  lcd.createChar(0, heart);
  lcd.begin(16, 2);  
  lcd.write(byte(0));
  lcd.print("   Welcome    "); //1st line
  lcd.write(byte(0));
  lcd.setCursor(0, 1); //go to next line
  lcd.print("Initial Setup");
  delay(3000);

}

void loop() {
    lcd.clear();
    lcd.write(byte(0));
    lcd.print("   Running    "); //1st line
    lcd.write(byte(0));
    if (Serial.available()) 
    {
      delay(100);
      lcd.clear();
      while (Serial.available() > 0) {
          lcd.write(Serial.read());
      }
    }
    else
    { 
        lcd.setCursor(0, 1); //go to next linebegins with 0):
        lcd.print("");
        lcd.print("Waiting :  ");
        lcd.print(millis() / 1000);
        delay(200);
    }
  
}
