#include "User.h"
#include <string>
using namespace std;

void User::print() const {
    // تو اینجا می‌تونی تعریف پایه‌ای چاپ اضافه کنی اگر لازم بود
}

void User::gettype() const {
    // تو اینجا می‌تونی نوع پایه‌ای کاربر اضافه کنی
}

// Setters
void User::setuser_id(int user_id) { this->user_id = user_id; }
void User::setname(string name) { this->name = name; }
void User::setlast_name(string last_name) { this->last_name = last_name; }
void User::sethashed_password(string hashed_password) { this->hashed_password = hashed_password; }

// Getters
int User::getuser_id() const { return user_id; }
string User::getname() const { return name; }
string User::getlast_name() const { return last_name; }
string User::gethashed_password() const { return hashed_password; }
