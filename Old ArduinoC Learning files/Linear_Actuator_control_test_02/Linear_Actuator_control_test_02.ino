     
int Speed = 255; //this is the PWM speed 0-255

// Bluetooth stuff ==========================================================
char junk;
String inputString="";
//===========================================================================


void setup() {
  Serial.begin(9600);
}

void loop() {

    if(Serial.available()){

          pinMode(8, OUTPUT); //Linear actuato //this reconnects the motors 
          pinMode(9, OUTPUT);
          pinMode(10, OUTPUT);


char inChar = (char)Serial.read();
inputString = inChar;

    if(inputString == "a"){
          



          digitalWrite(8,LOW);                                  // Pulls
          digitalWrite(9,HIGH);
          analogWrite(10,Speed); //this is the PWM speed 0-255
          delay(7000);

            pinMode(8, INPUT); // Here we disconnect the motors to prevent an infinte loop of the final actions 
            pinMode(9, INPUT);
            pinMode(10, INPUT);          
                    

    } else if (inputString == "b") {
      
          digitalWrite(8,HIGH);                                  // Pushes
          digitalWrite(9,LOW);
          analogWrite(10,Speed); //this is the PWM speed 0-255
          delay(7000);

            pinMode(8, INPUT); // Here we disconnect the motors to prevent an infinte loop of the final actions 
            pinMode(9, INPUT);
            pinMode(10, INPUT);          
      
    }
  }
}



          

