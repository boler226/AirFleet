//
// Created by User on 16.08.2024.
//

#ifndef AIRFLEET_FLIGHTCONTROLLER_H
#define AIRFLEET_FLIGHTCONTROLLER_H

#include "../../models/headers/FlightModel.h"
#include <future>
#include <vector>
#include <memory>
#include <map>


class FlightController {
private:
    std::map<int, FlightModel> flights;
    std::filesystem::path infoPath;
public:
    FlightController();

    std::future<void> List();
    std::future<std::string> CreateOrUpdate(const FlightModel& model);
    std::future<std::string> Delete(int flightNumber);
    std::future<std::vector<FlightModel>> Sort(const std::string& key);

    std::future<std::string> Upload();
};


#endif //AIRFLEET_FLIGHTCONTROLLER_H
