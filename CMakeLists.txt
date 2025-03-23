cmake_minimum_required(VERSION 3.29)
project(leet)

set(CMAKE_CXX_STANDARD 20)

include_directories(.)

set(TARGET 0010/0001.h)
add_definitions(-DTARGET=\"${TARGET}\")

add_executable(1
        ${TARGET}
        util.h
        run.cc
)
