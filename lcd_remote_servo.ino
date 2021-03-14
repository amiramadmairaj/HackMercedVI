#include <LiquidCrystal.h>
#include <Servo.h>
#include <IRremote.h>

LiquidCrystal lcd(7,8,9,10,11,12);
Servo myservo;
int angle = 0;
int min = 60000;
// Define sensor pin
const int RECV_PIN = 4;
 
// Define IR Receiver and Results Objects
IRrecv irrecv(RECV_PIN);
decode_results results;


void write_name_lcd(int pos){
  lcd.setCursor(0,1);
  lcd.print(pos);
  lcd.print("");
}

void setup(){
  lcd.begin(16,2);
  lcd.print("WTR.IO!");
  lcd.setCursor(0,1);
  myservo.attach(6); // putting the orange servo pin into port 6
Serial.begin(9600);
  irrecv.enableIRIn(); //starts reviever
 
}
void loop() {
   if(irrecv.decode(&results)){
    switch(results.value){
      case 0xFF30CF:
        // And back from 90 to 0 degrees:
        for (angle = 70; angle >= 0; angle -= 1) {
        myservo.write(angle);
        delay(1000);
        }
        delay(1000);
        // Sweep from 0 to 90 degrees:
        for (angle = 0; angle <= 70; angle += 1) {
        myservo.write(angle);
        delay(5);
        }
        delay (min);
      case 0xFF18E7:
                // And back from 90 to 0 degrees:
        for (angle = 70; angle >= 0; angle -= 1) {
        myservo.write(angle);
        delay(5);
        }
        delay(1000);
        // Sweep from 0 to 90 degrees:
        for (angle = 0; angle <= 70; angle += 1) {
        myservo.write(angle);
        delay (min * 2);
        }
      case 0xFF7A85:
        // And back from 90 to 0 degrees:
        for (angle = 70; angle >= 0; angle -= 1) {
        myservo.write(angle);
        delay(5);
        }
        delay(1000);
        // Sweep from 0 to 90 degrees:
        for (angle = 0; angle <= 70; angle += 1) {
        myservo.write(angle);
        delay (min * 3);
        }
      case 0xFF10EF:
        // And back from 90 to 0 degrees:
        for (angle = 70; angle >= 0; angle -= 1) {
        myservo.write(angle);
        delay(5);
        }
        delay(1000);
        // Sweep from 0 to 90 degrees:
        for (angle = 0; angle <= 70; angle += 1) {
        myservo.write(angle);
        delay (min * 4);
        }
      case 0xFF38C7:
        // And back from 90 to 0 degrees:
        for (angle = 70; angle >= 0; angle -= 1) {
        myservo.write(angle);
        delay(5);
        }
        delay(1000);
        // Sweep from 0 to 90 degrees:
        for (angle = 0; angle <= 70; angle += 1) {
        myservo.write(angle);
        delay (min * 5);
        }
      case 0xFF5AA5:
        // And back from 90 to 0 degrees:
        for (angle = 70; angle >= 0; angle -= 1) {
        myservo.write(angle);
        delay(5);
        }
        delay(1000);
        // Sweep from 0 to 90 degrees:
        for (angle = 0; angle <= 70; angle += 1) {
        myservo.write(angle);
        delay (min * 6);
        }
      case 0xFFA2BD:
        // And back from 90 to 0 degrees:
        for (angle = 70; angle >= 0; angle -= 1) {
        myservo.write(angle);
        delay(5);
        }
        delay(1000);
        // Sweep from 0 to 90 degrees:
        for (angle = 0; angle <= 70; angle += 1) {
        myservo.write(angle);
        delay (min * 7);
    }
   
    irrecv.resume();//next value
    delay(500);
    }
        }
}
        
