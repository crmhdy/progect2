#include "Student.h"
#include "Reservation.h"
#include "Meal.h"
#include <iostream>
#include <algorithm>

using namespace std;

void Student::print() const {
    cout << getstudent_id() << '\t'
        << getname() << '\t'
        << getemail() << '\t'
        << getbalance() << '\t'
        << getis_active() << '\t';
}

void Student::reserve_meal(Meal* meal, Reservation* reserve) {
    if (meal->getprice() <= this->balance) {
        balance -= meal->getprice();
        reserve->setmeal(meal);
    }
}

bool Student::cancel_reservation(Reservation* reservation) {
    auto it = find(this->reservation.begin(), this->reservation.end(), *reservation);
    if (it != this->reservation.end()) {
        this->reservation.erase(it);
        return true;
    }
    return false;
}

void Student::activate() {
    setactiv(true);
}

void Student::deactivate() {
    setactiv(false);
}

void Student::gettype() {
    cout << "Student";
}

vector<Reservation> Student::getreservation() {
    return reservation;
}

// Setters
void Student::setphone(string phone) { this->phone = phone; }
void Student::setstudent_id(string student_id) { this->student_id = student_id; }
void Student::setname(string name) { this->name = name; }
void Student::setemail(string email) { this->email = email; }
void Student::setbalance(float balance) { this->balance = balance; }
void Student::setreserv(Reservation reserv) { reservation.push_back(reserv); }
void Student::setactiv(bool activ) { is_active = activ; }

// Getters
string Student::getstudent_id() const { return student_id; }
string Student::getname() const { return name; }
string Student::getemail() const { return email; }
float Student::getbalance() const { return balance; }
bool Student::getis_active() const { return is_active; }
string Student::getphone() const { return phone; }
