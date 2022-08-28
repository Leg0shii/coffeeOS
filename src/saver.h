#ifndef COFFEEOS_SAVER_H
#define COFFEEOS_SAVER_H

#pragma once

#include <unordered_map>

class saver {
public:
    void saverInit();

    void saveUser(int, double);
    void saveAllUser();
    
    double getUserAmount(int);
    void setAllUserAmount();

private:
    void clearFlashMem();
    void writeIntIntoEEPROM(int, int);
    int readIntFromEEPROM(int);
    
};


#endif //COFFEEOS_SAVER_H
