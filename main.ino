/*
 * =====================================================================================
 *
 *       Filename:  main.ino
 *
 *    Description:  Sketch for LED Control using Android Application
 *
 *        Version:  1.0
 *        Created:  Saturday 3 March 2012 22:36:21  IST
 *       Revision:  none
 *       Compiler:  arduino
 *
 *         Author:  Ashish Ranjan (Jalan), hi.ashish26@gmail.com
 *        Company:  IIT, Madras
 *
 * =====================================================================================
 */

 
/*
(a) Serial.begin(long): Sets the data rate in bits per second (baud) for serial data transmission.
                        Returns:
                            Nothing.
(b) Serial.available(): Gets the number of bytes (characters) available for reading from the serial port. 
                        This is data that's already arrived and stored in the serial receive buffer (which holds 128 bytes).
                        available() inherits from the Stream utility class. 
                        Returns:
                            The number of bytes available to read - int.
(c) Serial.read()     : Reads incoming serial data. 
                        read() inherits from the Stream utility class. 
                        Returns:
                            The first byte of incoming serial data available (or -1 if no data is available) - int.
*/

int ledPin = 13;
int byteInput = 0;

void setup() {
  pinMode(ledPin, OUTPUT);
  Serial.begin(57600);      // Opens serial port, sets data rate to 57600 bps
}

void loop() {
  while (Serial.available() == 0);
  
  byteInput = Serial.read();
  int ledLevel = map(byteInput, 0, 100, 0, 255);
  analogWrite(ledPin, ledLevel);
  
  Serial.flush();
}
