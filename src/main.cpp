#include "coffeeOS.h"

OBDISP obd;

void setup() {
    CoffeeOS::instance().setup();
}

void loop() {
    CoffeeOS::instance().loop();
}
