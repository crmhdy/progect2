#pragma once
#ifndef ADMINSESSION_H
#define ADMINSESSION_H

#include <string>
#include "SessionBase.h"
using std::string;

class Admin; // Forward declaration

namespace AdminSession {

    class SessionManager : public SessionBase {
    private:
        Admin* current_admin;
        int admin_id;
        void load_session(string) override;
        void save_session() override;

        SessionManager();
        static SessionManager* instance;

    public:
        SessionManager(const SessionManager&) = delete;
        void operator=(const SessionManager&) = delete;

        static SessionManager* getInstance();

        void login(string username, string password) override;
        void logout() override;
        Admin* getcurrent_admin();

        // Getters
        int getadmin_id() const;
    };

}

#endif // ADMINSESSION_H
