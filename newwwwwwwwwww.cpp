#include <iostream>
#include <vector>
#include <algorithm>
#include <fstream>
#include <sstream>
#include <string>
#include "md5.h"

using namespace std;


//enums ---------------------------------------------------------

enum Meal_type{breakfast,dinner,lunch};
enum Item{};
enum Status{faild,cancelled,success};
enum ReservDay { Saturday, Sunday, Monday, Tuesday, Wednesday };
enum TransactionType{Transfer,Payment};
enum TransactionStatus{Pending,Completed,Failed};
enum SessionStatus{Authenticated,Anonymous};

//---------------------------------------------------------

class Meal;
class Reservation;
class DiningHall;
class Student;
class Storage;
class Transaction;
class Student;
class SessionManagar;
class Admin;
class Panel;
class ShoppingCart;
//--------------------------------------------------------
class ShoppingCart {

private:

    vector<Reservation>reservation;

public:

    ShoppingCart(){}
    Transaction confirm(Student*);
    void add_reservation(Reservation);
    void remove_reaervation(int);
    void view_shoppingcart_item();
    void clear();
    vector<Reservation>getreservation()const;

};
void ShoppingCart::add_reservation(Reservation reservation) {
    this->reservation.push_back(reservation);
}
void ShoppingCart::remove_reaervation(int id){
    for (int i = 0; i < reservation.size();i++) {
        if (reservation[i].getreservation_id() == id) {
            reservation.erase(reservation.begin() + i);
        }
    }
}
void ShoppingCart::view_shoppingcart_item() {
    for (int i = 0; i < reservation.size(); i++) {
        reservation[i].print();
    }
}
void ShoppingCart::clear() {
    reservation.clear();
}
vector<Reservation> ShoppingCart::getreservation()const {
    return reservation;
}

Transaction ShoppingCart::confirm(Student* student) {
    float sum = 0;
    vector<Reservation> stu = student->getreservation();
    for (int i = 0; i < reservation.size(); i++) {
        for(int j=0;j<stu.size();i++){   
            if(reservation[i].getmeal()->getreserv_day()!=stu[i].getmeal()->getreserv_day()){
                if (reservation[i].getstatus() != success || reservation[i].getstatus() != faild) {
                    if (reservation[i].getmeal()->is_active() == true) {
                        if (reservation[i].getdhall()->getcapacity() > 0) {
                            sum += reservation[i].getprice();
                        }
                    }

                }
            }
        }
        
    }
    if (sum <= student->getbalance()) {
        Transaction trns;
        trns.setamount(sum);
        
    }
    
}



class Transaction {

private:

    int transaction_id;
    string tracking_code;
    float amount;
    TransactionType type;
    TransactionStatus status;
    time_t created_at;
    
public:

    Transaction();
    void settransaction_id(int);
    void settracking_code(string);
    void setamount(float);
    void settype(TransactionType);
    void setstatus(TransactionStatus);
    void setcreated(time_t);

    int gettransaction_id()const;
    string gettracking_code()const;
    float getamount()const;
    TransactionType gettype()const;
    TransactionStatus getstatus()const;
    time_t getcreated_at()const;
};
Transaction::Transaction() {
    created_at= time(nullptr);
}
void Transaction::settransaction_id(int id) {
    transaction_id = id;
}
void Transaction::settracking_code(string code) {
    tracking_code = code;
}
void Transaction::setamount(float amount) {
    this->amount = amount;
}
void Transaction::settype(TransactionType type) {
    this->type = type;
}
void Transaction::setstatus(TransactionStatus status) {
    this->status = status;
}
void Transaction::setcreated(time_t time) {
    created_at = time;
}
int Transaction::gettransaction_id()const {
    return transaction_id;
}
string Transaction::gettracking_code()const {
    return tracking_code;
}
float Transaction::getamount()const {
    return amount;
}
TransactionStatus Transaction::getstatus()const {
    return status;
}
TransactionType Transaction::gettype()const {
    return type;
}
time_t Transaction::getcreated_at()const {
    return created_at;
}





