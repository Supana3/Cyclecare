#ifndef MOODLOG_H
#define MOODLOG_H

#include <string>

/**
 * MoodLog represents one daily mood entry: a date, a mood level (1–5),
 * and an optional free-text note.
 */
class MoodLog {
private:
    std::string date;   // YYYY-MM-DD
    int moodLevel;      // 1 (low) to 5 (great)
    std::string note;

public:
    // Constructors
    MoodLog();
    MoodLog(const std::string& date, int moodLevel);
    MoodLog(const std::string& date, int moodLevel, const std::string& note);

    // Getters
    std::string getDate() const;
    int getMoodLevel() const;
    std::string getNote() const;

    // Setters
    void setMoodLevel(int level);
    void setNote(const std::string& note);

    // Core functionality
    void display() const;
    std::string toFileLine() const;                       // Serialize for saving
    static MoodLog fromFileLine(const std::string& line); // Deserialize
};

#endif // MOODLOG_H