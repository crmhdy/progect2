#pragma once
#ifndef ENUMS_H
#define ENUMS_H

// نوع وعده غذایی
enum Meal_type { breakfast, dinner, lunch };

// آیتم‌های جانبی غذا (خالی فعلاً)
enum Item {};

// وضعیت رزرو
enum Status { faild, cancelled, success };

// روزهای رزرو
enum ReservDay { Saturday, Sunday, Monday, Tuesday, Wednesday };

// نوع تراکنش
enum TransactionType { Transfer, Payment };

// وضعیت تراکنش
enum TransactionStatus { Pending, Completed, Failed };

// وضعیت session
enum SessionStatus { Authenticated, Anonymous };

#endif // ENUMS_H
