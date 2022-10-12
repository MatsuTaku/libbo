cmake_minimum_required(VERSION 3.14)

# Source of a documentation of GoogleTest Quickstart: CMake (https://google.github.io/googletest/quickstart-cmake.html)
include(FetchContent)
FetchContent_Declare(
  googletest
  GIT_REPOSITORY https://github.com/google/googletest.git
  GIT_TAG release-1.12.1
)
# For Windows: Prevent overriding the parent project's compiler/linker settings
set(gtest_force_shared_crt ON CACHE BOOL "" FORCE)
FetchContent_MakeAvailable(googletest)


include(GoogleTest)
file(GLOB TEST_SOURCES src/*_test.cpp)
foreach(TEST_SOURCE ${TEST_SOURCES})
  get_filename_component(TEST_SOURCE_NAME ${TEST_SOURCE} NAME_WE)

  add_executable(${TEST_SOURCE_NAME} ${TEST_SOURCE})
  target_link_libraries(${TEST_SOURCE_NAME} GTest::gtest_main libbo)
  target_compile_options(${TEST_SOURCE_NAME} PRIVATE -O3 -Wall)
  # add_test(NAME ${TEST_SOURCE_NAME} COMMAND ${TEST_SOURCE_NAME})
  gtest_discover_tests(${TEST_SOURCE_NAME})

  add_executable(${TEST_SOURCE_NAME}_builtin ${TEST_SOURCE})
  target_link_libraries(${TEST_SOURCE_NAME}_builtin GTest::gtest_main libbo)
  target_compile_options(${TEST_SOURCE_NAME}_builtin PRIVATE -march=native -O3 -Wall)
  # add_test(NAME ${TEST_SOURCE_NAME}_builtin COMMAND ${TEST_SOURCE_NAME}_builtin)
  gtest_discover_tests(${TEST_SOURCE_NAME}_builtin)
endforeach()


