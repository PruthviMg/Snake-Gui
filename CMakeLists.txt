cmake_minimum_required(VERSION 3.1)

project(Game)

set(CMAKE_CXX_FLAGS "-std=c++0x -g -pthread")

find_package(PkgConfig)

INCLUDE_DIRECTORIES(
	${CMAKE_SOURCE_DIR}/inc/
	${CMAKE_SOURCE_DIR}/api/
	${CMAKE_SOURCE_DIR}/image/
	/usr/include/
)


set(LIBS
)


file(GLOB_RECURSE ${PROJECT_NAME}_SOURCE_FILES
	test.cpp /	
    ${CMAKE_SOURCE_DIR}/src/*.cpp
)	

add_executable(Game ${${PROJECT_NAME}_SOURCE_FILES})
target_link_libraries(Game ${LIBS} -lsfml-graphics -lsfml-window -lsfml-system)