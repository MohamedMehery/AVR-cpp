cmake_minimum_required(VERSION 3.20.5)
#must add winavr and winavr/util to path variables, winavr/util it has linux commands to run on windows
set(CMAKE_SYSTEM_NAME Generic)  #means it will not run on pc.
set(CMAKE_CXX_COMPILER avr-g++ CACHE STRING "C++ compiler" FORCE)
set(CMAKE_C_COMPILER avr-gcc CACHE STRING "C compiler" FORCE)
set(CMAKE_OBJCOPY avr-objcopy CACHE STRING "avr objcopy" FORCE) #formlization the output to .hex to be burnt

#CMAKE_CXX_FLAGS is built in variable must written proberly
set(CMAKE_CXX_FLAGS "-mmcu=atmega32 -O1 -DF_CPU=1000000UL")#compiler take the flags to substitute to run
##############################################################################################
project(AVRCPP CXX) 

# file(GLOB_RECURSE SRCS RELATIVE ${CMAKE_CURRENT_BINARY_DIR} *.cpp *.hpp)
# #   message(${SRCS})
# string(REGEX REPLACE "build/[^;]+;?" "" SRCS "${SRCS}")
set(SRCS ./src/main.cpp
        ./src/led.cpp)
message("${SRCS}")
##############################################################################################
set(CMAKE_PREFIX_PATH "C:/Users/Mohamed Mehery/Downloads/Compressed/googletest/build")
add_executable(${PROJECT_NAME}.elf ${SRCS})
target_include_directories(${PROJECT_NAME}.elf PUBLIC hdr/)
target_link_libraries(${PROJECT_NAME}.elf PRIVATE gtest)
target_link_libraries(${PROJECT_NAME}.elf PRIVATE gtest_main)

#fromating
message("${FLASH_FLAGS}")
add_custom_target(flash ALL     #add flash target to overall target
                DEPENDS ${PROJECT_NAME}.elf
                COMMAND avr-objcopy -j .text -j .data -O ihex ${PROJECT_NAME}.elf ${PROJECT_NAME}.hex)       

