#pragma once

#include "ESP32Encoder.h"
#include "OneBitDisplay.h"
#include <Adafruit_PN532.h>

#include "my_menu.h"
#include "my_manager.h"
#include "saver.h"

 class CoffeeOS {
public:

    int brightness_t = 255;
    uint8_t ucBuffer[1024]{};

    Adafruit_PN532 nfc_reader_t;
    ESP32Encoder encoder_t;
    OBDISP obd{};

    my_menu myMenu;
    saver mySaver;
    my_manager myManager;

    // boot begins from here
    void setup();
    void loop();

    explicit CoffeeOS(Adafruit_PN532 nfc_reader_t) : nfc_reader_t(nfc_reader_t) {
        this->nfc_reader_t = nfc_reader_t;
    }

    static CoffeeOS &instance() {
        static CoffeeOS instance({2, 3});
        return instance;
    }

private:
    void display_init();
    void rotaryEncoder_init();
    void nfcReader_init();
    void startUpScreen();

};

