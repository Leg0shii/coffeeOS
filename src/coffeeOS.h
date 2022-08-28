
#include "ESP32Encoder.h"
#include "OneBitDisplay.h"
#include <Adafruit_PN532.h>

 class CoffeeOS {
public:

    int brightness_t = 255;
    uint8_t ucBuffer[1024]{};

    Adafruit_PN532 nfc_reader_t;

    ESP32Encoder encoder_t;
    OBDISP obd{};

    // boot begins from here
    void setup();
    void loop();

    void display_init();
    void rotaryEncoder_init();
    void nfcReader_init();
    void startUpScreen();

    explicit CoffeeOS(Adafruit_PN532 nfc_reader_t) : nfc_reader_t(nfc_reader_t) {
        this->nfc_reader_t = nfc_reader_t;
    }

    static CoffeeOS &instance() {
        static CoffeeOS instance({2, 3});
        return instance;
    }
};

