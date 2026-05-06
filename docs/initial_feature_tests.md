 # Initial Feature Test Cases

 ## Feature: Log Period

 The Log Period features lets the user record their last period start date along with their average cycle length and period length.

 ### Test 1: Normal Operation 
 - What it tests: Logging a period with valid date and lengths stores all values correctly.
 - Expected result: getLastPeriodDate returns the date, getCycleLength return 28, getPeriodLength return 5.
 - Result: Pass

 ### Test 2: Edge Case
 - What it tests: Default constructed Cycle has sensible defaults.
 - Expected results: getLastPeriodDate returns empty, getCycleLength return 28, getPeriodLength return 5.
 - Result: Pass

 ### Test 3: Boundary Condition
 - What it tests: setCycleLength and setPeriodLength reject zero and negative values.
 - Expected result: After trying invalid values, cycle length stays at 28 and period length stays at 5.
 - Result: Pass

 ###CTest Output

 1: Running tests...
 1: Test 1: Normal operation... PASSED
 1: Test 2: Edge case (default constructor)... PASSED
 1: Test 3: Boundary condition (invalid length rejected)... PASSED
 1: All tests passed.
 1/1 Test #1: CycleCareTests ... Passed 0.09 sec

 100% tests passed, 0 tests failed out of 1