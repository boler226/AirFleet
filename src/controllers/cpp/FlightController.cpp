//
// Created by User on 16.08.2024.
//

#include <regex>
#include "../headers/FlightController.h"

FlightController::FlightController() {
    Upload();
    infoPath = std::filesystem::current_path().parent_path() / "info";
}

std::future<void> FlightController::List() {
    return std::async(std::launch::async, [this]() {
        for (const auto& [number, flight] : flights) {
            std::cout << FlightModel::getFlight(flight) << std::endl;
        }
    });
}

std::future<std::string> FlightController::Create(const FlightModel& model) {
    return std::async(std::launch::async, [this, model]() -> std::string {
       flights.push_back(model);

       FlightModel::saveDataToFile(model, "flight_data_" + std::to_string(model.getFlightNumber()) + ".txt");
        return "Info: New flight was created.";
    });
}

std::future<std::string> FlightController::Upload() {
    return std::async(std::launch::async, [this]() -> std::string {
        if (!std::filesystem::exists(infoPath)) {
            return "Error: Folder 'info' does not exist.";
        }

        for (const auto& entry : std::filesystem::directory_iterator(infoPath)) {
            if (entry.is_regular_file()) {
                FlightModel flight = FlightModel::fromFile(entry.path());
                flights[flight.getFlightNumber()] = flight;
            }
        }

        return "Info: Data about flight's was uploaded from file.";
    });
}
