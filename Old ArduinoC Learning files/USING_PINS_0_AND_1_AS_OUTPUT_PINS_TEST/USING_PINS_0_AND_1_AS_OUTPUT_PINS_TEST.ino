
// BOTH PINS 0 AND 1 WORK AS OUTPUT PINS BUT THEY BOTH FIRE BREIFLY WHEN UPLOADING A SKETCH FOR 
// THE FIRST TIME


void setup() {
  // put your setup code here, to run once:


  pinMode(0,OUTPUT);
  pinMode(1,OUTPUT);

}

void loop() {
  // put your main code here, to run repeatedly:

  digitalWrite(0,LOW);
  digitalWrite(1,HIGH);

}
