

/* Welcome to the ECU Reader project. This sketch uses the Canbus library.
It requires the CAN-bus shield for the Arduino. This shield contains the MCP2515 CAN controller and the MCP2551 CAN-bus driver.
A connector for an EM406 GPS receiver and an uSDcard holder with 3v level convertor for use in data logging applications.
The output data can be displayed on a serial LCD.



SK Pang Electronics www.skpang.co.uk
v4.0 04-03-12 Updated for Arduino 1.0

*/
#include <Canbus.h>

char buffer[512];  //Data will be temporarily stored to this buffer before being written out

void setup() {
    Serial.begin(9600);
    Serial.println("ECU Reader");

    if(Canbus.init(CANSPEED_500))  { /* Initialise MCP2515 CAN controller at the specified speed */

        Serial.print("CAN Init ok");
    } else {
        Serial.print("Can't init CAN");
    } /* For debug use */


    delay(1000);

}


void loop() {

    if(Canbus.ecu_req(ENGINE_RPM,buffer) == 1) {
        Serial.println(buffer);
    }
    if(Canbus.ecu_req(VEHICLE_SPEED,buffer) == 1) {
        Serial.println(buffer);
    }
    if(Canbus.ecu_req(ENGINE_COOLANT_TEMP,buffer) == 1) {
        Serial.println(buffer);
    }

    if(Canbus.ecu_req(THROTTLE,buffer) == 1) {
        Serial.println(buffer);
    }
    delay(100);

}


