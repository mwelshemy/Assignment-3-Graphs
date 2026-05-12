project(Google_tests)

# 1. Download a fresh, working version of Google Test
include(FetchContent)
FetchContent_Declare(
  googletest
  GIT_REPOSITORY https://github.com/google/googletest.git
  GIT_TAG        v1.14.0
)
# Force Windows to use the correct runtime library
set(gtest_force_shared_crt ON CACHE BOOL "" FORCE)
FetchContent_MakeAvailable(googletest)

# 2. Create your test runner
add_executable(Google_Tests_run Testcases.cpp)

# 3. Link your code and the fresh Google Test library
target_link_libraries(Google_Tests_run
        PRIVATE
        Code_library
        GTest::gtest_main
)