int myF(int a) {
  int temp = a;
  return a; // <--- this would fix the function so that it returns the int that you put in 
  // myF's argument. However in it's curent state, it would spit out a junk int (for some reason)
  // it spits out 0 always 
}

void setup() {
Serial.begin(9600);



Serial.println(myF(2));
}

void loop() {
  // put your main code here, to run repeatedly:

}
