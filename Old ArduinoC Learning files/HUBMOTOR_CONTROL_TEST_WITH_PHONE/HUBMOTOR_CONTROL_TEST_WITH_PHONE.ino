
// Bluetooth stuff ==========================================================
char junk;
String inputString="";
//===========================================================================

int a;
int motorDirCon = 3;
int motorEnableCon = 4;
int motorSpeedCon = 8;


void setup() {
  
  Serial.begin(9600);            
  pinMode(motorDirCon,OUTPUT); //HIGH = cw, LOW = ccw
  pinMode(motorEnableCon,OUTPUT); //HIGH = stop, LOW = go
  pinMode(motorSpeedCon, OUTPUT); // PWM Signal 0-255

  digitalWrite(motorDirCon,LOW);        
  digitalWrite(motorEnableCon,HIGH);    // prevents motor from starting without commands

}

void loop() {
 
 if (Serial.available() > 0) {

      char inChar = (char)Serial.read();
      inputString = inChar;
  
  if (inputString == "a") {

    digitalWrite(motorDirCon,LOW);        // turns on motor and makes it turn ccw
    digitalWrite(motorEnableCon,LOW);
    analogWrite(motorSpeedCon,50);      // speed of motor
    Serial.println("SPEED 1 CCW");

    delay(3000);

    digitalWrite(motorDirCon,LOW);        
    digitalWrite(motorEnableCon,HIGH);    // turns motor off
    
  } else if (inputString == "b") {

    digitalWrite(motorDirCon,HIGH);        // turns on motor and makes it turn ccw
    digitalWrite(motorEnableCon,LOW);
    analogWrite(motorSpeedCon,100);      // speed of motor
    Serial.println("SPEED 2 CCW");
        
    delay(3000);

    digitalWrite(motorDirCon,LOW);        
    digitalWrite(motorEnableCon,HIGH);    // turns motor off
  
  } else if (inputString == "c") {

    digitalWrite(motorDirCon,HIGH);        // turns on motor and makes it turn ccw
    digitalWrite(motorEnableCon,LOW);
    analogWrite(motorSpeedCon,150);      // speed of motor
    Serial.println("SPEED 3 CCW");
        
    delay(3000);

    digitalWrite(motorDirCon,LOW);        
    digitalWrite(motorEnableCon,HIGH);    // turns motor off
 
 } else if (inputString == "d") {

    digitalWrite(motorDirCon,HIGH);        // turns on motor and makes it turn ccw
    digitalWrite(motorEnableCon,LOW);
    analogWrite(motorSpeedCon,200);      // speed of motor
    Serial.println("SPEED 4 CCW");
        
    delay(3000);

    digitalWrite(motorDirCon,LOW);        
    digitalWrite(motorEnableCon,HIGH);    // turns motor off
 
 } else if (inputString == "e") {

    digitalWrite(motorDirCon,LOW);        // turns on motor and makes it turn cw
    digitalWrite(motorEnableCon,LOW);
    analogWrite(motorSpeedCon,50);      // speed of motor
    Serial.println("SPEED 1 CW");
        
    delay(3000);

    digitalWrite(motorDirCon,LOW);        
    digitalWrite(motorEnableCon,HIGH);    // turns motor off  

 
  } else if (inputString == "f") {

    digitalWrite(motorDirCon,LOW);        // turns on motor and makes it turn cw
    digitalWrite(motorEnableCon,LOW);
    analogWrite(motorSpeedCon,100);      // speed of motor
    Serial.println("SPEED 2 CW");
        
    delay(3000);

    digitalWrite(motorDirCon,LOW);        
    digitalWrite(motorEnableCon,HIGH);    // turns motor off  

  } else if (inputString == "g") {

    digitalWrite(motorDirCon,LOW);        // turns on motor and makes it turn cw
    digitalWrite(motorEnableCon,LOW);
    analogWrite(motorSpeedCon,150);      // speed of motor
    Serial.println("SPEED 3 CW");
        
    delay(3000);

    digitalWrite(motorDirCon,LOW);        
    digitalWrite(motorEnableCon,HIGH);    // turns motor off  

} else if (inputString == "h") {

    digitalWrite(motorDirCon,LOW);        // turns on motor and makes it turn cw
    digitalWrite(motorEnableCon,LOW);
    analogWrite(motorSpeedCon,200);      // speed of motor
    Serial.println("SPEED 4 CW");
        
    delay(3000);

    digitalWrite(motorDirCon,LOW);        
    digitalWrite(motorEnableCon,HIGH);    // turns motor off  
}
}
}
