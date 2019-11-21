cmake_minimum_required(VERSION 3.15)
project(DataBase)

set(CMAKE_CXX_STANDARD 14)

add_executable(DataBase model/main.cpp model/Doctor.cpp model/Doctor.h model/Person.cpp model/Person.h model/Patient.cpp model/Patient.h Database.cpp Database.h)