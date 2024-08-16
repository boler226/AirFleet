cmake_minimum_required(VERSION 3.27)
project(AirFleet)

set(CMAKE_CXX_STANDARD 17)

add_executable(AirFleet main.cpp
        src/models/cpp/FlightModel.cpp
        src/models/headers/FlightModel.h
        src/interfaces/Destination.cpp
        src/interfaces/Destination.h
        src/models/cpp/PlaneModel.cpp
        src/models/headers/PlaneModel.h
        src/models/cpp/TicketModel.cpp
        src/models/headers/TicketModel.h
        src/controllers/cpp/FlightController.cpp
        src/controllers/headers/FlightController.h)
