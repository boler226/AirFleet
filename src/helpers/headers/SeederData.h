//
// Created by User on 06.09.2024.
//

#ifndef AIRFLEET_SEEDERDATA_H
#define AIRFLEET_SEEDERDATA_H

#include <future>
#include "../../controllers/headers/FlightController.h"

class SeederData {
private:
    FlightController flightController;
public:
    SeederData();

    std::future<std::string> SeedData();
};

#endif //AIRFLEET_SEEDERDATA_H
