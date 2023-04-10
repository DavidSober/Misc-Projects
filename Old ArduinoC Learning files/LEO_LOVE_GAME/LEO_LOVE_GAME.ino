/****
 * Function that lets user respond to a question with yes or no
 * Parameters:
 * int a                represents the integer translation of the character input by the user
 *                      via the Serial.read function
 * Return value         none
 */


int a;

void setup() {
  Serial.begin(9600); 
  Serial.println("Do you love Leo???");
  Serial.println("a = yes \nb = no");
}

void loop() {


  if (Serial.available() > 0) {

    a = Serial.read(); 
      if (a == 97) {
        Serial.println("You are MLG");
      } else {
        if (a == 98) {
          Serial.println("YOU ARE NOT MLG");
        } else {
          Serial.println("LOL JK");
        }
    }


    
  }
}


