cmake_minimum_required(VERSION 3.27)
project(AirFleet)

set(CMAKE_CXX_STANDARD 17)

add_executable(AirFleet main.cpp
        src/models/cpp/Flight.cpp
        src/models/headers/Flight.h
        src/interfaces/Destination.cpp
        src/interfaces/Destination.h
        src/models/cpp/Plane.cpp
        src/models/headers/Plane.h
        src/models/cpp/Ticket.cpp
        src/models/headers/Ticket.h)
