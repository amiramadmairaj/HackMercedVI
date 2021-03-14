#include <LiquidCrystal.h>
#include <Servo.h>
#include <IRremote.h>

//declaring port numbers for lcd --  RS = 7; D6 = 8; D4 = 9; D5 = 10; D6 = 11; D7 = 12;
LiquidCrystal lcd(7,8,9,10,11,12);

Servo myservo;
int angle = 0;
int min = 60000;
// Define sensor pin for remote
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
  lcd.print("WTR.IO!"); // printed on screen
  lcd.setCursor(0,1);
  myservo.attach(6); // putting the orange servo pin into port 6
Serial.begin(9600);
  irrecv.enableIRIn(); //starts reviever
 
}
void loop() {
   if(irrecv.decode(&results)){
     // code for the cases - time intervals in 1 to 7 mins for hackathon purposes -- the code would be in days when we improve it.
    switch(results.value){ 
      case 0xFF30CF: 
        // sweep from 70 to 0 degrees:
        for (angle = 70; angle >= 0; angle -= 1) {
        myservo.write(angle);
        delay(5);
        }
        delay(1000);
        // Sweep from 0 to 70 degrees:
        for (angle = 0; angle <= 70; angle += 1) {
        myservo.write(angle);
        delay(5);
        }
        delay (min);
      case 0xFF18E7:
                // sweep back from 70 to 0 degrees:
        for (angle = 70; angle >= 0; angle -= 1) {
        myservo.write(angle);
        delay(5);
        }
        delay(1000);
        // Sweep from 0 to 70 degrees:
        for (angle = 0; angle <= 70; angle += 1) {
        myservo.write(angle);
        delay (min * 2);
        }
      case 0xFF7A85:
        // sweep back from 70 to 0 degrees:
        for (angle = 70; angle >= 0; angle -= 1) {
        myservo.write(angle);
        delay(5);
        }
        delay(1000);
        // Sweep from 0 to 70 degrees:
        for (angle = 0; angle <= 70; angle += 1) {
        myservo.write(angle);
        delay (min * 3);
        }
      case 0xFF10EF:
        // sweep back from 70 to 0 degrees:
        for (angle = 70; angle >= 0; angle -= 1) {
        myservo.write(angle);
        delay(5);
        }
        delay(1000);
        // Sweep from 0 to 70 degrees:
        for (angle = 0; angle <= 70; angle += 1) {
        myservo.write(angle);
        delay (min * 4);
        }
      case 0xFF38C7:
        // sweep back from 70 to 0 degrees:
        for (angle = 70; angle >= 0; angle -= 1) {
        myservo.write(angle);
        delay(5);
        }
        delay(1000);
        // Sweep from 0 to 70 degrees:
        for (angle = 0; angle <= 70; angle += 1) {
        myservo.write(angle);
        delay (min * 5);
        }
      case 0xFF5AA5:
        // sweep back from 70 to 0 degrees:
        for (angle = 70; angle >= 0; angle -= 1) {
        myservo.write(angle);
        delay(5);
        }
        delay(1000);
        // Sweep from 0 to 70 degrees:
        for (angle = 0; angle <= 70; angle += 1) {
        myservo.write(angle);
        delay (min * 6);
        }
      case 0xFFA2BD:
        // sweep back from 70 to 0 degrees:
        for (angle = 70; angle >= 0; angle -= 1) {
        myservo.write(angle);
        delay(5);
        }
        delay(1000);
        // Sweep from 0 to 70 degrees:
        for (angle = 0; angle <= 70; angle += 1) {
        myservo.write(angle);
        delay (min * 7);
    }
   
    irrecv.resume();//next value
    delay(500);
    }
        }
}
        
