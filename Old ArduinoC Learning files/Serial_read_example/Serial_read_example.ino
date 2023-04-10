int incomingByte;  // for incoming serial data

void setup() {
  Serial.begin(9600); // opens serial port, sets data rate to 9600 bps
}

void loop() {

  // send data only when you receive data:
  if (Serial.available() > 0) {
    // read the incoming byte:
    incomingByte = Serial.read(); // "Serial.read();" takes the char input that the user sends to the
                                  // arduino via the monitor and returns an integer form of that char
                                  

    // say what you got:
    Serial.print("I received: ");
    Serial.println(incomingByte, BIN); // the format does not matter IN THIS CASE 
                                       // This code was copied from arduino reference 
                                       // they used BIN to show that you can output data
                                       // in any format you want including BIN
  }
}
