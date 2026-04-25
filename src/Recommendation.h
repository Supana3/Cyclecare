#ifndef RECOMMENDATION_H
#define RECOMMENDATION_H

#include <string>
#include <vector>

/**
 * Recommendation provides phase-aware food, cramp-relief, and
 * self-care tips. Tips are hardcoded for now; later can be file-loaded.
 */
class Recommendation {
private:
    // Phase-keyed tip lists (loaded in constructor)
    std::vector<std::string> menstrualFoods;
    std::vector<std::string> follicularFoods;
    std::vector<std::string> ovulationFoods;
    std::vector<std::string> lutealFoods;
    std::vector<std::string> crampTips;
    std::vector<std::string> selfCareTips;

public:
    // Constructor
    Recommendation();

    // Core functionality (all const — pure lookups, safe to test)
    std::vector<std::string> getFoodTips(const std::string& phase) const;
    std::vector<std::string> getCrampTips() const;
    std::vector<std::string> getSelfCareTips(int moodLevel) const;
    void displayDailyTips(const std::string& phase, int moodLevel) const;
};

#endif // RECOMMENDATION_H