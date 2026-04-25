#ifndef CYCLE_H
#define CYCLE_H

#include <string>

/**
 * Cycle represents a user's menstrual cycle data and provides
 * phase calculations and next-period predictions.
 */
class Cycle {
private:
    std::string lastPeriodDate;   // YYYY-MM-DD
    int cycleLength;              // Average days between periods (typical: 28)
    int periodLength;             // Average days of bleeding (typical: 5)
    int currentDayOfCycle;        // 1-based day within current cycle

public:
    // Constructors
    Cycle();
    Cycle(const std::string& lastPeriodDate, int cycleLength, int periodLength);

    // Getters (const — side-effect-free)
    std::string getLastPeriodDate() const;
    int getCycleLength() const;
    int getPeriodLength() const;
    int getCurrentDayOfCycle() const;

    // Setters
    void setLastPeriodDate(const std::string& date);
    void setCycleLength(int days);
    void setPeriodLength(int days);

    // Core functionality
    void logPeriod(const std::string& startDate);
    std::string predictNextPeriod() const;
    std::string getCurrentPhase() const;   // "menstrual", "follicular", "ovulation", "luteal"
    int daysUntilNextPeriod() const;
};

#endif // CYCLE_H