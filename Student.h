#pragma once
#ifndef STUDENT_H
#define STUDENT_H

#include <string>
#include <vector>
#include <iostream>
#include <algorithm>
#include"User.h"
#include"Reservation.h"
using std::string;
using std::vector;

// Forward declarations
class Meal;
class Reservation;
class User;

class Student : public User {
private:
    string student_id;
    string name;
    string email;
    string phone;
    float balance;
    bool is_active;
    vector<Reservation> reservation;

public:
    Student() {}

    void print() const;
    void reserve_meal(Meal* meal, Reservation* reserve);
    bool cancel_reservation(Reservation* reservation);
    void activate();
    void deactivate();
    void gettype();
    vector<Reservation> getreservation();

    // Setters
    void setphone(string phone);
    void setstudent_id(string student_id);
    void setname(string name);
    void setemail(string email);
    void setbalance(float balance);
    void setactiv(bool activ);
    void setreserv(Reservation reserv);

    // Getters
    string getphone() const;
    string getstudent_id() const;
    string getname() const;
    string getemail() const;
    float getbalance() const;
    bool getis_active() const;
};

#endif // STUDENT_H
