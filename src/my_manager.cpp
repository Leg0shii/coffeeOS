
#include <unordered_map>

#include "coffeeOS.h"

#include "my_manager.h"
#include "product.h"
#include "user.h"

void my_manager::loadUsers() {
    user_list.insert({0, user(0, "Tim", "Pruess", 0.0)});
    user_list.insert({1, user(1, "Olaf", "nn", 0.0)});
    user_list.insert({2, user(2, "Holger", "nn", 0.0)});
    user_list.insert({3, user(3, "Markus", "nn", 0.0)});
    user_list.insert({4, user(4, "Ronald", "nn", 0.0)});

    CoffeeOS::instance().mySaver.saveUser(0, 10.25);
    CoffeeOS::instance().mySaver.setAllUserAmount();
}

void my_manager::loadProducts() {
    product_list.insert({0, product(0, "Kaffee", 1.0)});
    product_list.insert({1, product(1, "Ristretto", 1.5)});
    product_list.insert({2, product(2, "Espresso", 1.2)});
    product_list.insert({3, product(3, "Latte Macchiato", 10.1)});
    product_list.insert({4, product(4, "Cappuccino", 20.0)});
    product_list.insert({5, product(5, "Cafe Latte", 1.23)});
    product_list.insert({6, product(6, "Cafe au lait", 2.5)});
    product_list.insert({7, product(7, "Cafe Americano", 3.5)});
    product_list.insert({8, product(8, "Flat White", 4.2)});
    product_list.insert({9, product(9, "Long Black", 4.2)});
    product_list.insert({10, product(10, "Heisse Milch", 4.2)});
    product_list.insert({11, product(11, "Milchschaum", 4.2)});
    product_list.insert({12, product(12, "Schwarzer Tee", 4.2)});
    product_list.insert({13, product(13, "Gruener Tee", 4.2)});
    product_list.insert({14, product(14, "Kraeutertee", 4.2)});
    product_list.insert({15, product(15, "Fruechtetee", 4.2)});

    // product_list.insert({3, product(3, "Espresso Macchiato", 0.5)});
    // product_list.insert({6, product(6, "Cappuccino Italiano", 1.75)});
}

void my_manager::updateUser(int id, double amount) {
    user_list.at(id).initAmount(amount);
}

void my_manager::setup() {
    loadProducts();
    loadUsers();
}

std::unordered_map<int, product> &my_manager::getProductList() {
    return product_list;
}

std::unordered_map<int, user> &my_manager::getUserList() {
    return user_list;
}
