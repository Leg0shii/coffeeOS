#ifndef TIMHELP_PRODUCT_T_H
#define TIMHELP_PRODUCT_T_H

#pragma once

#include <string>

class product {
public:
    int identifier;
    std::string name;
    double price;

    product(int, std::string, double);

    std::string toString() const;
    void printData() const;
};


#endif //TIMHELP_PRODUCT_T_H
