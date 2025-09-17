#pragma once
#ifndef SESSIONBASE_H
#define SESSIONBASE_H

#include <ctime>
#include <string>
#include"Enums.h"
using std::string;

// Forward declaration برای enum


class SessionBase {
protected:
    time_t created_at;
    time_t lasttime_login;
    SessionStatus status;

    virtual void load_session(string) = 0;
    virtual void save_session() = 0;

public:
    SessionBase();

    virtual void login(string username, string password) = 0;
    virtual void logout() = 0;

    // Setters
    void setcreated_at(time_t time);
    void setlasttime_login(time_t last);
    void setstatus(SessionStatus status);

    // Getters
    time_t getcreated_at() const;
    time_t getlasttime_login() const;
    SessionStatus getstatus() const;
};

#endif // SESSIONBASE_H
