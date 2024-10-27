//
// Created by User on 16.08.2024.
//

#include <regex>
#include "../headers/FlightController.h"

FlightController::FlightController() {
    infoPath = std::filesystem::current_path().parent_path() / "info";
    Upload();
}

std::future<void> FlightController::List() {
    return std::async(std::launch::async, [this]()  {
        try {
            for (const auto& [number, flight] : flights) {
                std::cout << FlightModel::getFlight(flight) << std::endl << std::endl;
            }
        } catch (const std::exception& ex) {
            std::cerr << "Error listing flights: " << ex.what() << std::endl;
        } catch (...) {
            std::cerr << "Unknown error occurred while listing flights." << std::endl;
        }
    });
}

std::future<std::string> FlightController::CreateOrUpdate(const FlightModel& model) {
    return std::async(std::launch::async, [this, model]() -> std::string {
        try {
            flights[model.getFlightNumber()] = model; // Додати або оновити рейс
            FlightModel::saveDataToFile(model, "flight_data_" + std::to_string(model.getFlightNumber()) + ".txt");

            if (flights.find(model.getFlightNumber()) != flights.end()) {
                return "Info: Existing flight was changed.";
            } else {
                return "Info: New flight was created.";
            }
        } catch (const std::exception& ex) {
            return "Error creating or updating flight: " + std::string(ex.what());
        } catch (...) {
            return "Error: Unknown error occurred while creating or updating flight.";
        }
    });
}

std::future<std::string> FlightController::Upload() {
    return std::async(std::launch::async, [this]() -> std::string {
        try {
            if (!std::filesystem::exists(infoPath)) {
                return "Error: Folder 'info' does not exist.";
            }

            for (const auto& entry : std::filesystem::directory_iterator(infoPath)) {
                if (entry.is_regular_file()) {
                    FlightModel flight = FlightModel::fromFile(entry.path());
                    flights[flight.getFlightNumber()] = flight;
                }
            }

            return "Info: Data about flights was uploaded from file.";
        } catch (const std::exception& ex) {
            return "Error uploading flight data: " + std::string(ex.what());
        } catch (...) {
            return "Error: Unknown error occurred while uploading flight data.";
        }
    });
}

std::future<std::string> FlightController::Delete(int flightNumber) {
    return std::async(std::launch::async, [this, flightNumber]() -> std::string {
        try {
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
        } catch (const std::exception& ex) {
            return "Error deleting flight: " + std::string(ex.what());
        } catch (...) {
            return "Error: Unknown error occurred while deleting flight.";
        }
    });
}

std::future<std::vector<FlightModel>> FlightController::Sort(const std::string &key) {
    return std::async(std::launch::async, [this, key]() -> std::vector<FlightModel> {
        std::vector<FlightModel> sortedFlights;
        sortedFlights.reserve(flights.size());

        for (const auto& [_, flight] : flights) {
            sortedFlights.push_back(flight);
        }

        if (key == "flightNumber") {
            std::sort(sortedFlights.begin(), sortedFlights.end(), [](const FlightModel& a, const FlightModel& b) {
                return a.getFlightNumber() < b.getFlightNumber();
            });
        } else if (key == "whither") {
            std::sort(sortedFlights.begin(), sortedFlights.end(), [](const FlightModel& a, const FlightModel& b) {
                return a.getWhither().toString() < b.getWhither().toString();
            });
        } else if (key == "availableSeats") {
            std::sort(sortedFlights.begin(), sortedFlights.end(), [](const FlightModel& a, const FlightModel& b) {
                return a.getAvailableSeats() < b.getAvailableSeats();
            });
        }
        return sortedFlights;
    });
}
