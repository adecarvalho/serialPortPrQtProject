#include "mbed.h"

// prototypes
void setup();
void loop();
void flash();
void serialHandler();
void sendMessage();

// obj
DigitalOut ledInternal(D13);
DigitalOut ledExternal(D9);
RawSerial pc(SERIAL_TX, SERIAL_RX);

//***************************
void serialHandler() {
  //
  if (pc.readable()) {
    char val = pc.getc();

    switch (val) {
    case 'l':
      ledExternal = 1;
      break;
    //
    case 'k':
      ledExternal = 0;
      break;
    //
    default:
      break;
    }

    // pc.putc(val);
  }
}

//***************************
void sendMessage() {
  static int cmp = 100;
  //
  pc.putc('D');
  pc.printf("%d", cmp);
  pc.putc('T');
  //
  cmp += 1;
  if (cmp > 1000) {
    cmp = 100;
  }
}

//***************************
void flash() {
  for (int i = 0; i < 3; i++) {
    ledInternal = 1;
    wait_us(100000);
    //
    ledInternal = 0;
    wait_us(100000);
  }
}

//****************************
void setup() {
  //
  ledInternal = 0;
  pc.baud(115200);
  pc.attach(&serialHandler, Serial::RxIrq);
}
//****************************
void loop() {
  flash();
  //
  sendMessage();
  //
  thread_sleep_for(1000);
}

//****************************
int main() {
  setup();

  while (true) {
    loop();
  }
}
