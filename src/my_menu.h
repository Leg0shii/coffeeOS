#pragma once

#ifndef UNTITLED_MENU_H
#define UNTITLED_MENU_H

static bool temp_turn;                              // force stop after each turn: one turn click -> one new product
static int menu_state = 0;                          // the selected menu item
static time_t time_stamp = time(nullptr);     // after 10s go back to home screen
static bool select_mode;                            // true when user is selecting product (for 10s)
static bool clicked;                                // true when user clicks the turn wheel (for 10s)

class my_menu {
public:
    static void setup();

    static void onRotateEvent();
    static void onLeftEvent();
    static void onRightEvent();
    static void onClickEvent();

    static int getMenuState();
    static time_t getTimeStamp();
    static bool isTurned();
    static bool hasClicked();
    static void setClicked(bool);

    static void initMenu();
    static void exitMenu();

    static std::string getCurrentProduct();
};


#endif //UNTITLED_MENU_H
