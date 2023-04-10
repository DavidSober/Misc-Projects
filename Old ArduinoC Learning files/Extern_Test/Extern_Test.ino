//int x = 4;

int HALLL(int y);
extern int y;   //We are telling the compiler that we are defining a variable y externally in another tab in the future (in this case y is defined in tab 02)



void setup() {
  // put your setup code here, to run once:
Serial.begin(9600);
Serial.println(HALLL(y));

}

void loop() {
  // put your main code here, to run repeatedly:

}
