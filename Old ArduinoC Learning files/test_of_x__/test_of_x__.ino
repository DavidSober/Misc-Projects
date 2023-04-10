int x = 0;
int y = 0;


void setup() {
  // put your setup code here, to run once:
Serial.begin(9600);



}

void loop() {
  // put your main code here, to run repeatedly:

if (x <= 4) {


  Serial.print(x);
  ++x;

}

//if (y <= 4) {
//  
//  Serial.println(y);
//  y++;
//
//}

}
