#include "Cycle.h"
#include <iostream>
#include <sstream>
#include <iomanip>
#include <ctime>

Cycle::Cycle() {
    lastPeriodDate = "";              
    cycleLength = 28;                
    periodLength = 5;                
    currentDayOfCycle = 0;           
}

Cycle::Cycle(const std::string& date, int cycleLen, int periodLen) {
    lastPeriodDate = date;
    cycleLength = (cycleLen > 0) ? cycleLen : 28;
    periodLength = (periodLen > 0) ? periodLen : 5;
    currentDayOfCycle = 0; 
}

std::string Cycle::getLastPeriodDate() const {
    return lastPeriodDate;
}

int Cycle::getCycleLength() const {
    return cycleLength;
}

int Cycle::getPeriodLength() const {
    return periodLength;
}

int Cycle::getCurrentDayOfCycle() const {
    return currentDayOfCycle;
}

void Cycle::setLastPeriodDate(const std::string& date) {
    lastPeriodDate = date;
}

void Cycle::setCycleLength(int days) {
    if (days > 0) {
        cycleLength = days;
    }
}

void Cycle::setPeriodLength(int days) {
    if (days > 0) {
        periodLength = days;
    }
}

void Cycle::logPeriod(const std::string& startDate) {
    lastPeriodDate = startDate;
    currentDayOfCycle = 1;
}

std::string Cycle::predictNextPeriod() const {
    if (lastPeriodDate.empty() || cycleLength <= 0) {
        return "";
    }

    std::tm tm = {};
    std::istringstream ss(lastPeriodDate);
    ss >> std::get_time(&tm, "%Y-%m-%d"); 
    if (ss.fail()) {
        return "";
    }
    tm.tm_mday += cycleLength;
    std::mktime(&tm);

    std::ostringstream out;
    out << std::put_time(&tm, "%Y-%m-%d");
    return out.str();
}

std::string Cycle::getCurrentPhase() const {
    return "";  
}

int Cycle::daysUntilNextPeriod() const {
    std::string nextPeriod = predictNextPeriod();
    if (nextPeriod.empty()) {
        return -1;
    }
    
    std::tm nextTm = {};
    std::istringstream ss(nextPeriod);
    ss >> std::get_time(&nextTm, "%Y-%m-%d");
    if (ss.fail()) {
        return -1;
    }

    std::time_t nextTime = std::mktime(&nextTm);
    std::time_t now = std::time(nullptr);


    double diff = std::difftime(nextTime, now);
    return static_cast<int>(diff / (60 * 60 * 24));
}