
// BLUETOOTH VARIABLES ======================================================
char junk;
String inputString="";
//===========================================================================

// H-BRIDGE VARIABLES =======================================================
int IN1 = 32;
int IN2 = 33;
int ENA = 255; // PWM Speed for the linear actuator
//===========================================================================

// MOTOR PIN LAYOUT =========================================================

// Motor 1 Pins on Mega //
int M1_FR = 22;
int M1_EN = 23;
int M1_SV = 3; //PWM SIGNAL

// Motor 2 Pins on Mega//
int M2_FR = 26;
int M2_EN = 27;
int M2_SV = 4; //PWM SIGNAL

// Motor 3 Pins on Mega//
int M3_FR = 40;
int M3_EN = 41;
int M3_SV = 5; //PWM SIGNAL

// Motor 4 Pins on Mega//
int M4_FR = 46;
int M4_EN = 47;
int M4_SV = 6; //PWM SIGNAL 

//===========================================================================

//Motor Power for rotating cw
int M_CW_POWER = 100;

void setup() {
  
  Serial.begin(9600);  
  
// MOTOR INITIALIZATION =====================================================
            
// Motor 1 Initialization //
  pinMode(M1_FR,OUTPUT); //HIGH = cw, LOW = ccw
  pinMode(M1_EN,OUTPUT); //HIGH = stop, LOW = go
  pinMode(M1_SV, OUTPUT); // PWM Signal 0-255

// Motor 2 Initialization //
  pinMode(M2_FR,OUTPUT); //HIGH = cw, LOW = ccw
  pinMode(M2_EN,OUTPUT); //HIGH = stop, LOW = go
  pinMode(M2_SV, OUTPUT); // PWM Signal 0-255

// Motor 3 Initialization //
  pinMode(M3_FR,OUTPUT); //HIGH = cw, LOW = ccw
  pinMode(M3_EN,OUTPUT); //HIGH = stop, LOW = go
  pinMode(M3_SV, OUTPUT); // PWM Signal 0-255

// Motor 4 Initialization //
  pinMode(M4_FR,OUTPUT); //HIGH = cw, LOW = ccw
  pinMode(M4_EN,OUTPUT); //HIGH = stop, LOW = go
  pinMode(M4_SV, OUTPUT); // PWM Signal 0-255

//===========================================================================

// MOTOR UNWANTED START PREVENTION ==========================================

// Motor 1 
  digitalWrite(M1_FR,LOW);        
  digitalWrite(M1_EN,HIGH);    // prevents motor from starting without commands

// Motor 2 
  digitalWrite(M2_FR,LOW);        
  digitalWrite(M2_EN,HIGH);    // prevents motor from starting without commands

// Motor 3 
  digitalWrite(M3_FR,LOW);        
  digitalWrite(M3_EN,HIGH);    // prevents motor from starting without commands

// Motor 4 
  digitalWrite(M4_FR,LOW);        
  digitalWrite(M4_EN,HIGH);    // prevents motor from starting without commands

//===========================================================================

}


void loop() {
 
 if (Serial.available() > 0) {

      char inChar = (char)Serial.read();
      inputString = inChar;

    
    if (inputString == "a") {

    digitalWrite(M1_FR,LOW);        // turns on motor and makes it turn ccw
    digitalWrite(M1_EN,LOW);
    analogWrite(M1_SV,50);      // speed of motor

    digitalWrite(M2_FR,HIGH);        // turns on motor and makes it turn ccw
    digitalWrite(M2_EN,LOW);
    analogWrite(M2_SV,50);      // speed of motor

    digitalWrite(M3_FR,LOW);        // turns on motor and makes it turn cw
    digitalWrite(M3_EN,LOW);
    analogWrite(M3_SV,50);      // speed of motor

    digitalWrite(M4_FR,LOW);        // turns on motor and makes it turn cw
    digitalWrite(M4_EN,LOW);
    analogWrite(M4_SV,50);      // speed of motor
    
    Serial.println("Forward at low speed");

    delay(500);
    
    // Turns off motors
    digitalWrite(M1_FR,LOW);        
    digitalWrite(M1_EN,HIGH);    // turns motor off

    digitalWrite(M2_FR,LOW);        
    digitalWrite(M2_EN,HIGH);    // turns motor off

    digitalWrite(M3_FR,LOW);        
    digitalWrite(M3_EN,HIGH);    // turns motor off

    digitalWrite(M4_FR,LOW);        
    digitalWrite(M4_EN,HIGH);    // turns motor off
    
  } else if (inputString == "b") {  // rotate mower cw


    digitalWrite(M1_FR,LOW);        // turns on motor and makes it turn ccw
    digitalWrite(M1_EN,LOW);
    analogWrite(M1_SV,M_CW_POWER);      // speed of motor

    digitalWrite(M2_FR,HIGH);        // turns on motor and makes it turn ccw
    digitalWrite(M2_EN,LOW);
    analogWrite(M2_SV,M_CW_POWER);      // speed of motor

    digitalWrite(M3_FR,HIGH);        // turns on motor and makes it turn ccw
    digitalWrite(M3_EN,LOW);
    analogWrite(M3_SV,M_CW_POWER);      // speed of motor

    digitalWrite(M4_FR,HIGH);        // turns on motor and makes it turn ccw
    digitalWrite(M4_EN,LOW);
    analogWrite(M4_SV,M_CW_POWER);      // speed of motor
    
    Serial.println("Forward at low speed");

    delay(500);
    
    // Turns off motors
    digitalWrite(M1_FR,LOW);        
    digitalWrite(M1_EN,HIGH);    // turns motor off

    digitalWrite(M2_FR,LOW);        
    digitalWrite(M2_EN,HIGH);    // turns motor off

    digitalWrite(M3_FR,LOW);        
    digitalWrite(M3_EN,HIGH);    // turns motor off

    digitalWrite(M4_FR,LOW);        
    digitalWrite(M4_EN,HIGH);    // turns motor off
    
  }
  
 
}
}
