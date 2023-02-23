#include "mbed.h"

// prototypes
void setup();
void loop();

// obj
DigitalOut ledInternal(D13);

//****************************
void setup() { ledInternal = 0; }
//****************************
void loop() {
  ledInternal = 1;
  thread_sleep_for(100);
  ledInternal = 0;
  thread_sleep_for(800);
}

//****************************
int main() {
  setup();

  while (true) {
    loop();
  }
}
