#include "Recommendation.h"
#include <iostream>

Recommendation::Recommendation() {    
}

std::vector<std::string> Recommendation::getFoodTips(const std::string& phase) const {
    (void)phase;
    return {}; 
}

std::vector<std::string> Recommendation::getCrampTips() const {
    return {};
}

std::vector<std::string> Recommendation::getSelfCareTips(int moodLevel) const {
    (void)moodLevel;
    return {};
}

void Recommendation::displayDailyTips(const std::string& phase, int moodLevel) const {
    (void)phase;
    (void)moodLevel;
    std::cout << "[Recommendation::displayDailyTips] not yet implemented\n";
}