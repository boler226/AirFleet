//
// Created by User on 16.08.2024.
//

#ifndef AIRFLEET_FLIGHTCONTROLLER_H
#define AIRFLEET_FLIGHTCONTROLLER_H

#include "../../models/headers/FlightModel.h"
#include <future>
#include <vector>


class FlightController {
private:
    std::vector<FlightModel> flights;
public:
    FlightController();
    FlightController(std::vector<FlightModel> flights);


    std::future<std::string> List();
    std::future<std::string> Create(FlightModel model);
    std::future<std::string> Update(FlightModel model);
    std::future<std::string> Delete(int flightNumber);

    std::future<std::string> Upload();
};


#endif //AIRFLEET_FLIGHTCONTROLLER_H
