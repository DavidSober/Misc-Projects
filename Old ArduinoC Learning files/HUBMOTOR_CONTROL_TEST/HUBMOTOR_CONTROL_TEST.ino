
int a;
int motorDirCon = 3;
int motorEnableCon = 4;



void setup() {
  
  Serial.begin(9600);            
  pinMode(motorDirCon,OUTPUT); //HIGH = cw, LOW = ccw
  pinMode(motorEnableCon,OUTPUT); //HIGH = stop, LOW = go

  digitalWrite(motorDirCon,LOW);        
  digitalWrite(motorEnableCon,HIGH);    // prevents motor from starting without commands

}

void loop() {
 
 if (Serial.available() > 0) {

  a = Serial.read();
  
  if (a == 97) {

    digitalWrite(motorDirCon,LOW);        // turns on motor and makes it turn ccw
    digitalWrite(motorEnableCon,LOW);
    Serial.println("letter a was entered");

    delay(3000);

    digitalWrite(motorDirCon,LOW);        
    digitalWrite(motorEnableCon,HIGH);    // turns motor off
    
  } else if (a == 98) {

    digitalWrite(motorDirCon,HIGH);        // turns on motor and makes it turn cw
    digitalWrite(motorEnableCon,LOW);
    Serial.println("letter b was entered");
        
    delay(3000);

    digitalWrite(motorDirCon,LOW);        
    digitalWrite(motorEnableCon,HIGH);    // turns motor off
  
  }
 
 }

 
}
