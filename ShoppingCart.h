#pragma once
#ifndef SHOPPINGCART_H
#define SHOPPINGCART_H

#include <vector>
#include"Enums.h"
#include"Reservation.h"
using std::vector;

// Forward declarations
class Reservation;
class Transaction;
class Student;

class ShoppingCart {
private:
    vector<Reservation> reservation;

public:
    ShoppingCart() {}

    Transaction confirm(Student* student);
    void add_reservation(Reservation reservation);
    void remove_reaervation(int id);
    void view_shoppingcart_item();
    void clear();
    vector<Reservation> getreservation() const;
};

#endif // SHOPPINGCART_H
