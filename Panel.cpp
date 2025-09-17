#include "Panel.h"
#include "Student.h"
#include "Reservation.h"
#include "ShoppingCart.h"
#include "Storage.h"
#include <iostream>
#include <vector>
using namespace std;

void Panel::action(int i) {
    // متد برای انتخاب عمل
}

void Panel::show_menu(Storage* storage) {
    storage->getall_meals();
}

void Panel::show_student_info(Student* student) {
    student->print();
}

void Panel::check_balance(Student* student) {
    cout << student->getbalance();
}

void Panel::view_reservation(Student* student) {
    vector<Reservation> s = student->getreservation();
    for (int i = 0; i < s.size(); i++) {
        s[i].print();
    }
}

void Panel::view_shopping_cart(ShoppingCart* shp) {
    vector<Reservation> r = shp->getreservation();
    for (int i = 0; i < r.size(); i++) {
        r[i].print();
    }
}

void Panel::remove_shopping_cart_item(Reservation* reserve, ShoppingCart* shp) {
    shp->remove_reaervation(reserve->getreservation_id());
}

void Panel::exit() {
    // پیاده‌سازی خروج
}
