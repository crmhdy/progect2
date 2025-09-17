#include "StudentSession.h"
#include "Student.h"
#include "ShoppingCart.h"
#include "MD5.h"  // برای هش کردن پسورد
#include <fstream>
#include <sstream>
#include <iostream>
#include "Enums.h"


using namespace std;

namespace StudentSession {

    SessionManager* SessionManager::instance = nullptr;

    SessionManager::SessionManager() : current_student(nullptr), shopping_cart(nullptr), student_id(0) {}

    SessionManager* SessionManager::getInstance() {
        if (instance == nullptr) {
            instance = new SessionManager();
        }
        return instance;
    }

    void SessionManager::load_session(string userid) {
        // پیاده‌سازی بارگذاری session
    }

    void SessionManager::save_session() {
        // پیاده‌سازی ذخیره session
    }

    void SessionManager::login(string username, string password) {
        string hashed_pass = MD5::md5(password);

        ifstream file("studentsCsvFile.csv");
        if (!file.is_open()) {
            cerr << "Could not open the file!" << endl;
            exit(1);
        }

        string line;
        getline(file, line); // خواندن header

        while (getline(file, line)) {
            stringstream ss(line);
            string user_id, student_id, first_name, last_name, pass_hash, email, phone;

            getline(ss, user_id, ',');
            getline(ss, student_id, ',');
            getline(ss, first_name, ',');
            getline(ss, last_name, ',');
            getline(ss, pass_hash, ',');
            getline(ss, email, ',');
            getline(ss, phone, ',');

            if (student_id == username && pass_hash == hashed_pass) {
                current_student = new Student();
                current_student->setactiv(true);
                // current_student->setuser_id(stoi(user_id)); // در صورت نیاز
                current_student->setstudent_id(student_id);
                current_student->setname(first_name);
                current_student->setlast_name(last_name);
                current_student->setemail(email);
                current_student->setphone(phone);

                shopping_cart = new ShoppingCart();
                break;
            }
        }

        file.close();
    }

    void SessionManager::logout() {
       
    }

    Student* SessionManager::getcurrent_student() {
        return current_student;
    }

    ShoppingCart* SessionManager::getshopping_cart() {
        return shopping_cart;
    }

}
