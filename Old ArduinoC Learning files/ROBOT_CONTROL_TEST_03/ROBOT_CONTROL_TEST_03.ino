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

  
  pinMode(2, OUTPUT); //motor A
  pinMode(3, OUTPUT);
  pinMode(4, OUTPUT);

  pinMode(5, OUTPUT); //motor B
  pinMode(6, OUTPUT);
  pinMode(7, OUTPUT);

  pinMode(8, OUTPUT); //motor C
  pinMode(9, OUTPUT);
  pinMode(10, OUTPUT);

  pinMode(11, OUTPUT); //motor D
  pinMode(12, OUTPUT);
  pinMode(13, OUTPUT);

  
  Serial.begin(9600);
  Serial.println("REMOTE CONTROL ROBOT TEST 03"); 
  irrecv.enableIRIn(); // Start the receiver

}/*--(end setup )---*/


void loop()  { /*----( LOOP: RUNS CONSTANTLY )----*/

  if (irrecv.decode(&results) == 0) {
      Serial.println("NOPE");
      
          digitalWrite(5,LOW);
          digitalWrite(7,LOW);
          analogWrite(6,10); //this is the PWM speed 0-255
          
          digitalWrite(3,LOW);
          digitalWrite(4,LOW);
          analogWrite(5,10); //this is the PWM speed 0-255

    
  
//    irrecv.resume(); // receive the next value
  }

  


  
  
  if (irrecv.decode(&results)) {  // have we received an IR signal?

    if(results.value != 0xFFFFFFFF ){
       LastCode = results.value;
    
    } else {
      if(results.value == 0xFFFFFFFF && LastCode == 0xFF4AB5) { // button 8

          digitalWrite(5,HIGH);
          digitalWrite(7,LOW);
          analogWrite(6,Speed); //this is the PWM speed 0-255
          
          digitalWrite(2,HIGH);
          digitalWrite(4,LOW);
          analogWrite(3,Speed); //this is the PWM speed 0-255
          delay(Delay);
          Serial.println("test01");

      } else {
        if(results.value == 0xFFFFFFFF && LastCode == 0xFF18E7) { // button 2
            digitalWrite(5,LOW);
            digitalWrite(7,HIGH);
            analogWrite(6,Speed);
           
            digitalWrite(2,LOW);
            digitalWrite(4,HIGH);
            analogWrite(3,Speed);
            delay(Delay);
            Serial.println("test02");
      } else {
        if(results.value == 0xFFFFFFFF && LastCode == 0xFF5AA5) { // button 6
            
            digitalWrite(5,HIGH);
            digitalWrite(7,LOW);
            analogWrite(6,Speed);
           
            digitalWrite(2,LOW);
            digitalWrite(4,HIGH);
            analogWrite(3,Speed);
            delay(Delay);
            Serial.println("test03");
          
        } else {
          if(results.value == 0xFFFFFFFF && LastCode == 0xFF10EF) { // button 4
            digitalWrite(5,LOW);
            digitalWrite(7,HIGH);
            analogWrite(6,Speed);
           
            digitalWrite(2,HIGH);
            digitalWrite(4,LOW);
            analogWrite(3,Speed);
            delay(Delay);
            Serial.println("test04");
            
          }
        }
      }
      
      
      }
    }
    
    
    
    
    
 




  
  
    irrecv.resume(); // receive the next value
}
/* --(end main loop )-- */
}

