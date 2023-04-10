
// Bluetooth stuff ==========================================================
char junk;
String inputString="";
//===========================================================================

int Speed = 200;
void setup()                    
{

 Serial.begin(9600);            // set the baud rate to 9600, same should be of your Serial Monitor

}

void loop()
{
    
  if(Serial.available()){ // if bluetooth is talking to arudino


          char inChar = (char)Serial.read();
          inputString = inChar;
          
          
          pinMode(8, OUTPUT); // Linear actuator this reconnects the motors 
          pinMode(9, OUTPUT);
          pinMode(6, OUTPUT);

  }
    if (inputString == "a"){
          Serial.println("LOL");
          digitalWrite(8,LOW);                                  // Pulls
          digitalWrite(9,HIGH);
          analogWrite(6,Speed); //this is the PWM speed 0-255
          delay(7000);

            pinMode(8, INPUT); // Here we disconnect the motors to prevent an infinte loop of the final actions 
            pinMode(9, INPUT);
            pinMode(6, INPUT);          
                
        
      

 
    
      }
     else if (inputString == "c") {
      
          digitalWrite(8,HIGH);                                  // Pushes
          digitalWrite(9,LOW);
          analogWrite(6,Speed); //this is the PWM speed 0-255
          delay(7000);

            pinMode(8, INPUT); // Here we disconnect the motors to prevent an infinte loop of the final actions 
            pinMode(9, INPUT);
            pinMode(6, INPUT);     
    
} 

}


