#pragma once
#ifndef PANEL_H
#define PANEL_H

#include <iostream>
#include <vector>
using std::vector;

class Student;
class Reservation;
class ShoppingCart;
class Storage;

class Panel {
public:
    Panel() {}

    void action(int i);
    void show_menu(Storage* storage);
    void show_student_info(Student* student);
    void check_balance(Student* student);
    void view_reservation(Student* student);
    void view_shopping_cart(ShoppingCart* shp);
    void remove_shopping_cart_item(Reservation* reserve, ShoppingCart* shp);
    void exit();
};

#endif // PANEL_H
