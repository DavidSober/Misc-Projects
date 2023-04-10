/***
 * Show how to change the rvalue of a regular variable indirectly by using a pointer
 * 
 * 
 * 
 * 
 * 
 * THE BOOK AT PAGE 154 HAS A BETTER EXAMPLE
 */
#include <stdio.h>

int X = 5; // defined a standard var
int *ptrY; // defined a pointer


void setup() {
Serial.begin(9600);
Serial.println((long) &ptrY,DEC); // shows the lvalue *ptrY which is all prtY has 

ptrY = &X; // we took the lvalue of X and placed it into the rvalue of *ptrY and get the rvalue of X
            // VIA the following path: *ptrY --> (X's lvalue) --> (X's rvalue)

Serial.println(*ptrY); // proves that *ptrY equals the rvalue of X via the direction: 
                       //*ptrY --> lvalue X --> rvalue X

*ptrY = 7; // If you wish to use a pointer to change the rvalue of the variable it points to, 
           // then you use the indirection operator. (*) 

Serial.println(*ptrY); //Both prints prove that the rvalue of X has been successfully modified from 
Serial.println(X); // 5 to 7 

}

void loop() {

}
