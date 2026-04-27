cmake_minimum_required(VERSION 3.10)
project(CycleCare)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED True)

# Enable testing
enable_testing()

# Create main executable
add_execut.able(cyclecare src/main.cpp)
# target_link_libraries(cyclecare cyclecare_lib)

# Create test executable
# add_executable(tests tests/test_main.cpp)
# target_link_libraries(tests cyclecare_lib)

# Register tests with CTest
# add_test(NAME CycleCareTests COMMAND tests).
