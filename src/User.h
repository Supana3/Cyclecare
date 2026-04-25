#ifndef USER_H
#define USER_H

#include <string>

/**
 * User holds personal profile info and theme preferences.
 */
class User {
private:
    std::string name;
    int age;
    std::string themePreference;   // "auto", "warm", "cool", "mono"

public:
    // Constructors
    User();
    User(const std::string& name, int age);

    // Getters
    std::string getName() const;
    int getAge() const;
    std::string getThemePreference() const;

    // Setters
    void setName(const std::string& name);
    void setAge(int age);
    void setThemePreference(const std::string& theme);

    // Core functionality
    void displayProfile() const;
};

#endif // USER_H