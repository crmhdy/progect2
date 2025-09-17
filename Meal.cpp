#include "Meal.h"
#include"Enums.h"
#include <iostream>
using namespace std;


void Meal::print() const {
    cout << getmeal_id() << '\t'
        << getname() << '\t'
        << getprice() << '\t';
    for (int i = 0; i < side_items.size(); i++) {
        cout << side_items[i] << '\t';
    }
}

void Meal::update_price(float new_price) {
    if (new_price >= 0) {
        setprice(new_price);
    }
}

void Meal::add_side_item(string item) {
    // برای اضافه کردن آیتم جانبی باید کلاس Item تعریف شده باشد
    // مثال: side_items.push_back(Item(item));
}

void Meal::activate() {
    setis_active(true);
}

void Meal::deactivate() {
    setis_active(false);
}

// Setters
void Meal::setmeal_id(int meal_id) { this->meal_id = meal_id; }
void Meal::setname(string name) { this->name = name; }
void Meal::setprice(float price) { this->price = price; }
void Meal::setmeal_type(Meal_type type) { meal_type = type; }
void Meal::setis_active(bool active) { isactive = active; }
void Meal::setreserv_day(ReservDay reserv_day) { this->reserv_day = reserv_day; }

// Getters
int Meal::getmeal_id() const { return meal_id; }
string Meal::getname() const { return name; }
float Meal::getprice() const { return price; }
Meal_type Meal::getmeal_type() const { return meal_type; }
bool Meal::is_active() const { return isactive; }
ReservDay Meal::getreserv_day() const { return reserv_day; }
