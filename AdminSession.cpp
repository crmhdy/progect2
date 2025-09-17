#include "AdminSession.h"
#include "Admin.h" // شامل تعریف کامل کلاس Admin
#include <string>

using namespace std;

namespace AdminSession {

    SessionManager* SessionManager::instance = nullptr;

    SessionManager::SessionManager() : current_admin(nullptr), admin_id(0) {}

    SessionManager* SessionManager::getInstance() {
        if (instance == nullptr) {
            instance = new SessionManager();
        }
        return instance;
    }

    void SessionManager::load_session(string userid) {
        // پیاده‌سازی بارگذاری session با userid
    }

    void SessionManager::save_session() {
        // پیاده‌سازی ذخیره session
    }

    void SessionManager::login(string username, string password) {
        // پیاده‌سازی login برای Admin
    }

    void SessionManager::logout() {
        current_admin = nullptr;
        
    }

    Admin* SessionManager::getcurrent_admin() {
        return current_admin;
    }

    int SessionManager::getadmin_id() const {
        return admin_id;
    }

}
