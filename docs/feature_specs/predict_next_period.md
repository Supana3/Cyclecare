# Predict Next Period - Spec

## Problem statement
User can see their next predicted period date based on their last period and cycle length.

## Types involved
- Cycle (reads lastPeriodDate, cyclelength)
- CycleCareApp (calls the predict method)

## Public interface
- std::string Cycle::predictNextPeriod() const;
- int Cycle::daysUntilNextPeriod() const;

## Inputs and outputs
- Input: user picks "Show Next PEriod Prediction" from menu
- Output: predicted date as YYY-MM-DD, or "no period logged yet"

## Edge Cases
- No period logged yet
- Cycle length zero or negative 
- Month rollover (Jan 25 + 28 + Feb 22)
- Year rollover (Dec 20 + 28 = Jan 17 next year)

## Three tests
- Normal; log 2026-01-01, cycle 28, returns "2026-01-29"
- Edge: no period logged, returns ""
- Boundary: log 2026-12-20, cycle 28, returns "2027-01-17"

## Design decisions
- Use chrono for date math, handles, leap years
- Return empty string for "no data" instead of throwing