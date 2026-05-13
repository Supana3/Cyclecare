#include "MoodLog.h"
#include <iostream>

// Default constructor — empty/zeroed values, used as a placeholder
MoodLog::MoodLog() {
    date = "";
    moodLevel = 0;
    note = "";
}

// Two-arg constructor — date + mood level, note left empty
MoodLog::MoodLog(const std::string& logDate, int level) {
    date = logDate;
    moodLevel = level;
    note = "";
}

// Three-arg constructor — date + mood level + free-text note
MoodLog::MoodLog(const std::string& logDate, int level, const std::string& logNote) {
    date = logDate;
    moodLevel = level;
    note = logNote;
}

// Getters
std::string MoodLog::getDate() const {
    return date;
}

int MoodLog::getMoodLevel() const {
    return moodLevel;
}

std::string MoodLog::getNote() const {
    return note;
}

// Setters — moodLevel is clamped to the valid 1-5 range; invalid input is ignored
void MoodLog::setMoodLevel(int level) {
    if (level >= 1 && level <= 5) {
        moodLevel = level;
    }
}

void MoodLog::setNote(const std::string& logNote) {
    note = logNote;
}

// Print a human-readable representation of this mood entry
void MoodLog::display() const {
    std::cout << "  [" << date << "] Mood: " << moodLevel << "/5";
    if (!note.empty()) {
        std::cout << " - " << note;
    }
    std::cout << std::endl;
}

// File persistence — stubbed for now, will be implemented when
// the File save/load feature is added.
std::string MoodLog::toFileLine() const {
    return "";
}

MoodLog MoodLog::fromFileLine(const std::string& line) {
    (void)line;
    return MoodLog();
}
