#ifndef TIMHELP_USER_T_H
#define TIMHELP_USER_T_H

#pragma once

#include <string>

class user {
public:
    int identifier;
    std::string nfcIdentifier;
    std::string firstName;
    std::string lastName;

    user(int, std::string, std::string, double);
    void addAmount(double);
    void resetAmount();
    void printData() const;
    std::string toString() const;
    void initAmount(double); // only for init on reboot!! change is not saved in mem
    double getAmount();

private:
    double amount = 0;
    void dataChange();

};

#endif //TIMHELP_USER_T_H
