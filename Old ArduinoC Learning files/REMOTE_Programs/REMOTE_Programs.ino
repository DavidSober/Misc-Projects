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

float blue = 0;     //color counters 
float red = 0;
float green = 0;
float yellow = 0;
int totalCount = 10; //total number of times lights will blink before displaying info
int randNumber;
int desiredValue = 72; // number you want to find in the random number finder
int TimesToCheck = 100; //number of times to check if the random number = desired Value
int count = 0; //Initializes the counter for the random number finder (DONT CHANGE)

void setup() {
  pinMode(led1, OUTPUT); 
  pinMode(led2, OUTPUT);
  pinMode(led3, OUTPUT);
  pinMode(led4, OUTPUT);
  Serial.begin(9600);
  Serial.println("REMOTE CONROLLED LED PROGRAM\n-------------------------------\nINSTRUCTIONS\n-------------------------------\nRewind = Random Number finder\nFastFoward = Random Blinks\n1,2,3,4 correspond to an individual LED");
  irrecv.enableIRIn(); // Start the receiver

}

void loop()   /*----( LOOP: RUNS CONSTANTLY )----*/
{
  
  
  if (irrecv.decode(&results))  {  // have we received an IR signal?


/************************************************************************************    
 * Remote LEDs
 ************************************************************************************/
    if (results.value == 0xFF30CF) {
      
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
//************************************************************************************//
// Alternate blink code
//************************************************************************************//

if (results.value == 0xFFC23D) { //if fast foward button is pressed

while(true) {
  
  float sum = blue + green + red + yellow;
  randNumber = random(0, 100);
  
  if(randNumber <= 25) {
      
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

      ++blue;
  } else {
      if(randNumber > 25 && randNumber <= 50) {
        digitalWrite(led1, LOW);    // turn the LED off by making the voltage LOW
        digitalWrite(led2, HIGH);
        digitalWrite(led3, LOW);
        digitalWrite(led4, LOW);
        delay(onDelay);

        digitalWrite(led1, LOW);   // turn the LEDs off
        digitalWrite(led2, LOW);
        digitalWrite(led3, LOW);
        digitalWrite(led4, LOW);
        delay(offDelay);   

        ++red;
      } else {
          if(randNumber > 50 && randNumber <= 75) {
            digitalWrite(led1, LOW);    // turn the LED off by making the voltage LOW
            digitalWrite(led2, LOW);
            digitalWrite(led3, HIGH);
            digitalWrite(led4, LOW);
            delay(onDelay);

            digitalWrite(led1, LOW);   // turn the LEDs off
            digitalWrite(led2, LOW);
            digitalWrite(led3, LOW);
            digitalWrite(led4, LOW);
            delay(offDelay);   


            ++yellow;
          } else {
              if(randNumber > 75 && randNumber <= 100) {
                digitalWrite(led1, LOW);    // turn the LED off by making the voltage LOW
                digitalWrite(led2, LOW);
                digitalWrite(led3, LOW);
                digitalWrite(led4, HIGH);
                delay(onDelay);

                digitalWrite(led1, LOW);   // turn the LEDs off
                digitalWrite(led2, LOW);
                digitalWrite(led3, LOW);
                digitalWrite(led4, LOW);
                delay(offDelay);


                ++green; 
                    }
        }
      }
  }
    if (sum == totalCount) {
      
      Serial.println("\n\nColors are...");

      Serial.print("Red count: "); 
      Serial.print(red); 
      Serial.print(" %:");
      Serial.println((red/sum)*100);
      
    
      Serial.print("Blue count: "); 
      Serial.print(blue); 
      Serial.print(" %:");
      Serial.println((blue/sum)*100);

      Serial.print("Green count: "); 
      Serial.print(green); 
      Serial.print(" %:");
      Serial.println((green/sum)*100);

      Serial.print("Yellow count: "); 
      Serial.print(yellow); 
      Serial.print(" %:");
      Serial.println((yellow/sum)*100);
      Serial.print("Sum: ");
      Serial.println(sum);

      
    }
if (sum > totalCount) {

sum = 0;  //Old  mistake made here: The first "float sum" cannot be reset by including its data type here 
red = 0; //aka float sum != sum. sum affects the first "float sum" at the top of the while(true) loop
blue = 0; // Thus to reset the first "float sum" declare "sum = 0;"
green = 0;
break;
}



  } // end of infinite while loop

}
/********************************************************************************
 * Random number finder (aka: Needle in a haystack program)
 *******************************************************************************/

if (results.value == 0xFF22DD) {
      
      Serial.println("\nWill the desired number be found randomly?");

  while(true) {
    
    randNumber = random(0, 100);
  
  
    if(randNumber == desiredValue) {
        
        digitalWrite(led1, LOW);   // turn the LED on (HIGH is the voltage level)
        digitalWrite(led2, HIGH);
        digitalWrite(led3, LOW);
        digitalWrite(led4, LOW);
        delay(onDelay);
  
        Serial.print("Desired Value was found! It is: "); 
        Serial.println(desiredValue); //tells user that the desired value is found!
  
        digitalWrite(led1, LOW);   // turn the LEDs off
        digitalWrite(led2, LOW);
        digitalWrite(led3, LOW);
        digitalWrite(led4, LOW);
        delay(offDelay);
        count = count + 1;
        
    } else {
        if(randNumber != desiredValue) {
          digitalWrite(led1, LOW);    // turn the LED on by making the voltage HIGH
          digitalWrite(led2, LOW);
          digitalWrite(led3, LOW);
          digitalWrite(led4, HIGH);
          delay(100);
  
          digitalWrite(led1, LOW);   // turn the LEDs off
          digitalWrite(led2, LOW);
          digitalWrite(led3, LOW);
          digitalWrite(led4, LOW);
          delay(offDelay);  
          count = count + 1;
  }
    }

if (count > TimesToCheck) {
  Serial.println("\nRandom number finder program is finished.\nTotal Times desired number was checked: ");
  Serial.print(count-1);
  count = 0;
  break;
}


  
  } //end of infinte while loop

  
}
    
    irrecv.resume(); // receive the next value
  }  



}/* --(end main loop )-- */


