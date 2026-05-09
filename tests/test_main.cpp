#include <iostream>
#include <cassert>
#include <string>
#include "../src/Cycle.h"


void test_log_period_normal() {
    std::cout << "Test 1: Normal operation...";
    Cycle c;
    c.logPeriod("2026-05-05");
    c.setCycleLength(28);
    c.setPeriodLength(5);
    assert(c.getLastPeriodDate() == "2026-05-05");
    assert(c.getCycleLength() == 28);
    assert(c.getPeriodLength() == 5);
    std::cout << " PASSED" << std::endl;
}

void test_log_period_default_constructor() {
    std::cout << "Test 2: Edge case - (default constructor)...";
    Cycle c;
    assert(c.getLastPeriodDate() == "");
    assert(c.getCycleLength() == 28);
    assert(c.getPeriodLength() == 5);
    std::cout << " PASSED" << std::endl;
}

void test_log_period_invalid_length_rejected() {
    std::cout << "Test 3: Boundary condition (invalid lengths rejected)...";
    Cycle c;
    c.setCycleLength(28);
    c.setPeriodLength(5);
    c.setCycleLength(0);
    c.setPeriodLength(-10);
    c.setCycleLength(0);
    c.setPeriodLength(-3);
    assert(c.getCycleLength() == 28);
    assert(c.getPeriodLength() == 5);
    std::cout << " PASSED" << std::endl;
}

void test_predict_next_period_normal() {
    std::cout << "Test 4: Predict next period normal...";
    Cycle c;
    c.logPeriod("2026-01-01");
    c.setCycleLength(28);
    assert(c.predictNextPeriod() == "2026-01-29");
    std::cout << " PASSED" << std::endl;
}

void test_predict_next_period_no_log() {
    std::cout << "Test 5: Predict next period with no log...";
    Cycle c;
    assert(c.predictNextPeriod() == "");
    std::cout << " PASSED" << std::endl;
}

void test_predict_next_period_year_rollover() {
    std::cout << "Test 6: Predict next period with year rollover...";
    Cycle c;
    c.logPeriod("2026-12-20");
    c.setCycleLength(28);
    assert(c.predictNextPeriod() == "2027-01-17");
    std::cout << " PASSED" << std::endl;
}

int main() {
    std::cout << "Running tests..." << std::endl;
    test_log_period_normal();
        test_log_period_default_constructor();
        test_log_period_invalid_length_rejected();
        test_predict_next_period_normal();
        test_predict_next_period_no_log();
        test_predict_next_period_year_rollover();
        std::cout << "\nAll tests passed." << std::endl;
        return 0;
}