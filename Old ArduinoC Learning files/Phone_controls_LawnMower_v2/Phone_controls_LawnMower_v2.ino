#include <Servo.h>

int Speed = 255; //this is the PWM speed 0-255 for the Linear actuator


// Servo stuff =============================================================
int ConnectionTime = 1500; // How long the wires will be connected before disconnect in mili seconds
int MaxAngle = 30; // Max angle that the servo will make before returning to intial position
int pos = 0;    // variable to store the servo position

Servo myservo;  // create servo object to control a servo
// twelve servo objects can be created on most boards
//===========================================================================

// Bluetooth stuff ==========================================================
char junk;
String inputString="";
//===========================================================================


void setup()                    
{

 Serial.begin(9600);            // set the baud rate to 9600, same should be of your Serial Monitor

}

void loop()
{
    
  if(Serial.available()){ // if bluetooth is talking to arudino


          char inChar = (char)Serial.read();
          inputString = inChar;
          
          myservo.attach(6); // this is reattaching the servo to the appropiate pin for running the following code
                             // btw the servo attatchment changes at the end of this if statement (that's why this line exists to allow for future inputs to the servo)

          pinMode(8, OUTPUT); // Linear actuator this reconnects the motors 
          pinMode(9, OUTPUT);
          pinMode(10, OUTPUT);

    
    if (inputString == "a"){
    
          digitalWrite(8,LOW);                                  // Pulls
          digitalWrite(9,HIGH);
          analogWrite(10,Speed); //this is the PWM speed 0-255
          delay(7000);

            pinMode(8, INPUT); // Here we disconnect the motors to prevent an infinte loop of the final actions 
            pinMode(9, INPUT);
            pinMode(10, INPUT);          
                
        
      

  } else if (inputString == "b") {
          
      // below is the code that makes the servo turn on the lawn mower
      
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

        if (pos == 0) {                 // this is to prevent endless spining 
          myservo.attach(3);
          
      
        }
    
      }
    } else if (inputString == "c") {
      
          digitalWrite(8,HIGH);                                  // Pushes
          digitalWrite(9,LOW);
          analogWrite(10,Speed); //this is the PWM speed 0-255
          delay(7000);

            pinMode(8, INPUT); // Here we disconnect the motors to prevent an infinte loop of the final actions 
            pinMode(9, INPUT);
            pinMode(10, INPUT);     
    
} 

}
}

