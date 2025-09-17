#include "Admin.h"
#include "User.h"
#include <iostream>
using namespace std;

void Admin::print() const {
    cout << getuser_id() << '\t'
        << getname() << '\t'
        << getlast_name() << '\t';
}

void Admin::gettype() const {
    cout << "Admin";
}
