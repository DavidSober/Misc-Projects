
void setup() {
 


}




void loop() {


  pinMode(22,OUTPUT); 
  pinMode(23,OUTPUT);
  pinMode(4,OUTPUT);
  
  digitalWrite(22, HIGH);
  digitalWrite(23, LOW);
  analogWrite(4,255);
  delay(25);

  pinMode(22,INPUT); 
  pinMode(23,INPUT);
  pinMode(4,INPUT);

  
  delay(0);

  pinMode(22,OUTPUT); 
  pinMode(23,OUTPUT);
  pinMode(4,OUTPUT);
  
  digitalWrite(22, LOW);
  digitalWrite(23, HIGH);
  analogWrite(4,255);
  delay(25);

  pinMode(22,INPUT); 
  pinMode(23,INPUT);
  pinMode(4,INPUT);

}
