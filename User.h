#pragma once
#ifndef USER_H
#define USER_H

#include <string>
#include <iostream>
using std::string;

class User {
private:
    int user_id;
    string name;
    string last_name;
    string hashed_password;

public:
    User() {}

    virtual void print() const;
    virtual void gettype() const;

    // Setters
    void setuser_id(int user_id);
    void setname(string name);
    void setlast_name(string last_name);
    void sethashed_password(string hashed_password);

    // Getters
    int getuser_id() const;
    string getname() const;
    string getlast_name() const;
    string gethashed_password() const;
};

#endif // USER_H
