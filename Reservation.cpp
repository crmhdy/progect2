#include "Reservation.h"
#include "Student.h"
#include "DiningHall.h"
#include "Meal.h"
#include "Enums.h"


Reservation::Reservation() {
    created_at = time(nullptr);
}
void Reservation::print() const {
    cout << getreservation_id() << '\t'
        << static_cast<int>(getstatus()) << '\t'
        << gettime_at() << '\t';
    if (student) student->print();
    if (dhall) dhall->print();
    if (meal) meal->print();
}

bool Reservation::cancel() {
    if (status == success) {
        setstatus(cancelled);
        return true;
    }
}

void Reservation::setreservation_id(int resrve_id) {
    reservation_id = resrve_id;
}

void Reservation::setdhall(DiningHall* dhall) {
    this->dhall = dhall;
}

void Reservation::setmeal(Meal* meal) {
    this->meal = meal;
}

void Reservation::setstatus(Status status) {
    this->status = status;
}

void Reservation::settime_at(time_t time) {
    created_at = time;
}

void Reservation::setday(ReservDay day) {
    this->day = day;
}

void Reservation::setprice(float p) {
    price = p;
}

int Reservation::getreservation_id() const {
    return reservation_id;
}

Status Reservation::getstatus() const {
    return status;
}

time_t Reservation::gettime_at() const {
    return created_at;
}

ReservDay Reservation::getday() const {
    return day;
}

Meal* Reservation::getmeal() const {
    return meal;
}

DiningHall* Reservation::getdhall() const {
    return dhall;
}

float Reservation::getprice() const {
    return price;
}
