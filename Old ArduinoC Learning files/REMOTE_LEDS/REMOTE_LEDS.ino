/***
 *Function that blinks different lights based on the buttons pressed on the IR remote
 *No Parameters and No return values 
 *
 *The following lists the remotes and their ID's:
 ***********************************************
 *case 0xFFA25D: Serial.println("POWER"); break;
  case 0xFFE21D: Serial.println("FUNC/STOP"); break;
  case 0xFF629D: Serial.println("VOL+"); break;
  case 0xFF22DD: Serial.println("FAST BACK");    break;
  case 0xFF02FD: Serial.println("PAUSE");    break;
  case 0xFFC23D: Serial.println("FAST FORWARD");   break;
  case 0xFFE01F: Serial.println("DOWN");    break;
  case 0xFFA857: Serial.println("VOL-");    break;
  case 0xFF906F: Serial.println("UP");    break;
  case 0xFF9867: Serial.println("EQ");    break;
  case 0xFFB04F: Serial.println("ST/REPT");    break;
  case 0xFF6897: Serial.println("0");    break;
  case 0xFF30CF: Serial.println("1");    break;
  case 0xFF18E7: Serial.println("2");    break;
  case 0xFF7A85: Serial.println("3");    break;
  case 0xFF10EF: Serial.println("4");    break;
  case 0xFF38C7: Serial.println("5");    break;
  case 0xFF5AA5: Serial.println("6");    break;
  case 0xFF42BD: Serial.println("7");    break;
  case 0xFF4AB5: Serial.println("8");    break;
  case 0xFF52AD: Serial.println("9");    break;
  case 0xFFFFFFFF: Serial.println(" REPEAT");break;  
 */


#include "IRremote.h"

int led1 = 7; //led# = pin#
int led2 = 2;
int led3 = 3;
int led4 = 4;
int receiver = 11; // Signal Pin of IR receiver to Arduino Digital Pin 11 

/*-----( Declare objects )-----*/
IRrecv irrecv(receiver);     // create instance of 'irrecv'
decode_results results;      // create instance of 'decode_results'

int onDelay = 250; //how long the light will be on
int offDelay = .001; // how long the light will be off



void setup() {
  pinMode(led1, OUTPUT); 
  pinMode(led2, OUTPUT);
  pinMode(led3, OUTPUT);
  pinMode(led4, OUTPUT);
  Serial.begin(9600);
  Serial.println("REMOTE CONROLLED LED PROGRAM");
  irrecv.enableIRIn(); // Start the receiver

}

void loop()   /*----( LOOP: RUNS CONSTANTLY )----*/
{
  if (irrecv.decode(&results)) // have we received an IR signal?
    {
    if (results.value == 0xFF30CF) {
      Serial.print("HELLO");
      digitalWrite(led1, HIGH);   // turn the LED on (HIGH is the voltage level)
      digitalWrite(led2, LOW);
      digitalWrite(led3, LOW);
      digitalWrite(led4, LOW);
      delay(onDelay);

      digitalWrite(led1, LOW);   // turn the LEDs off
      digitalWrite(led2, LOW);
      digitalWrite(led3, LOW);
      digitalWrite(led4, LOW);
      delay(offDelay);
      

    } else {
      if (results.value == 0xFF18E7) {
        digitalWrite(led1, LOW);   // turn the LED on (HIGH is the voltage level)
        digitalWrite(led2, HIGH);
        digitalWrite(led3, LOW);
        digitalWrite(led4, LOW);
        delay(onDelay);
  
        digitalWrite(led1, LOW);   // turn the LEDs off
        digitalWrite(led2, LOW);
        digitalWrite(led3, LOW);
        digitalWrite(led4, LOW);
        delay(offDelay);
      } else {
        if (results.value == 0xFF7A85) {
          digitalWrite(led1, LOW);   // turn the LED on (HIGH is the voltage level)
          digitalWrite(led2, LOW);
          digitalWrite(led3, HIGH);
          digitalWrite(led4, LOW);
          delay(onDelay);
    
          digitalWrite(led1, LOW);   // turn the LEDs off
          digitalWrite(led2, LOW);
          digitalWrite(led3, LOW);
          digitalWrite(led4, LOW);
          delay(offDelay);
        } else {
          if (results.value == 0xFF10EF) {
            digitalWrite(led1, LOW);   // turn the LED on (HIGH is the voltage level)
            digitalWrite(led2, LOW);
            digitalWrite(led3, LOW);
            digitalWrite(led4, HIGH);
            delay(onDelay);
      
            digitalWrite(led1, LOW);   // turn the LEDs off
            digitalWrite(led2, LOW);
            digitalWrite(led3, LOW);
            digitalWrite(led4, LOW);
            delay(offDelay); 
          }
        }
      }
    }
    irrecv.resume(); // receive the next value
    }  




}/* --(end main loop )-- */


