/******
 * Purpose: to check if the given year is a leap year
 * Parameters: int year       the year to test
 * 
 * Return value: int          1 if the year is a leap year, 0 otherwise
 */
int IS_LEAP_YEAR( int year);

extern int year = 2016; //enter the year you want to check the leapyearness of

extern int IS_LEAP_YEAR( int year) {

  if ( year % 4 == 0  &&  year % 100 > 0  ||  year % 400 == 0 ) {
     Serial.print("Yes: ");
     return (1);
     
      } else {
//        Serial.print("No: ");
        return (0);
        
           }
 
}





void setup() {
  // put your setup code here, to run once:
Serial.begin(9600);
Serial.println("Is the entered year a leap year?");
Serial.print(IS_LEAP_YEAR(year)); //used to test if the function works (it does) on the monitor
                                  // requires you to enter a value or uncomment in year above

}

void loop() {
  // put your main code here, to run repeatedly:

}
