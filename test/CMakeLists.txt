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

include(CheckCXXCompilerFlag)
CHECK_CXX_COMPILER_FLAG("-march=native" COMPILER_SUPPORTS_MARCH)
CHECK_CXX_COMPILER_FLAG("-mcpu=native" COMPILER_SUPPORTS_MCPU)
if(COMPILER_SUPPORTS_MARCH)
  set(NATIVE_OPTION "-march=native")
elseif(COMPILER_SUPPORTS_MCPU)
  set(NATIVE_OPTION "-mcpu=native")
endif()

set(CMAKE_CXX_FLAGS_DEBUG "${CMAKE_CXX_FLAGS_DEBUG} -Wall")

include(GoogleTest)
file(GLOB TEST_SOURCES src/*_test.cpp)
foreach(TEST_SOURCE ${TEST_SOURCES})
  get_filename_component(TEST_NAME ${TEST_SOURCE} NAME_WE)

  add_executable(${TEST_NAME} ${TEST_SOURCE})
  target_link_libraries(${TEST_NAME} GTest::gtest_main libbo)
  gtest_discover_tests(${TEST_NAME})

  set(TEST_INTRIN_NAME ${TEST_NAME}_intrin)
  add_executable(${TEST_INTRIN_NAME} ${TEST_SOURCE})
  target_link_libraries(${TEST_INTRIN_NAME} GTest::gtest_main libbo)
  target_compile_options(${TEST_INTRIN_NAME} PRIVATE ${NATIVE_OPTION})
  target_compile_definitions(${TEST_INTRIN_NAME} PRIVATE BO_INTRINSIC_ENABLED)
  gtest_discover_tests(${TEST_INTRIN_NAME})
endforeach()


