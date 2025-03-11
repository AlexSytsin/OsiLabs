cmake_minimum_required(VERSION 3.14) 
project(Lab1 CXX)

set(CMAKE_CXX_STANDARD 14)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_executable(Main Main/main.cpp)
target_include_directories(Main 
	PRIVATE 
		${CMAKE_CURRENT_SOURCE_DIR}/data
)

add_executable(Creator Creator/Creator.cpp)
target_include_directories(Creator 
	PRIVATE 
		${CMAKE_CURRENT_SOURCE_DIR}/data
)

add_executable(Reporter Reporter/Reporter.cpp)
target_include_directories(Reporter 
	PRIVATE 
		${CMAKE_CURRENT_SOURCE_DIR}/data
)
