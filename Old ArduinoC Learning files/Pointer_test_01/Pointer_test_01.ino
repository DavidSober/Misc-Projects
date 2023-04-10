//Checks if pointers can be related in relational expressions correctly aka is 1>2 if we are using pointers pointing to two different vars: Spoiler it works
int *ptr1;
int *ptr2;
int var1 = 1;
int var2 = 2;
int x;

void setup() {
  // put your setup code here, to run once:


Serial.begin(9600);

ptr1 = &var1;
ptr2 = &var2;

pinMode(0,OUTPUT);

if(*ptr1 > *ptr2) {
  Serial.println("IT DOES NOT WORK");
  
} else {
  if(*ptr1 < *ptr2) {
    Serial.println("IT WORKS");
    
  }
}

randomSeed(analogRead(0));
x = random(0,100);
}

void loop() {
  // put your main code here, to run repeatedly:

Serial.println(x);
  

}
