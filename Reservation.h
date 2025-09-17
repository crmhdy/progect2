#pragma once
#ifndef RESERVATION_H
#define RESERVATION_H
#include "Enums.h"
#include <ctime>
#include <iostream>
#include <iostream>
#include "User.h"
#include "Admin.h"
#include "Student.h"
#include "Meal.h"
#include "Reservation.h"
#include "Transaction.h"
#include "ShoppingCart.h"
#include "SessionBase.h"
#include "AdminSession.h"
#include "StudentSession.h"
#include "Panel.h"
#include "Storage.h"
#include "DiningHall.h"

using std::cout;




class Reservation {
private:
    int reservation_id;
    Student* student;
    DiningHall* dhall;
    Meal* meal;
    ReservDay day;
    Status status;
    time_t created_at;
    float price;

public:
    Reservation();

    void print() const;
    bool cancel();
    bool operator==(const Reservation& other) const {
        return reservation_id == other.reservation_id;
    }

    // Setters
    void setreservation_id(int resrve_id);
    void setdhall(DiningHall* dhall);
    void setmeal(Meal* meal);
    void setstatus(Status status);
    void settime_at(time_t time);
    void setday(ReservDay day);
    void setprice(float p);

    // Getters
    int getreservation_id() const;
    Status getstatus() const;
    time_t gettime_at() const;
    ReservDay getday() const;
    float getprice() const;
    Meal* getmeal() const;
    DiningHall* getdhall() const;
};

#endif // RESERVATION_H
