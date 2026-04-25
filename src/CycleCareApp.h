#ifndef CYCLECAREAPP_H
#define CYCLECAREAPP_H

#include <string>
#include <vector>
#include "User.h"
#include "Cycle.h"
#include "MoodLog.h"
#include "Recommendation.h"

/**
 * CycleCareApp is the main manager class. It owns the User, Cycle,
 * mood log history, and Recommendation engine, and drives the menu loop,
 * file I/O, and console theming.
 */
class CycleCareApp {
private:
    User user;
    Cycle cycle;
    std::vector<MoodLog> moodHistory;
    Recommendation recommendations;
    std::string dataFilename;

    // Helpers
    void displayMenu() const;
    void displayWelcome() const;
    void applyTheme() const;   // ANSI color based on phase/mood
    std::string currentDate() const;

public:
    // Constructors
    CycleCareApp();
    explicit CycleCareApp(const std::string& dataFilename);

    // Main loop
    void run();

    // Actions triggered from menu
    void logPeriodAction();
    void logMoodAction();
    void showPredictionAction();
    void showFoodTipsAction() const;
    void showCrampTipsAction() const;
    void changeThemeAction();

    // File I/O
    bool loadFromFile(const std::string& filename);
    bool saveToFile(const std::string& filename) const;

    // Utility (const)
    int getMoodEntryCount() const;
    bool hasData() const;
};

#endif // CYCLECAREAPP_H