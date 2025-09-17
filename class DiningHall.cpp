#include "DiningHall.h"
#include <iostream>
using namespace std;

void DiningHall::print() const {
    cout << gethall_id() << '\t'
        << getname() << '\t'
        << getaddress() << '\t'
        << getcapacity() << '\n';
}

// Setters
void DiningHall::sethall_id(int hall_id) { this->hall_id = hall_id; }
void DiningHall::setname(string name) { this->name = name; }
void DiningHall::setaddress(string address) { this->address = address; }
void DiningHall::setcapacity(int capacity) { this->capacity = capacity; }

// Getters
int DiningHall::gethall_id() const { return hall_id; }
string DiningHall::getname() const { return name; }
string DiningHall::getaddress() const { return address; }
int DiningHall::getcapacity() const { return capacity; }
