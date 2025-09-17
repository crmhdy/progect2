#pragma once
#ifndef DININGHALL_H
#define DININGHALL_H

#include <string>
#include <iostream>
using std::string;

class DiningHall {
private:
    int hall_id;
    string name;
    string address;
    int capacity;

public:
    DiningHall() {}

    void print() const;

    // Setters
    void sethall_id(int hall_id);
    void setname(string name);
    void setaddress(string address);
    void setcapacity(int capacity);

    // Getters
    int gethall_id() const;
    string getname() const;
    string getaddress() const;
    int getcapacity() const;
};

#endif // DININGHALL_H
