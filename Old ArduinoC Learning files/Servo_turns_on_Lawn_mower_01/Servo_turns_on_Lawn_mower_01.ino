#include "IRremote.h"
#include <Servo.h>

int receiver = 11; // IR reciever connection pin
int ConnectionTime = 1500; // How long the wires will be connected before disconnect in mili seconds
int MaxAngle = 30; // Max angle that the servo will make before returning to intial position


/*-----( Declare objects )-----*/
IRrecv irrecv(receiver);     // create instance of 'irrecv'
decode_results results;      // create instance of 'decode_results'

Servo myservo;  // create servo object to control a servo
// twelve servo objects can be created on most boards

int pos = 0;    // variable to store the servo position



void setup() {
  Serial.begin(9600);
  Serial.println("This is the Servo that will turn on the lawn mower remotely");
  myservo.attach(9);  // attaches the servo on pin 9 to the servo object
  irrecv.enableIRIn(); // Start the receiver
}

void loop() {
  if (irrecv.decode(&results)) {  // have we received an IR signal?
    
    if(results.value == 0xFF18E7 ){ // button 2 Turn on
      Serial.println("Button 2 is pressed");

        for (pos = 0; pos <= MaxAngle; pos += 1) { // goes from 0 degrees to 30 degrees
        // in steps of 1 degree
        myservo.write(pos);              // tell servo to go to position in variable 'pos'
          delay(15);                       // waits 15ms for the servo to reach the position
          
          if (pos == MaxAngle) {
            delay(ConnectionTime); // how long the copper connects the two wires
          }
        }
         
        for (pos = MaxAngle; pos >= 0; pos -= 1) { // goes from 30 degrees to 0 degrees
        myservo.write(pos);              // tell servo to go to position in variable 'pos'
        delay(15);                       // waits 15ms for the servo to reach the position
  }
}

  
        
        irrecv.resume(); // receive the next signal   
    }
  }



