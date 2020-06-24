#include "BluetoothSerial.h"

BluetoothSerial SerialBT;

void setup()
{
	Serial.begin(9600);
	SerialBT.begin("ESP32-13721");
}

int count = 0;
void loop()
{
	if (Serial.available()) {
		SerialBT.write(Serial.read());
	}
	if (SerialBT.available()) {
		Serial.write(SerialBT.read());
	}

	if(count > 50) {
		count = 0;
		int time = millis(); // get time
		SerialBT.print("[Bluetooth] Hello World. ");
		SerialBT.println(time);
    Serial.print("Hello World. ");
    Serial.println(time);
	}
	count ++;

	delay(20);
}
