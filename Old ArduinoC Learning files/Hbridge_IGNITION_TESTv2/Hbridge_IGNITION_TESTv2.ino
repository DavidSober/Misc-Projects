

int Speed = 200;

void setup() {
  // put your setup code here, to run once:

          Serial.begin(9600);
          pinMode(8, OUTPUT); // Linear actuator this reconnects the motors 
          pinMode(9, OUTPUT);
          pinMode(10, OUTPUT);


          for(;;) {
          
          Serial.println("BEFORE DELAY");
          
          digitalWrite(8,HIGH);                                  // Pulls
          digitalWrite(9,LOW);
          analogWrite(10,255); //this is the PWM speed 0-255
          delay(7000);

          Serial.println("AFTER DELAY");
          pinMode(8, INPUT); // Here we disconnect the motors to prevent an infinte loop of the final actions 
          pinMode(9, INPUT);
          pinMode(10, INPUT);  
          break;
          }


}

void loop() {
  
}
