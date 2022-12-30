cmake_minimum_required(VERSION 3.19)

project(libbo)

set(CMAKE_CXX_STANDARD 17)

if (NOT CMAKE_BUILD_TYPE)
	set(CMAKE_BUILD_TYPE Release)
endif()

add_library(libbo INTERFACE)
target_include_directories(libbo INTERFACE include)

enable_testing()
add_subdirectory(test)

install(FILES include/bo.hpp DESTINATION include)
file(GLOB Libbo_HEADERS "include/bo/*.hpp")
install(FILES ${Libbo_HEADERS} DESTINATION include/bo)
