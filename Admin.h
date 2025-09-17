#pragma once
#ifndef ADMIN_H
#define ADMIN_H
#include"User.h"
#include <iostream>
#include <string>
using std::string;

class User; // Forward declaration

class Admin : public User {
public:
    Admin() {}

    void print() const;
    void gettype() const;
};

#endif // ADMIN_H
