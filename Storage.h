#pragma once
#ifndef STORAGE_H
#define STORAGE_H

#include <vector>
using std::vector;

class Meal;
class DiningHall;

class Storage {
private:
    int mealid_counter;
    int dining_hallid_counter;
    vector<Meal> all_meals;
    vector<DiningHall> all_dining_halls;

    static Storage* instance;
    Storage() {}

public:
    Storage(const Storage&) = delete;
    Storage& operator=(const Storage&) = delete;

    static Storage* getInstance();

    vector<Meal> getall_meals();
};

#endif // STORAGE_H
