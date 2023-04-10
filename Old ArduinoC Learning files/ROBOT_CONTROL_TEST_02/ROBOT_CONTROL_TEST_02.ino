#include "IRremote.h"


int receiver = 11;
unsigned long LastCode;

int Speed = 255;
int Delay = 0;

/*-----( Declare objects )-----*/
IRrecv irrecv(receiver);     // create instance of 'irrecv'
decode_results results;      // create instance of 'decode_results'


void setup()   /*----( SETUP: RUNS ONCE )----*/
{
  pinMode(7, OUTPUT); //motor A
  pinMode(8, OUTPUT);
  pinMode(9, OUTPUT);
  
  
  pinMode(3, OUTPUT); //motor B
  pinMode(4, OUTPUT);
  pinMode(5, OUTPUT);

  
  Serial.begin(9600);
  Serial.println("REMOTE CONTROL ROBOT TEST 02"); 
  irrecv.enableIRIn(); // Start the receiver

}/*--(end setup )---*/


void loop()  { /*----( LOOP: RUNS CONSTANTLY )----*/
  
  
  if (irrecv.decode(&results)) {  // have we received an IR signal?

    if(results.value != 0xFFFFFFFF ){
       LastCode = results.value;
    
    } else {
      if(results.value == 0xFFFFFFFF && LastCode == 0xFF4AB5) {

          digitalWrite(8,HIGH);
          digitalWrite(7,LOW);
          analogWrite(9,Speed); //this is the PWM speed 0-255
          
          digitalWrite(3,HIGH);
          digitalWrite(4,LOW);
          analogWrite(5,Speed); //this is the PWM speed 0-255
          delay(Delay);
          Serial.println("test01");

      } else {
        if(results.value == 0xFFFFFFFF && LastCode == 0xFF18E7) {
            digitalWrite(8,LOW);
            digitalWrite(7,HIGH);
            analogWrite(9,Speed);
           
            digitalWrite(3,LOW);
            digitalWrite(4,HIGH);
            analogWrite(5,Speed);
            delay(Delay);
            Serial.println("test02");
      } else {
        if(results.value == 0xFFFFFFFF && LastCode == 0xFF5AA5) {
            
            digitalWrite(8,HIGH);
            digitalWrite(7,LOW);
            analogWrite(9,Speed);
           
            digitalWrite(3,LOW);
            digitalWrite(4,HIGH);
            analogWrite(5,Speed);
            delay(Delay);
            Serial.println("test03");
          
        } else {
          if(results.value == 0xFFFFFFFF && LastCode == 0xFF10EF) {
            digitalWrite(8,LOW);
            digitalWrite(7,HIGH);
            analogWrite(9,Speed);
           
            digitalWrite(3,HIGH);
            digitalWrite(4,LOW);
            analogWrite(5,Speed);
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

