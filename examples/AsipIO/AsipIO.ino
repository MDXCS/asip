/* AsipIO.ino */

#include <asip.h>       // the base class definitions
#include <asipIO.h>     // the core I/O class definition

// the list of services, here there is only the core service to read and write pins
asipService services[] = {&asipIO}; // the core class for pin level I/O
                         
void setup() {
  Serial.begin(57600);  
  asip.begin(&Serial, asipServiceCount(services), services, "AsipIO"); 
  asip.reserve(SERIAL_RX_PIN);  // reserve pins used by the serial port 
  asip.reserve(SERIAL_TX_PIN);  // these defines are in asip/boards.h 
  asipIO.begin(); // start the IO service
  Serial.println("!AsipIO is ready");
}

void loop() 
{
  asip.service();
}
