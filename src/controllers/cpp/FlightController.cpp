//
// Created by User on 16.08.2024.
//

#include <regex>
#include "../headers/FlightController.h"

FlightController::FlightController() {
    Upload();
}

std::future<void> FlightController::List() {
    return std::async(std::launch::async, [this]() {
        for (auto& flight : flights) {
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
        std::filesystem::path folderPath = std::filesystem::current_path().parent_path() / "info";

        std::string result;

        if (!std::filesystem::exists(folderPath)) {
            return "Error: Folder 'info' does not exist.";
        }

        std::vector<std::future<std::string>> results;

        for (const auto& entry : std::filesystem::directory_iterator(folderPath)) {
            if (entry.is_regular_file()) {
                flights.push_back(FlightModel::fromFile(entry.path()));
            }
        }

        return "Info: Data about flight's was uploaded from file.";
    });
}
