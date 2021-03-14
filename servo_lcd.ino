#include <LiquidCrystal.h>
#include <Servo.h>

LiquidCrystal lcd(7,8,9,10,11,12);
Servo myservo;

void write_name_lcd(int pos){
  lcd.setCursor(0,1);
  lcd.print(pos);
  lcd.print("");
}

void setup(){
  myservo.attach(6); // putting the orange servo pin into port 6
  lcd.begin(16,2);
  lcd.print("WTR.IO!");
  lcd.setCursor(0,1);
}
void loop(){
  int pos;
  int angle = 0;
long t = 1;

   for (angle = 0; angle <= 180; angle += 1) {
    myservo.write(angle);
    delay(5);
  }

  // And back from 180 to 0 degrees:
  
  for (angle = 180; angle >= 0; angle -= 1) {
    myservo.write(angle);
    delay(5);
  }
  delay(60000);
}
