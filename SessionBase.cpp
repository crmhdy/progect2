#include "SessionBase.h"
#include <ctime>
#include"Enums.h"

SessionBase::SessionBase() {
    created_at = time(nullptr);
}

void SessionBase::setcreated_at(time_t time) {
    created_at = time;
}

void SessionBase::setlasttime_login(time_t last) {
    lasttime_login = last;
}

void SessionBase::setstatus(SessionStatus status) {
    this->status = status;
}

time_t SessionBase::getcreated_at() const {
    return created_at;
}

time_t SessionBase::getlasttime_login() const {
    return lasttime_login;
}

SessionStatus SessionBase::getstatus() const {
    return status;
}
