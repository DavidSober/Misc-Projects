// blink one led and alternate

int led1 = 7; //global vars which are the leds
int led2 = 2;
int led3 = 3;
int led4 = 4;
int randNumber; 

float blue = 0;     //color counters 
float red = 0;
float green = 0;
float yellow = 0;

int onDelay = 10; //how long the light will be on
int offDelay = 1; // how long the light will be off
int totalCount = 10; //total number of times lights blinked before displaying info


void setup() {
  pinMode(led1, OUTPUT); 
  pinMode(led2, OUTPUT);
  pinMode(led3, OUTPUT);
  pinMode(led4, OUTPUT);
  Serial.begin(9600);
  Serial.println("GUESS THE COLOR");

}


void loop() {
  
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
      
      Serial.println("Colors are...");

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
           

      
    }

 
}