class SessionBase {

protected:
    time_t created_at;
    time_t lasttime_login;
    SessionStatus status;
    virtual void load_session() = 0;
    virtual void save_session() = 0;
public:
    SessionBase();
    virtual void login(string, string) = 0;
    virtual void logout() = 0;
    //setters
    void setcreated_at(time_t);
    void setlasttime_login(time_t);
    void setstatus(SessionStatus);
    //getters
    time_t getcreated_at()const;
    time_t getlasttime_login()const;
    SessionStatus getstatus()const;
};
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
time_t SessionBase::getcreated_at()const {
    return created_at;
}
time_t SessionBase::getlasttime_login()const {
    return lasttime_login;
}
SessionStatus SessionBase::getstatus()const {
    return status;
}


namespace AdminSession {
    class SessionManager : public SessionBase {
        
    private:
        Admin* current_admin;
        int admin_id;
        void load_session()override;
        void save_session()override;
        SessionManager(){}
        static SessionManager* instance;
    public:
        SessionManager(const SessionManager&) = delete;
        void operator=(const SessionManager&) = delete;
        static SessionManager* getInstance() {
            if (instance == nullptr) {
                instance = new SessionManager();
            }
            return instance;
        }
        void login(string, string)override;
        void logout()override;
        Admin* getcurrent_admin();
        //getters
        int getadmin_id()const;
           
    };
}
void AdminSession::SessionManager::load_session() {

}
void AdminSession::SessionManager::save_session() {

}
void AdminSession::SessionManager::logout() {

}


Admin* AdminSession::SessionManager::getcurrent_admin() {
    return current_admin;
}
int AdminSession::SessionManager::getadmin_id()const {
    return admin_id;
}







namespace StudentSession {
    class SessionManager : public SessionBase {
        
    private:
        
        Student* current_student;
        ShoppingCart* shopping_cart;
        int student_id;
        void load_session()override;
        void save_session()override;
        SessionManager() {}
        static SessionManager* instance;
    public:
        SessionManager(const SessionManager&) = delete;
        void operator=(const SessionManager&) = delete;
        static SessionManager* getInstance() {
            if (instance == nullptr) {
                instance = new SessionManager();
            }
            return instance;
        }
        void login(string, string)override;
        void logout()override;
        Student* getcurrent_student();
        ShoppingCart* getshopping_cart();
           
    };
}
Student* StudentSession::SessionManager::getcurrent_student() {
    return current_student;
}
ShoppingCart* StudentSession::SessionManager::getshopping_cart() {
    return shopping_cart;
}
void StudentSession::SessionManager::login(string username,string password) {
    string hashed_pass = MD5::md5(password);
    ifstream file("studentsCsvFile.csv");
    if (!file.is_open()) {
        cerr << "Could not open the file!" << endl;
        exit(1);
    }
    string line;
    getline(file, line); 
    bool found = false;
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

        if (user_id == username && pass_hash == password) {
            found = true;
            break;
        }
    }
    if (found == true) {
        Student stu;
        stu.setactiv(true);
        
        
    }
    file.close();
}




class Panel {

private:


public:

