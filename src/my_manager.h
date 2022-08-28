#pragma once

#ifndef UNTITLED_PREF_H
#define UNTITLED_PREF_H

#include <unordered_map>

#include "product.h"
#include "user.h"

class my_manager {
public:
    void setup();
    void updateUser(int, double);

    std::unordered_map<int, product> &getProductList();
    std::unordered_map<int, user> &getUserList();

private:
    std::unordered_map<int, product> product_list;
    std::unordered_map<int, user> user_list;

    void loadUsers();
    void loadProducts();
};

#endif //UNTITLED_PREF_H
