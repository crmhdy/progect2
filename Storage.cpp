#include "Storage.h"
#include "Meal.h"
#include "DiningHall.h"

Storage* Storage::instance = nullptr;

Storage* Storage::getInstance() {
    if (instance == nullptr) {
        instance = new Storage();
    }
    return instance;
}

vector<Meal> Storage::getall_meals() {
    return all_meals;
}
