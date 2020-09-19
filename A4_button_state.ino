  
#include <LiquidCrystal.h>

LiquidCrystal lcd(12, 11, 5, 4, 3, 2);
uint8_t heart[8] = {0x0,0xa,0x1f,0x1f,0xe,0x4,0x0};


const int  buttonPin = 8;
const int ledPin = 13;

int counter = 1; 
int buttonState = 0;
int lastButtonState = 0;


void setup() {
  lcd.clear();
  pinMode(buttonPin, INPUT);
  pinMode(ledPin, OUTPUT);
  Serial.begin(9600);
  lcd.begin(16, 2);  
  lcd.print("Initial Setup");
}
void loop() {
  buttonState = digitalRead(buttonPin);
  if (buttonState != lastButtonState) {
    if (buttonState == HIGH) {
      counter++;
      lcd.setCursor(5, 1); //go to next line
      lcd.print(counter);
      Serial.println(counter);
    }
    // Delay a little bit to avoid bouncing
    delay(100);
  }
  lastButtonState = buttonState;
  if (counter >= 3) {
    digitalWrite(ledPin, HIGH);
    counter = 0;
  }
  else if (counter == 1){
    digitalWrite(ledPin, LOW);
  }
}
