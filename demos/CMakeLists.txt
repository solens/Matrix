project(malos_service C CXX)
cmake_minimum_required(VERSION 2.8)

add_definitions(-std=c++11)

find_package(Threads)
find_library (FFTW_LIBRARIES NAMES fftw3f )
FIND_LIBRARY(WIRINGPI_LIB NAMES wiringPi)
FIND_LIBRARY(WIRINGPI_DEV_LIB NAMES wiringPiDev)
FIND_LIBRARY(CRYPT_LIB NAMES crypt)
FIND_LIBRARY(GFLAGS_LIB NAMES gflags)
message(STATUS "gflags found =>" "${GFLAGS_LIB}") 

add_subdirectory(../cpp/driver driver)

add_executable(turn_lights_off turn_lights_off.cpp)
  set_property(TARGET turn_lights_off PROPERTY CXX_STANDARD 11)
  target_link_libraries(turn_lights_off matrix_creator_hal)
  target_link_libraries(turn_lights_off ${CMAKE_THREAD_LIBS_INIT})

add_executable(light_stuff light_stuff.cpp)
  set_property(TARGET light_stuff PROPERTY CXX_STANDARD 11)
  target_link_libraries(light_stuff matrix_creator_hal)
  target_link_libraries(light_stuff ${CMAKE_THREAD_LIBS_INIT})