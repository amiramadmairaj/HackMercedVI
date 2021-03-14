#include <Servo.h>
#include <IRremote.h>

//new servo object:
Servo myservo;

// Define the servo pin:
#define servoPin 6

// Create a variable to store the servo position:
int angle = 0;
int min = 60000;
// Define sensor pin
const int RECV_PIN = 4;
 
// Define IR Receiver and Results Objects
IRrecv irrecv(RECV_PIN);
decode_results results;


void setup() {
  Serial.begin(9600);
  irrecv.enableIRIn(); //starts reviever
  // Attach the Servo variable to a pin:
  myservo.attach(servoPin);
  Serial.println("Beginning.");
}

void loop() {
   if(irrecv.decode(&results)){
    switch(results.value){
      case 0xFF30CF:
        // And back from 90 to 0 degrees:
        for (angle = 70; angle >= 0; angle -= 1) {
        myservo.write(angle);
        delay(5);
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
        
