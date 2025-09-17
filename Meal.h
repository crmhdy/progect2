#pragma once
#ifndef MEAL_H
#define MEAL_H

#include <string>
#include <vector>
#include <iostream>
#include"Enums.h"
using std::string;
using std::vector;

// Forward declarations



class Meal {
private:
    int meal_id;
    string name;
    float price;
    bool isactive;
    Meal_type meal_type;
    vector<Item> side_items;
    ReservDay reserv_day;

public:
    Meal() {}

    void print() const;
    void update_price(float new_price);
    void add_side_item(string item);
    void activate();
    void deactivate();

    // Setters
    void setmeal_id(int meal_id);
    void setname(string name);
    void setprice(float price);
    void setis_active(bool active);
    void setmeal_type(Meal_type type);
    void setreserv_day(ReservDay reserv_day);

    // Getters
    int getmeal_id() const;
    string getname() const;
    float getprice() const;
    bool is_active() const;
    Meal_type getmeal_type() const;
    ReservDay getreserv_day() const;
};

#endif // MEAL_H
