cmake_minimum_required(VERSION 3.10)

project(ap4a-project)

# specify the C++ standard
set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED True)

find_package(Threads REQUIRED)

set(SRC_FILES
	src/main.cpp
	src/Humidity.cpp
    src/InputCheck.cpp
    src/Light.cpp
    src/Pression.cpp
    src/Scheduler.cpp
    src/Server.cpp
    src/Temperature.cpp


)

set(HEADER_FILES
	src/Humidity.hpp
    src/InputCheck.hpp
    src/Light.hpp
    src/Pression.hpp
    src/Scheduler.hpp
    src/Server.hpp
    src/Temperature.hpp
)

add_executable(ap4a-project ${SRC_FILES} ${HEADER_FILES})


target_link_libraries(ap4a-project Threads::Threads)