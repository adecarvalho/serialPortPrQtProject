#include "mbed.h"

// prototypes
void setup();
void loop();
void flash();

// obj
DigitalOut ledInternal(D13);
RawSerial pc(SERIAL_TX, SERIAL_RX);

//***************************
void flash() {
  for (int i = 0; i < 3; i++) {
    ledInternal = 1;
    wait_us(100000);
    ledInternal = 0;
    wait_us(100000);
  }
}

//****************************
void setup() { ledInternal = 0; }
//****************************
void loop() {
  flash();
  //
  thread_sleep_for(2000);
}

//****************************
int main() {
  setup();

  while (true) {
    loop();
  }
}
