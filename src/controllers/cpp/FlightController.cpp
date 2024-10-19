//
// Created by User on 16.08.2024.
//

#include "../headers/FlightController.h"

FlightController::FlightController() {

}

std::future<std::string> FlightController::List() {
    return std::async(std::launch::async, []() -> std::string {

    });
}

std::future<std::string> FlightController::Create(FlightModel model) {
    return std::async(std::launch::async, [this, model]() -> std::string {
       flights.push_back(model);

       FlightModel::saveDataToFile(model, "flight_data_" + std::to_string(model.getFlightNumber()) + ".txt");
    });
}

std::future<std::string> FlightController::Upload() {
    return  std::async(std::launch::async, [this]() -> std::string {
        std::filesystem::path directoryPath = std::filesystem::current_path() / "info";
        if (!std::filesystem::exists(directoryPath)) {
            return "Directory does not exist.";
        }

        for (const auto& entry : std::filesystem::directory_iterator(directoryPath)) {
            if (entry.is_block_file()) {
                std::string filePath = entry.path().string();
                FlightModel flight = FlightModel::fromFile(filePath);
                flights.push_back(flight);
            }
        }
    });
}
