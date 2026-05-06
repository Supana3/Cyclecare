#include "User.h"
#include <iostream>

User::User() {
    name = "";
    age = 0;
    themePreference = "";
}

User::User(const std::string& userName, int userAge) {
    (void)userName;
    (void)userAge;
    name = "";
    age = 0;
    themePreference = "";
    std::cout << "[User::User(params)] not yet implemented\n";
}

std::string User::getName() const {
    return "";
}

int User::getAge() const {
    return 0;
}

std::string User::getThemePreference() const {
    return "";
}

void User::setName(const std::string& userName) {
    (void)userName;
    std::cout << "[User::setName] not yet implemented\n";
}

void User::setAge(int userAge) {
    (void)userAge;
    std::cout << "[User::setAge] not yet implemented\n";
}

void User::setThemePreference(const std::string& theme) {
    (void)theme;
    std::cout << "[User::setThemePreference] not yet implemented\n";
}

void User::displayProfile() const {
    std::cout << "[User::displayProfile] not yet implemented\n";
}