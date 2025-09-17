#pragma once
#ifndef TRANSACTION_H
#define TRANSACTION_H

#include <string>
#include <ctime>
#include"Enums.h"
using std::string;

// Forward declaration for enums (اگر در فایل جدا تعریف شده‌اند)


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

    void settransaction_id(int id);
    void settracking_code(string code);
    void setamount(float amount);
    void settype(TransactionType type);
    void setstatus(TransactionStatus status);
    void setcreated(time_t time);

    int gettransaction_id() const;
    string gettracking_code() const;
    float getamount() const;
    TransactionType gettype() const;
    TransactionStatus getstatus() const;
    time_t getcreated_at() const;
};

#endif // TRANSACTION_H
