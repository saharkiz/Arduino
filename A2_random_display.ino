#include <LiquidCrystal.h>

LiquidCrystal lcd(12, 11, 5, 4, 3, 2);
uint8_t heart[8] = {0x0,0xa,0x1f,0x1f,0xe,0x4,0x0};
long randNumber;

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

  randomSeed(analogRead(0));
  delay(500);
}

void loop() {
    /* //Part 1
    lcd.clear();
    randNumber = random(300);
    lcd.print("Random Number is:  "); 
    lcd.setCursor(6,1);
    lcd.print(randNumber);  
    randNumber = random(10, 20);
    lcd.print(randNumber);
    delay(500);*/


    /*//part 2
    lcd.clear();
    lcd.print("Dice Roll is:  ");
    
    delay(1000);
    for (int i=0; i<=10; i++)
    { 
      randNumber = random(5); //0 to 5
      lcd.setCursor(6,1);
      lcd.print(randNumber+1);
      delay(300);
    }
    lcd.setCursor(0,0);
    lcd.print("Final Roll:  ");
    delay(2000);*/

    //part 3
    delay(1000);
    for (int i=0; i<=10; i++)
    { 
      
      lcd.clear();
      randNumber = random(5); //0 to 5
      lcd.print("Dice Roll is:  ");
      lcd.print(randNumber+1);
      lcd.setCursor(4,1);
      for (int j=0; j<= randNumber; j++)
      {
        lcd.write(byte(0));
      }
      delay(500);
    }
    lcd.setCursor(0,0);
    lcd.print("Final Roll:    ");
    lcd.print(randNumber+1);
    delay(2000);
  
}
