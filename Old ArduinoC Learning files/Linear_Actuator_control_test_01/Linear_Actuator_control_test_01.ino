
int Speed = 255; //this is the PWM speed 0-255



void setup() {

  Serial.begin(9600);
  pinMode(8, OUTPUT); //Linear actuato 
  pinMode(9, OUTPUT);
  pinMode(10, OUTPUT);
         



}

void loop() {

          digitalWrite(8,LOW);                                  // Pulls
          digitalWrite(9,HIGH);
          analogWrite(10,Speed); //this is the PWM speed 0-255
          Serial.println("before delay");
          delay(6700);
          Serial.println("after delay");

          digitalWrite(8,HIGH);                                 // Pushes
          digitalWrite(9,LOW);
          analogWrite(10,Speed); //this is the PWM speed 0-255
          Serial.println("before delay");
          delay(6700);
          Serial.println("after delay");
}
