#pragma once
#ifndef STUDENTSESSION_H
#define STUDENTSESSION_H

#include <string>
#include "SessionBase.h"
using std::string;

class Student;
class ShoppingCart;

namespace StudentSession {

    class SessionManager : public SessionBase {
    private:
        Student* current_student;
        ShoppingCart* shopping_cart;
        int student_id;

        void load_session(string) override;
        void save_session() override;

        SessionManager();
        static SessionManager* instance;

    public:
        SessionManager(const SessionManager&) = delete;
        void operator=(const SessionManager&) = delete;

        static SessionManager* getInstance();

        void login(string username, string password) override;
        void logout() override;

        Student* getcurrent_student();
        ShoppingCart* getshopping_cart();
    };

}

#endif // STUDENTSESSION_H
