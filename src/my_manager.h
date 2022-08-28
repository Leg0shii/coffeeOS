#pragma once

#ifndef UNTITLED_PREF_H
#define UNTITLED_PREF_H

#include "product.h"
#include "user.h"

static std::unordered_map<int, product> product_list;
static std::unordered_map<int, user> user_list;

class my_manager {
public:

    // static void saveUsers();
    static void loadUsers();
    static void loadProducts();
    static void setup();
    static std::unordered_map<int, product> getProductList();
    static std::unordered_map<int, user> getUserList();
};

#endif //UNTITLED_PREF_H
