// 
int a = 2;
int b = 2;

void kkhalf () {
  a = a/2;
}

int kkk(int b) {
  b = b/2;
  
}

void setup() {

Serial.begin(9600);


Serial.println(a);
Serial.println(b);

kkhalf();
kkk(b);

Serial.println(a);
Serial.println(b);
}


void loop() {


}
