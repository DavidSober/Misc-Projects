#include "IRremote.h"


int receiver = 11;
unsigned long LastCode;

int Speed = 255;
int Delay = 85;

/*-----( Declare objects )-----*/
IRrecv irrecv(receiver);     // create instance of 'irrecv'
decode_results results;      // create instance of 'decode_results'


void setup()   /*----( SETUP: RUNS ONCE )----*/
{

  
  pinMode(1, OUTPUT); //motor A
  pinMode(2, OUTPUT);
  pinMode(3, OUTPUT);

  pinMode(4, OUTPUT); //motor B
  pinMode(5, OUTPUT);
  pinMode(6, OUTPUT);

  pinMode(7, OUTPUT); //motor C
  pinMode(8, OUTPUT);
  pinMode(9, OUTPUT);

  pinMode(10, OUTPUT); //motor D
  pinMode(12, OUTPUT);
  pinMode(13, OUTPUT);

  
  Serial.begin(9600);
  Serial.println("REMOTE CONTROL ROBOT TEST 03"); 
  irrecv.enableIRIn(); // Start the receiver

}/*--(end setup )---*/


void loop()  { /*----( LOOP: RUNS CONSTANTLY )----*/

  if (irrecv.decode(&results) == 0) { // if no signal is recieved shut down all motors 
      Serial.println("NOPE");
      
          digitalWrite(1,LOW);
          digitalWrite(2,LOW);
          analogWrite(3,0); //this is the PWM speed 0-255
          
          digitalWrite(4,LOW);
          digitalWrite(5,LOW);
          analogWrite(6,0); //this is the PWM speed 0-255

          digitalWrite(7,LOW);
          digitalWrite(8,LOW);
          analogWrite(9,0);

          digitalWrite(13,LOW);
          digitalWrite(12,LOW);
          analogWrite(10,0);

          
  }
   
  
  if (irrecv.decode(&results)) {  // have we received an IR signal?

    if(results.value != 0xFFFFFFFF ){
       LastCode = results.value;
    
    } else {
      if(results.value == 0xFFFFFFFF && LastCode == 0xFF4AB5) { // button 8 Backup

          digitalWrite(1,HIGH);
          digitalWrite(2,LOW);
          analogWrite(3,Speed); //this is the PWM speed 0-255
          
          digitalWrite(4,HIGH);
          digitalWrite(5,LOW);
          analogWrite(6,Speed); //this is the PWM speed 0-255
          delay(Delay);
          Serial.println("test01");

      } else {
        if(results.value == 0xFFFFFFFF && LastCode == 0xFF18E7) { // button 2 Go Foward
            digitalWrite(1,LOW);
            digitalWrite(2,HIGH);
            analogWrite(3,Speed);
           
            digitalWrite(4,LOW);
            digitalWrite(5,HIGH);
            analogWrite(6,Speed);
            delay(Delay);
            Serial.println("test02");
      
      } else {
        if(results.value == 0xFFFFFFFF && LastCode == 0xFF5AA5) { // button 6 Rotate CW
            
            digitalWrite(1,HIGH);
            digitalWrite(2,LOW);
            analogWrite(3,Speed);
           
            digitalWrite(4,LOW);
            digitalWrite(5,HIGH);
            analogWrite(6,Speed);
            delay(Delay);
            Serial.println("test03");
          
        } else {
          if(results.value == 0xFFFFFFFF && LastCode == 0xFF10EF) { // button 4 Rotate CCW
            digitalWrite(1,LOW);
            digitalWrite(2,HIGH);
            analogWrite(3,Speed);
           
            digitalWrite(4,HIGH);
            digitalWrite(5,LOW);
            analogWrite(6,Speed);
            delay(Delay);
            Serial.println("test04");
            
          } else {
            if(results.value == 0xFFFFFFFF && LastCode == 0xFF906F) { // button UP Raise arm
              digitalWrite(7,LOW);
              digitalWrite(8,HIGH);
              analogWrite(9,Speed);
              delay(Delay);
              Serial.println("test05");
            
          } else {
            if(results.value == 0xFFFFFFFF && LastCode == 0xFFB04F) { // button ST/REPT Lower arm
              digitalWrite(7,HIGH);
              digitalWrite(8,LOW);
              analogWrite(9,Speed);
              delay(Delay);
              Serial.println("test06");
      
           } else {
            if(results.value == 0xFFFFFFFF && LastCode == 0xFFE01F) { // button DOWN Open Claw
                digitalWrite(13,HIGH);
                digitalWrite(12,LOW);
                analogWrite(10,Speed);
                delay(Delay);
                Serial.println("test07");
           
           } else {
            if(results.value == 0xFFFFFFFF && LastCode == 0xFF6897) { // button 0 Close Claw
                              
                digitalWrite(13,LOW);
                digitalWrite(12,HIGH);
                analogWrite(10,Speed);
                delay(Delay);
                Serial.println("test08");
           
             
            }
           }
           }
          }
          }
        }
      }
      
      
      }
    }
    
  
    irrecv.resume(); // receive the next value
}
/* --(end main loop )-- */
}