    Panel(){}
    void action(int);
    void show_menu(Storage* storage);
    void show_student_info(Student*);
    void check_balance(Student* student);
    void view_reservation(Student* student);
    void view_shopping_cart(ShoppingCart*);
    //void add_toshopping_cart();
    //void confirm_shopping_cart();
    void remove_shopping_cart_item(Reservation*, ShoppingCart*);
    //void increase_balance();
    //void view_recent_transations();
    //void cancel_reservation(int);
    void exit();

};
void Panel::action(int i) {
    
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
void Panel::remove_shopping_cart_item(Reservation* reserve,ShoppingCart* shp) {
    shp->remove_reaervation(reserve->getreservation_id());
}
void Panel::exit() {

}





class Storage {

private:

    int mealid_counter;
    int dining_hallid_counter;
    vector <Meal> all_meals;
    vector <DiningHall> all_dining_halls;
    static Storage* instance;
    Storage(){}

public:

    Storage(const Storage&) = delete;
    Storage& operator=(const Storage&) = delete;
    static Storage* getInstance() {
        if (instance == nullptr) {
            instance = new Storage();
        }
        return instance;
    }
    vector<Meal> getall_meals();

};
Storage* Storage::instance = nullptr;
vector<Meal> Storage::getall_meals() {
    return all_meals;
}



class User {

private:

    int user_id;
    string name;
    string last_name;
    string hashed_password;

public:
    User(){}
    virtual void print()const;
    virtual void gettype()const;
    //setters
    void setuser_id(int);
    void setname(string);
    void setlast_name(string);
    void sethashed_password(string);
    //getters
    int getuser_id()const;
    string getname()const;
    string getlast_name()const;
    string gethashed_password()const;

};
void User::print()const{
}
void User::gettype()const{
}
void User::setuser_id(int user_id) {
    this->user_id = user_id;
}
void User::setname(string name) {
    this->name = name;
}
void User::setlast_name(string last_name) {
    this->last_name = last_name;
}
void User::sethashed_password(string hashed_password) {
    this->hashed_password = hashed_password;
}
int User::getuser_id()const {
    return user_id;
}
string User::getname()const {
    return name;
}
string User::getlast_name()const {
    return last_name;
}
string User::gethashed_password()const {
    return hashed_password;
}

//Admin-----------------------------------------

class Admin :public User {

private:


public:
    Admin(){}
    void print()const;
    void gettype()const;

};
void Admin::print()const {
    cout << getuser_id() << '\t'
        << getname() << '\t'
        << getlast_name() << '\t';
}
void Admin::gettype()const {
    cout << "Admin";
}



//Student ---------------------------------------------------------

class Student:public User {
private:

    string student_id;
    string name;
    string email;
    string phone;
    float balance;
    bool is_active;
    vector <Reservation> reservation;

public:

    Student() {}
    void print()const;
    void reserve_meal(Meal*, Reservation*);
    bool cancel_reservation(Reservation*);
    void activate();
    void deactivate();
    void gettype();
    vector<Reservation> getreservation();
    //setters
    void setphone(string);
    void setstudent_id(string);
    void setname(string);
    void setemail(string);
    void setbalance(float);
    void setactiv(bool);
    void setreserv(Reservation);
    //getters
    string getphone()const;
    string getstudent_id()const;
    string getname()const;
    string getemail()const;
    float getbalance()const;
    bool getis_active()const;
    
    

};
void Student::print()const {
    cout << getstudent_id() << '\t'
        << getname() << '\t'
        << getemail() << '\t'
        << getbalance() << '\t'
        << getis_active() << '\t';
        
    
}
void Student::reserve_meal(Meal *meal,Reservation *reserve) {
    
    if (true) {

        if (meal->getprice() <= this->balance) {
            balance -= meal->getprice();
            reserve->setmeal(meal);
        }
    }
}
bool Student::cancel_reservation(Reservation* reservation) {
    auto it = find(this->reservation.begin(), this->reservation.end(), reservation);
    if (it != this->reservation.end()) {
        this->reservation.erase(it);
        return true;
    }
    return false;
}
void Student::activate() {
    setactiv(true);
}
void Student::deactivate() {
    setactiv(false);
}
void Student::gettype() {
    cout << "Student";
}
vector<Reservation> Student::getreservation() {
    return reservation;
}
void Student::setphone(string phone) {
    this->phone = phone;
}
void Student::setstudent_id(string student_id) {
    this->student_id = student_id;
}
void Student::setname(string name) {
    this->name = name;
}
void Student::setemail(string email) {
    this->email = email;
}
void Student::setbalance(float balance) {
    this->balance = balance;
}
void Student::setreserv(Reservation reserv) {
    reservation.push_back(reserv);
}
void Student::setactiv(bool activ) {
    is_active = activ;
}
string Student::getstudent_id()const {
    return student_id;
}
string Student::getname()const {
    return name;
}
string Student::getemail()const {
    return email;
}
float Student::getbalance()const {
    return balance;
}
bool Student::getis_active()const {
    return is_active;
}
string Student::getphone()const {
    return phone;
}


//Meal ---------------------------------------------------------

class Meal{

private:
    
    int meal_id;
    string name;
    float price;
    bool isactive;
    Meal_type meal_type;
    vector <Item> side_items;
    ReservDay reserv_day;

public:

    Meal(){}
    void print()const;
    void update_price(float);
    void add_side_item(string);
    void activate();
    void deactivate();
    //setters
    void setmeal_id(int);
    void setname(string);
    void setprice(float);
    void setis_active(bool);
    void setmeal_type(Meal_type);
    void setreserv_day(ReservDay);
    //getters
    int getmeal_id()const;
    string getname()const;
    float getprice()const;
    bool is_active()const;
    Meal_type getmeal_type()const;
    ReservDay getreserv_day()const;

};
void Meal::print()const {
    cout << getmeal_id() << '\t'
        << getname() << '\t'
        << getprice() << '\t'
        << getmeal_id() << '\t';
    for (int i = 0; i < side_items.size(); i++) {
        cout << side_items[i] << "_";
    }
}
void Meal::update_price(float new_price) {
    if (new_price >= 0) {
        setprice(new_price);
    }
}
void Meal::add_side_item(string item) {
    

}
void Meal::activate() {
    setis_active(true);
}
void Meal::deactivate() {
    setis_active(false);
}
void Meal::setmeal_id(int meal_id) {
    this->meal_id = meal_id;
}
void Meal::setname(string name) {
    this->name = name;
}
void Meal::setprice(float price) {
    this->price = price;
}
void Meal::setmeal_type(Meal_type type) {
    meal_type = type;
}
void Meal::setis_active(bool active) {
    isactive = active;
}
void Meal::setreserv_day(ReservDay reserv_day) {
    this->reserv_day = reserv_day;
}
int Meal::getmeal_id()const {
    return meal_id;
}
string Meal::getname()const {
    return name;
}
float Meal::getprice()const {
    return price;
}
Meal_type Meal::getmeal_type()const {
    return meal_type;
}
bool Meal::is_active()const {
    return isactive;
}
ReservDay Meal::getreserv_day()const {
    return reserv_day;
}
//reservation------------------------------------------------

class Reservation{

private:

    int reservation_id;
    Student *student;
    DiningHall *dhall;
    Meal *meal;
    ReservDay day;
    Status status;
    time_t created_at;
    float price;


public:
    Reservation(){}
    void print()const;
    bool cancel();
    //setters
    void setreservation_id(int);
    void setdhall(DiningHall*);
    void setmeal(Meal*);
    void setstatus(Status);
    void settime_at(time_t);
    void setday(ReservDay);
    void setprice(float);
    //getters
    int getreservation_id()const;
    Status getstatus()const;
    time_t gettime_at()const;
    ReservDay getday()const;
    float getprice()const;
    Meal* getmeal()const;
    DiningHall* getdhall()const;
};
void Reservation::print()const {
    cout << getreservation_id() << '\t'
        << getstatus() << '\t'
        << gettime_at() << '\t';
    student->print();
    dhall->print();
    meal->print();
}
bool Reservation::cancel() {
    if (status == success) {
        setstatus(cancelled);
    }
}
void Reservation::setreservation_id(int resrve_id) {
    reservation_id = resrve_id;
}
void Reservation::setdhall(DiningHall* dhall) {
    this->dhall = dhall;
}
void Reservation::setmeal(Meal* meal) {
    this->meal = meal;
}
void Reservation::setstatus(Status status) {
    this->status = status;
}
void Reservation::settime_at(time_t time) {
    created_at = time;
}
void Reservation::setday(ReservDay day) {
    this->day = day;
}
void Reservation::setprice(float p) {
    price = p;
}
int Reservation::getreservation_id()const {
    return reservation_id;
}
Status Reservation::getstatus()const {
    return status;
}
time_t Reservation::gettime_at()const {
    return created_at;
}
ReservDay Reservation::getday()const{
    return day;
}
Meal* Reservation::getmeal()const {
    return meal;
}
DiningHall* Reservation::getdhall()const {
    return dhall;
}
float Reservation::getprice()const {
    return price;
}


class DiningHall {
private:

    int hall_id;
    string name;
    string address;
    int capacity;

public:
    DiningHall(){}
    void print()const;
    //setters
    void sethall_id(int);
    void setname(string);
    void setaddress(string);
    void setcapacity(int);
    //getters
    int gethall_id()const;
    string getname()const;
    string getaddress()const;
    int getcapacity()const;
};
void DiningHall::print()const {
    cout << gethall_id() << '\t'
        << getname() << '\t'
        << getaddress() << '\t'
        << getcapacity() << '\n';
}
void DiningHall::sethall_id(int hall_id) {
    this->hall_id = hall_id;
}
void DiningHall::setname(string name) {
    this->name = name;
}
void DiningHall::setaddress(string address) {
    this->address = address;
}
void DiningHall::setcapacity(int capacity) {
    this->capacity = capacity;
}
int DiningHall::gethall_id()const {
    return hall_id;
}
string DiningHall::getname()const {
    return name;
}
string DiningHall::getaddress()const {
    return address;
}
int DiningHall::getcapacity()const {
    return capacity;
}


int main()
{
    
}

