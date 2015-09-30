cmake_minimum_required(VERSION 3.3.2)
project (epanet-cmake)

# Include files
INCLUDE_DIRECTORIES(../EPANET/include include)

# Source files
file(GLOB SOURCES "src/*.cpp")
file(GLOB EPANET "../EPANET/src/*.c")

add_executable(epanet-cmake ${SOURCES} ${EPANET})
