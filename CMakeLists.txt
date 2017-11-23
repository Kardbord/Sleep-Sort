cmake_minimum_required (VERSION 2.4)
project (Sleep-Sort)

if (CMAKE_COMPILER_IS_GNUCXX)
    set (CMAKE_CXX_FLAGS "-std=c++11 -pthread -g -Wl,--no-as-needed ${CMAKE_CXX_FLAGS}")
endif()

add_executable(Sleep-Sort
    main.cpp
    SyncedVec.hpp
)
