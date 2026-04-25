# Implementation Plan

## Feature 1: Track Period Start/End Dates and Cycle Length
**Trigger**: User selects "Log period" from main menu
Prompts the user for the period start date (YYYY-MM-DD) and optionally period length in days. Updates the Cycle object's lastPeriodDate and periodLength, recalculates currentDayOfCycle, and confirms the entry. This data feeds phase detection and prediction.

## Feature 2: Predict Next Period Date
**Trigger**: User selects "Predict next period" from main menu
Reads the stored lastPeriodDate and cycleLength from the Cycle object, adds cycleLength days to lastPeriodDate using a date arithmetic helper, and displays the predicted date plus the number of days remaining.

## Feature 3: Mood Logging for Each Day
**Trigger**: User selects "Log today's mood" from main menu
Prompts the user for a mood level (1–5) and an optional note. Creates a MoodLog object with today's date and appends it to the moodHistory vector in CycleCareApp. Displays a confirmation.

## Feature 4: Daily Food Recommendations
**Trigger**: User selects "Show food tips" from main menu
Calls Cycle.getCurrentPhase() to determine the current phase, passes it to Recommendation.getFoodTips(phase), and prints the returned list of foods to eat and avoid for that phase.

## Feature 5: Cramp Relief Tips and Self-Care Suggestions
**Trigger**: User selects "Show cramp/self-care tips" from main menu
Calls Recommendation.getCrampTips() for general cramp relief, and Recommendation.getSelfCareTips(moodLevel) using the most recent MoodLog entry. Displays both lists in a formatted block.

## Feature 6: Change App Theme Based on Phase and Mood
**Trigger**: Automatic on program start and after any log action; also manual via "Change theme" menu option
CycleCareApp.applyTheme() reads the current cycle phase and most recent mood level, then emits ANSI escape codes (e.g. \033[31m for red) to color console output. User can override with themePreference on the User object ("warm", "cool", "mono", "auto").

## Feature 7: Save/Load Data to File
**Trigger**: Program startup (load) and program exit or "Save and quit" menu choice (save)
On startup, loadFromFile() reads cyclecare_data.txt line by line — first lines hold User and Cycle fields, remaining lines are serialized MoodLog entries parsed via MoodLog::fromFileLine. On exit, saveToFile() writes all data back in the same format so state persists between runs.