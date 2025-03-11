cmake_minimum_required(VERSION 3.14)
project(ThreadExample CXX)

set(CMAKE_CXX_STANDARD 14)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# Подключение Google Test
include(FetchContent)
FetchContent_Declare(
  googletest
  URL https://github.com/google/googletest/archive/03597a01ee50ed33e9dfd640b249b4be3799d395.zip
)
set(gtest_force_shared_crt ON CACHE BOOL "" FORCE)
FetchContent_MakeAvailable(googletest)

add_executable(Main14 src/main14.cpp)
target_include_directories(Main14 PRIVATE ${CMAKE_CURRENT_SOURCE_DIR}/src)

enable_testing()
add_executable(Test14 tests/test14.cpp)
target_include_directories(Test14 PRIVATE ${CMAKE_CURRENT_SOURCE_DIR}/tests)
target_link_libraries(Test14 gtest_main)





set(CMAKE_CXX_STANDARD 98)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# Подключение Google Test
include(FetchContent)
FetchContent_Declare(
  googletest
  URL https://github.com/google/googletest/archive/03597a01ee50ed33e9dfd640b249b4be3799d395.zip
)
set(gtest_force_shared_crt ON CACHE BOOL "" FORCE)
FetchContent_MakeAvailable(googletest)

add_executable(Main98 src/main98.cpp)
target_include_directories(Main98 PRIVATE ${CMAKE_CURRENT_SOURCE_DIR}/src)

enable_testing()
add_executable(Test98 tests/test98.cpp)
target_include_directories(Test98 PRIVATE ${CMAKE_CURRENT_SOURCE_DIR}/tests)
target_link_libraries(Test98 gtest_main)

add_test(NAME Test14 COMMAND Test14)
add_test(NAME Test98 COMMAND Test98)