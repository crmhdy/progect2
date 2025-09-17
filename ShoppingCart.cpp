#include "ShoppingCart.h"
#include "Reservation.h"
#include "Transaction.h"
#include "Student.h"
#include <iostream>
#include "Enums.h"


using namespace std;

void ShoppingCart::add_reservation(Reservation reservation) {
    this->reservation.push_back(reservation);
}

void ShoppingCart::remove_reaervation(int id) {
    for (int i = 0; i < reservation.size(); i++) {
        if (reservation[i].getreservation_id() == id) {
            reservation.erase(reservation.begin() + i);
            break;
        }
    }
}

void ShoppingCart::view_shoppingcart_item() {
    for (int i = 0; i < reservation.size(); i++) {
        reservation[i].print();
    }
}

void ShoppingCart::clear() {
    reservation.clear();
}

vector<Reservation> ShoppingCart::getreservation() const {
    return reservation;
}

Transaction ShoppingCart::confirm(Student* student) {
    float sum = 0;
    vector<Reservation> stu = student->getreservation();
    for (int i = 0; i < reservation.size(); i++) {
        for (int j = 0; j < stu.size(); j++) {
            if (reservation[i].getmeal()->getreserv_day() != stu[j].getmeal()->getreserv_day()) {
                if (reservation[i].getstatus() != success && reservation[i].getstatus() != faild) {
                    if (reservation[i].getmeal()->is_active() == true) {
                        if (reservation[i].getdhall()->getcapacity() > 0) {
                            sum += reservation[i].getprice();
                        }
                    }
                }
            }
        }
    }

    Transaction trns;
    if (sum <= student->getbalance()) {
        trns.setamount(sum);
    }

    return trns;
}
