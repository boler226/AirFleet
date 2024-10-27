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

std::future<std::string> FlightController::CreateOrUpdate(const FlightModel& model) {
    return std::async(std::launch::async, [this, model]() -> std::string {
        flights[model.getFlightNumber()] = model; // Додати або оновити рейс
        FlightModel::saveDataToFile(model, "flight_data_" + std::to_string(model.getFlightNumber()) + ".txt");
        if (flights.find(model.getFlightNumber()) != flights.end()) {
            return "Info: Exist flight was changed.";
        } else {
            return "Info: New flight was created.";
        }
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

std::future<std::string> FlightController::Delete(int flightNumber) {
    return std::async(std::launch::async, [this, flightNumber]() ->std::string {
        if (!std::filesystem::exists(infoPath)) {
            return "Error: Folder 'info' does not exist.";
        }

        std::string fileName = "flight_data_" + std::to_string(flightNumber) + ".txt";
        std::filesystem::path filePath = infoPath / fileName;

        if (std::filesystem::exists(filePath)) {
            std::filesystem::remove(filePath);

            auto it = flights.find(flightNumber);
            if (it != flights.end()) {
                flights.erase(it);
            }
            return "Info: File " + fileName + " deleted successfully.";
        } else {
            return "Error: File " + fileName + " does not exist.";
        }
    });
}
