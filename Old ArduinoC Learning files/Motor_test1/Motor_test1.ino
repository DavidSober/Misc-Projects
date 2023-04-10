// blink one led and alternate

int M1 = 7;    //  Motor variables 
int led2 = 2;
int led3 = 3;
int led4 = 4;
int randNumber; 



int onDelay = 3000; //how long the light will be on
int offDelay = 1; // how long the light will be off


void setup() {
  pinMode(M1, OUTPUT); 
  pinMode(led2, OUTPUT);
  pinMode(led3, OUTPUT);
  pinMode(led4, OUTPUT);
  Serial.begin(9600);
  Serial.println("GUESS THE COLOR");

 



}


void loop() {
  
      digitalWrite(M1, HIGH);   // turn the LED on (HIGH is the voltage level)

      delay(onDelay);

  




 
}
