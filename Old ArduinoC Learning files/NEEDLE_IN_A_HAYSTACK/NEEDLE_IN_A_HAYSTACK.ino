// blink one led and alternate

int led1 = 7; //global vars which are the leds
int led2 = 2;
int led3 = 3;
int led4 = 4;
int randNumber; 
int desiredValue = 8;

int onDelay = 2000; //how long the light will be on
int offDelay = 50; // how long the light will be off

void setup() {
  pinMode(led1, OUTPUT); 
  pinMode(led2, OUTPUT);
  pinMode(led3, OUTPUT);
  pinMode(led4, OUTPUT);
  Serial.begin(9600);
  Serial.println("Will the desired number be found randomly?");

}


void loop() {
  randNumber = random(0, 100);


  if(randNumber == desiredValue) {
      
      digitalWrite(led1, HIGH);   // turn the LED on (HIGH is the voltage level)
      digitalWrite(led2, LOW);
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

      
  } else {
      if(randNumber != desiredValue) {
        digitalWrite(led1, LOW);    // turn the LED off by making the voltage LOW
        digitalWrite(led2, HIGH);
        digitalWrite(led3, LOW);
        digitalWrite(led4, LOW);
        delay(100);

        digitalWrite(led1, LOW);   // turn the LEDs off
        digitalWrite(led2, LOW);
        digitalWrite(led3, LOW);
        digitalWrite(led4, LOW);
        delay(offDelay);  
}
  }



  
}
