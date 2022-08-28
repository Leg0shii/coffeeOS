
#include <unordered_map>

#include <Adafruit_PN532.h>

#include "coffeeOS.h"
#include "my_menu.h"
#include "my_config.h"

#include "product.h"

void my_menu::onRotateEvent() {
    if (clicked) return; // check if user has selected an item and clicked on it
    if (digitalRead(ROT_BUTTON) == LOW) {
        onClickEvent();
        return;
    }
    if (digitalRead(ROT_CLK) == LOW) {
        select_mode = true;
        onLeftEvent();
        return;
    }
    if (digitalRead(ROT_DT) == LOW) {
        select_mode = true;
        onRightEvent();
        return;
    }
    temp_turn = false;
}

void my_menu::onLeftEvent() {
    if (temp_turn) return;
    time_stamp = time(nullptr);
    if (menu_state == 0) menu_state = CoffeeOS::instance().myManager.getProductList().size();
    menu_state = menu_state - 1;
    temp_turn = true;
}

void my_menu::onRightEvent() {
    if (temp_turn) return;
    time_stamp = time(nullptr);
    if (menu_state == CoffeeOS::instance().myManager.getProductList().size()-1) menu_state = 0;
    menu_state = menu_state + 1;
    temp_turn = true;
}

void my_menu::onClickEvent() {
    if (!select_mode) return;
    time_stamp = time(nullptr);
    OBDISP obd_t = CoffeeOS::instance().obd;
    std::string name = CoffeeOS::instance().myManager.getProductList().at(menu_state).name;

    obdFill(&obd_t, 0, 1);
    obdWriteString(&obd_t, 0, 0, 2*8, (char *)"You selected: ", FONT_8x8, 0, 1);
    obdWriteString(&obd_t, 0, 0, 4*8, (char *)name.c_str(), FONT_8x8, 0, 1);

    // set precision of double to 2 digits
    std::string num_text = std::to_string(CoffeeOS::instance().myManager.getProductList().at(menu_state).price);
    std::string rounded = num_text.substr(0, num_text.find('.')+3);
    obdWriteString(&obd_t, 0, 0, 6*8, (char *)("Price: " + rounded + " Euro").c_str(), FONT_8x8, 0, 1);
    clicked = true;
}

void my_menu::exitMenu() {
    clicked = false;
    temp_turn = false;
    select_mode = false;
}

int my_menu::getMenuState() const {
    return menu_state;
}

time_t my_menu::getTimeStamp() const {
    return time_stamp;
}

bool my_menu::isTurned() const {
    return temp_turn;
}

bool my_menu::hasClicked() const {
    return clicked;
}

void my_menu::setClicked(bool c) {
    clicked = c;
}

std::string my_menu::getCurrentProduct() const {
    return CoffeeOS::instance().myManager.getProductList().at(menu_state).name;
}

void my_menu::setup() {
    temp_turn = false;                      // force stop after each turn: one turn click -> one new product
    menu_state = 0;                          // the selected menu item
    time_stamp = time(nullptr);     // after 10s go back to home screen
    select_mode = false;                    // true when user is selecting product (for 10s)
    clicked = false;
}

