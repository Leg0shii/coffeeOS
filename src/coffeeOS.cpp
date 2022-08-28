#include <Arduino.h>
#include <Adafruit_PN532.h>
#include <chrono>
#include <unordered_map>

#include "coffeeOS.h"

#include "my_config.h"

#include "product.h"

bool reset = true;

/*! @brief This function initializes the rotary encoder.
 */
void CoffeeOS::rotaryEncoder_init() {
    pinMode(ROT_BUTTON, INPUT_PULLUP);
    pinMode(ROT_CLK, INPUT);
    pinMode(ROT_DT, INPUT);

    ESP32Encoder::useInternalWeakPullResistors = UP;
    encoder_t.attachFullQuad(ROT_CLK, ROT_DT);
    encoder_t.clearCount();
    encoder_t.pauseCount();
}

void CoffeeOS::display_init() {
    char *msgs[] = {(char *)"SSD1306 @ 0x3C", (char *)"SSD1306 @ 0x3D", (char *)"SH1106 @ 0x3C", (char *)"SH1106 @ 0x3D"};

    int checkDisplay = obdI2CInit(&obd, OLED_128x64, -1, 0, 0, 1, -1, -1, -1, 800000L);
    obdSetContrast(&obd, brightness_t);
    obdSetBackBuffer(&obd, ucBuffer);
    obdSetTextWrap(&obd, 1);

    obdFill(&obd, 0, 1);
    obdWriteString(&obd, 0, 0, 1*8, msgs[checkDisplay], FONT_8x8, 0, 1);
    delay(4000);
    obdFill(&obd, 0, 1);
}

void CoffeeOS::nfcReader_init() {
    Adafruit_PN532 reader = CoffeeOS::instance().nfc_reader_t;
    reader.begin();

    uint32_t versiondata = reader.getFirmwareVersion();
    if (!versiondata) {
        Serial.println("PN532 not found!");
        obdWriteString(&obd, 0, 0, 2*8, (char *) "PN532 not found!", FONT_6x8, 0, 1);
        delay(2000);
        return;
    }

    Serial.println("PN532 found!");
    obdWriteString(&obd, 0, 0, 2*8, (char *)"PN532 init", FONT_6x8, 0, 1);

    reader.setPassiveActivationRetries(0xFF); // set maximum retries
    reader.SAMConfig();
    Serial.println("PN532 configured");
    obdWriteString(&obd, 0, 0, 3*8, (char *)"PN532 config", FONT_6x8, 0, 1);
    delay(2000);
}

void CoffeeOS::startUpScreen() {
    obdFill(&obd, 0, 1);
    obdWriteString(&obd, 0, 10, 2*8, (char *)"ESP32 - ", FONT_8x8, 0, 1);
    obdWriteString(&obd, 0, 10, 4*8, (char *)"Coffee - ", FONT_8x8, 0, 1);
    obdWriteString(&obd, 0, 10, 6*8, (char *)"inator  ", FONT_8x8, 0, 1);
}

void CoffeeOS::setup() {

    Serial.begin(115200);

    rotaryEncoder_init();
	display_init();
    nfcReader_init();

	startUpScreen();

    mySaver.saverInit();
    myMenu.setup();
    myManager.setup();

    user u = myManager.getUserList().at(0);
    Serial.print(("User: " + u.firstName + "; To pay: " + std::to_string(u.getAmount())).c_str());

}

void CoffeeOS::loop() {
    std::string prev_prod_name = myMenu.getCurrentProduct();
    myMenu.onRotateEvent();

    if ((std::time(nullptr) - myMenu.getTimeStamp()) > 10) {
        if (reset) return; // check if start up was already drawn

        myMenu.exitMenu();
        startUpScreen();

        reset = true;
    } else {

        std::string curr_prod_name = myMenu.getCurrentProduct();
        if (prev_prod_name == curr_prod_name) return; // check if current name was already drawn

        int xShift = (15 - strlen(curr_prod_name.c_str()));
        obdFill(&obd, 0, 1);
        obdWriteString(&obd, 0, 8*(xShift/2), 4*8, (char *)curr_prod_name.c_str(), FONT_8x8, 0, 1);

        reset = false;
    }
}

