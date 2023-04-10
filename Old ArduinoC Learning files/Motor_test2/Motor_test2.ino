
int Speed = 255;
int Delay = 3000;

void setup() {
pinMode(7, OUTPUT); //motor A
pinMode(8, OUTPUT);
pinMode(9, OUTPUT);


pinMode(3, OUTPUT); //motor B
pinMode(4, OUTPUT);
pinMode(5, OUTPUT);



}

void loop() {
  //Motor A is below
  
  digitalWrite(8,HIGH);
  digitalWrite(7,LOW);
  analogWrite(9,Speed); //this is the PWM speed 0-255
  
  digitalWrite(3,HIGH);
  digitalWrite(4,LOW);
  analogWrite(5,Speed); //this is the PWM speed 0-255
  delay(Delay);

    
  
  digitalWrite(8,LOW);
  digitalWrite(7,HIGH);
  analogWrite(9,Speed);
 
  digitalWrite(3,LOW);
  digitalWrite(4,HIGH);
  analogWrite(5,Speed);
  delay(Delay);
  

}
