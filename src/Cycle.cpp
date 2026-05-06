#include "Cycle.h"
#include <iostream>

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
    return ""; 
}

std::string Cycle::getCurrentPhase() const {
    return "";  
}

int Cycle::daysUntilNextPeriod() const {
    return 0; 
}