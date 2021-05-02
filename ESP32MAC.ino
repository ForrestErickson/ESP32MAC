/*ESP32MAC
 * Forrest Erickson
 * Date: 20210502
 * License / Dedication: Public domain, Free to good home.
 * Warranty: This program will kill you but is not guarenteed to do so.
 * 
 * Reads the ESP32 chip ID and puts it into the form of a MAC address
 * 
 * 
 */

const int BAUDRATE = 115200;            //Use a fast baud.

#include <esp_system.h>
uint8_t chipid[8] = {0,0,0,0,0,0,0,0};
char myMACString[18];

void setup() {
  // put your setup code here, to run once:
  Serial.begin(BAUDRATE);

   
  //Get the chip id in the MAC format
  esp_efuse_read_mac(chipid);
  snprintf(myMACString, sizeof(myMACString), "%02X%02X%02X%02X%02X%02X", chipid[0], chipid[1], chipid[2],chipid[3],chipid[4],chipid[5]);
  Serial.println("-myMACString is: " + String(myMACString));
 
}

void loop() {
  // put your main code here, to run repeatedly:

}
