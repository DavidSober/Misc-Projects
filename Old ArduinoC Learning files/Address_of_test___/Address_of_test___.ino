int x = 69;


void setup() {
  // put your setup code here, to run once:
Serial.begin(9600);
Serial.print((int) &x); // (dayatype) &var will show the lvalue of the var
}

void loop() {
  // put your main code here, to run repeatedly:

}
