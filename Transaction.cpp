#include "Transaction.h"
#include <ctime>
#include <string>
#include"Enums.h"

Transaction::Transaction() {
    created_at = time(nullptr);
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

int Transaction::gettransaction_id() const {
    return transaction_id;
}

string Transaction::gettracking_code() const {
    return tracking_code;
}

float Transaction::getamount() const {
    return amount;
}

TransactionStatus Transaction::getstatus() const {
    return status;
}

TransactionType Transaction::gettype() const {
    return type;
}

time_t Transaction::getcreated_at() const {
    return created_at;
}
