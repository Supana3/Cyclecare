#include "CycleCareApp.h"
#include <iostream>
#include <limits>

CycleCareApp::CycleCareApp() {
    dataFilename = "cyclecare_data.txt"; 
}

CycleCareApp::CycleCareApp(const std::string& filename) {
    dataFilename = filename;
}
    
void CycleCareApp::run() {
    displayWelcome();
    int choice = 0;
    do {
        displayMenu();
        std::cout << "Enter your choice: ";
        if (!(std::cin >> choice)) {
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            std::cout << "Invalid input. Please enter a number.\n";
            continue;
        }
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); 

        switch (choice) {
            case 1: 
            logPeriodAction();
             break;
            case 2: 
            logMoodAction();
             break;
            case 3: 
            showPredictionAction();
             break;
            case 4: 
            showFoodTipsAction(); 
             break;
            case 5: 
            showCrampTipsAction();
             break;
            case 6: 
            changeThemeAction(); 
             break;
            case 0: 
            std::cout << "Exiting. Goodbye!\n"; 
             break;
            default: 
            std::cout << "Invalid choice. Please try again.\n";
             break;
        }
    } while (choice != 0);
}

void CycleCareApp::logPeriodAction() {
    std::string date;
    int cycleLen = 0;
    int periodLen = 0;

    std::cout << "\n--- Log New Period ---\n";
    std::cout << "Enter period start date (YYYY-MM-DD): ";
    std::getline(std::cin, date);

    std::cout << "Enter your average cycle length in days (typical: 28): ";
    if (!(std::cin >> cycleLen)) {
        std::cin.clear();
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        cycleLen = 28;
        std::cout << "Invalid input. Using default cycle length of 28 days.\n";
    } else {
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    }

    cycle.logPeriod(date);
    cycle.setCycleLength(cycleLen);
    cycle.setPeriodLength(periodLen);

    std::cout << "\nPeriod logged successfully!\n";
    std::cout << "Last period date: " << cycle.getLastPeriodDate() << "\n";
    std::cout << "Cycle length: " << cycle.getCycleLength() << " days\n";
    std::cout << "Period length: " << cycle.getPeriodLength() << " days\n";
}

void CycleCareApp::logMoodAction() {
    std::cout << "\n--- Log Mood ---\n";

    std::string date;
    std::cout << "Enter date (YYYY-MM-DD): ";
    std::getline(std::cin, date);
    if (date.empty()) {
        std::cout << "Date is required. Mood not logged.\n";
        return;
    }

    int level = 0;
    std::cout << "Enter your mood level (1=low, 5=great): ";
    if (!(std::cin >> level)) {
        std::cin.clear();
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        std::cout << "Invalid input. Mood not logged.\n";
        return;
    }
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

    if (level < 1 || level > 5) {
        std::cout << "Mood level must be between 1 and 5. Mood not logged.\n";
        return;
    }

    std::string note;
    std::cout << "Add a note (optional, press Enter to skip): ";
    std::getline(std::cin, note);

    MoodLog entry(date, level, note);
    moodHistory.push_back(entry);

    std::cout << "\nMood logged successfully!\n";
    entry.display();
    std::cout << "You have " << getMoodEntryCount() << " mood entries on record.\n";
}

void CycleCareApp::showPredictionAction() {
    std::cout << "[CycleCareApp::showPredictionAction] not yet implemented\n";
}

void CycleCareApp::showFoodTipsAction() const {
    std::cout << "[CycleCareApp::showFoodTipsAction] not yet implemented\n";
}

void CycleCareApp::showCrampTipsAction() const {
    std::cout << "[CycleCareApp::showCrampTipsAction] not yet implemented\n";
}

void CycleCareApp::changeThemeAction() {
    std::cout << "[CycleCareApp::changeThemeAction] not yet implemented\n";
}

bool CycleCareApp::loadFromFile(const std::string& filename) {
    (void)filename;
    return false; 
}

bool CycleCareApp::saveToFile(const std::string& filename) const {
    (void)filename;
    return false; 
}

int CycleCareApp::getMoodEntryCount() const {
    return static_cast<int>(moodHistory.size()); 
}

bool CycleCareApp::hasData() const {
    return !cycle.getLastPeriodDate().empty() || !moodHistory.empty(); 
}

void CycleCareApp::displayMenu() const {
    std::cout << "\n========== CycleCare Menu ==========\n";
    std::cout << "1. Log New Period\n";
    std::cout << "2. Log Mood\n";
    std::cout << "3. Show Next Period Prediction\n";
    std::cout << "4. Show Food Tips\n";
    std::cout << "5. Show Cramp Relief Tips\n";
    std::cout << "6. Change Theme\n";
    std::cout << "0. Exit\n";
    std::cout << "====================================\n";
}

void CycleCareApp::displayWelcome() const {
    std::cout << "\n*** Welcome to CycleCare! ***\n";
    std::cout << "Track your cycle, log your mood, and get personalized tips!\n";
}

void CycleCareApp::applyTheme() const {
}

std::string CycleCareApp::currentDate() const {
    return ""; 
}