#include "user.h"

#include "CoffeeOS.h"

// u:id;firstname;lastname;amount
user::user(int identifier, std::string firstName, std::string lastName, double amount) {
    this->firstName = firstName;
    this->lastName = lastName;
    this->nfcIdentifier = identifier;
    this->amount = amount;
}

void user::addAmount(double value) {
    this->amount = this->amount + value;
    dataChange();
}

void user::resetAmount() {
    this->amount = 0;
    dataChange();
}

void user::printData() const {
    OBDISP obd_t = CoffeeOS::instance().obd;
    obdFill(&obd_t, 0, 1);
    obdWriteString(&obd_t, 0, 0, 0*8, (char* ) ("Identifier: " + std::to_string(this->nfcIdentifier)).c_str(), FONT_8x8, 0, 1);
    obdWriteString(&obd_t, 0, 0, 1*8, (char* ) ("First-Name: " + this->firstName).c_str(), FONT_8x8, 0, 1);
    obdWriteString(&obd_t, 0, 0, 2*8, (char* ) ("Last-Name: " + this->lastName).c_str(), FONT_8x8, 0, 1);
    obdWriteString(&obd_t, 0, 0, 3*8, (char* ) ("Amount: " + std::to_string(this->amount)).c_str(), FONT_8x8, 0, 1);
}

void user::dataChange() {
    // update database
}

std::string user::toString() const {
    std::string user_string = "u:";
    user_string = user_string + std::to_string(nfcIdentifier) + ";";
    user_string = user_string + firstName + ";";
    user_string = user_string + lastName + ";";
    user_string = user_string + std::to_string(amount);
    return user_string;
}

