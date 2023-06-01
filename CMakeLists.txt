#Mark Hentges 5814125

cmake_minimum_required(VERSION 3.24)
project(project7)

set(CMAKE_CXX_STANDARD 17)

add_executable(project7 main.cpp PrecondViolatedExcep.cpp NotFoundException.cpp)
