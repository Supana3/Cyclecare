# CycleCare

A C++ command-line program that tracks menstrual cycles, logs mood, and gives personalized food and wellness recommendations based on cycle phase.

##Implemented and working:
Log Period — captures last period date, cycle length, and period length
Predict Next Period — predicts the next period date from the logged period and cycle length, with proper date math (including year rollover)
Log Mood — records a daily mood entry with date, mood level (1–5), and an optional note; entries are kept in memory for the session

Stubbed (declared and compile cleanly, but not implemented):
Show Food Tips — phase-based food recommendations
Show Cramp Relief Tips — cramp relief and self-care suggestions
Change Theme — ANSI color theming based on cycle phase and mood
File save/load — persistence between runs (this is the biggest gap; nothing is saved when the program exits)

##Building
"Requires CMake 3.x" and a C++20-capable compiler.
    cmake -S . -B build
    cmake --build build

## Running
    ./build/cyclecare.exe

## Running Tests
    ctest --test-dir build --output-on-failure

All 8 tests should pass.

## Known Limitations
- No persistence - data is lost when the program exits
- Food, cramp, and theme actions are stubs

## Author
Sapana Dhakal - CIS 25 Practice Project