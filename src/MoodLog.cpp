#include "MoodLog.h"
#include <iostream>

MoodLog::MoodLog() {
    date = "";
    moodLevel = 0;
    note = "";
}

MoodLog::MoodLog(const std::string& logDate, int level) {
    (void)logDate;
    (void)level;
    date = "";
    moodLevel = 0;
    note = "";
    std::cout << "[MoodLog::MoodLog(params)] not yet implemented\n";
}

MoodLog::MoodLog(const std::string& logDate, int level, const std::string& logNote) {
    (void)logDate;
    (void)level;
    (void)logNote;
    date = "";
    moodLevel = 0;
    note = "";
    std::cout << "[MoodLog::MoodLog(params+note)] not yet implemented\n";
}

std::string MoodLog::getDate() const {
    return "";
}

int MoodLog::getMoodLevel() const {
    return 0;
}

std::string MoodLog::getNote() const {
    return "";
}

void MoodLog::setMoodLevel(int level) {
    (void)level;
    std::cout << "[MoodLog::setMoodLevel] not yet implemented\n";
}

void MoodLog::setNote(const std::string& logNote) {
    (void)logNote;
    std::cout << "[MoodLog::setNote] not yet implemented\n";
}

void MoodLog::display() const {
    std::cout << "[MoodLog::display] not yet implemented\n";
}

std::string MoodLog::toFileLine() const {
    return ""; 
}

MoodLog MoodLog::fromFileLine(const std::string& line) {
    (void)line;
    std::cout << "[MoodLog::fromFileLine] not yet implemented\n";
    return MoodLog(); 
}