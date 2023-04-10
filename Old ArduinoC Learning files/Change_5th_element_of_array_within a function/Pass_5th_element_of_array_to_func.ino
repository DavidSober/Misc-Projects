/****
 * GOAL: Modify the 5th element of an array within a function by using a pointer
 * aka pass by reference 
 */



int Value[] = {0, 1, 2, 3, 4, 5};
int *ptr;
int func(int Array[],int *p) {      // you use 4 because of the N-1 rule for array elements

   p = &Array[4]; //sets the pointer to point towards the lvalue of the 5th element in Array                              
  *p = 69;                
  
}




void setup() {
  Serial.begin(9600);
  Serial.println("value of 5th element in Value array before function");
  Serial.println(Value[4]);
  func(Value,ptr);

  Serial.println("value of 5th element in Value array AFTER function");
  Serial.println(Value[4]);
  
}

void loop() {
}
