//
// Created by User on 16.08.2024.
//

#include "../headers/FlightController.h"

FlightController::FlightController() {

}

std::future<std::string> FlightController::Upload() {

}

std::future<std::string> FlightController::Create(FlightModel model) {
    return std::async(std::launch::async, [this, model]() -> std::string {
       flights.push_back(model);

       FlightModel::saveDataToFile(model, "flight_data_" + std::to_string(model.getFlightNumber()) + ".txt");
    });
}
