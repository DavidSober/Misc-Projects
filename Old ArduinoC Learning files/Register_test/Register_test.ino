/****
 * the static storage class saves the variable counter at the end of the call of Test()
 * [counter starts at 0 and return at 1]. Thus the second time Test() is called [counter 
 * starts at 1 and returns at 2] and so on.
 * 
 * This contrasted with the undefined/auto (undefined is defaulted to auto) storage class
 * of counter in Test02(). The difference is in Test02() counter always gets reset to 0 at 
 * the begining of the function call. Thus if you run this program you will see that Test()
 * will return incrementing numbers as defined by counter because the counter was defined as static
 * and thus the compiler remmebers the value after each call to Test(). Test02() produces the 
 * same result because counter is not static and thus its value is not remembered after Test02()
 * is called
 */


int Test () {
  static int counter = 0;

  return ++counter;

  
}

int Test02 () {
  int counter = 0;

  return ++counter;

  
}

void setup() {
  // put your setup code here, to run once:
Serial.begin(9600);
Serial.println(Test());
Serial.println(Test());
Serial.println(Test());
Serial.println(Test02());
Serial.println(Test02());
Serial.println(Test02());
Serial.print("The end result, however, is that you have a variable that can maintain its value\nbetween function calls without exposing it\noutside of the function in which it is defined.");


}

void loop() {
  // put your main code here, to run repeatedly:

}
