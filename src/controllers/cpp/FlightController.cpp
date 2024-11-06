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
            std::cerr << "Помилка списку рейсів: " << ex.what() << std::endl;
        } catch (...) {
            std::cerr << "Під час створення списку рейсів сталася невідома помилка." << std::endl;
        }
    });
}

std::future<std::string> FlightController::CreateOrUpdate(const FlightModel& model) {
    return std::async(std::launch::async, [this, model]() -> std::string {
        try {
            flights[model.getFlightNumber()] = model; // Додати або оновити рейс
            FlightModel::saveDataToFile(model, "flight_data_" + std::to_string(model.getFlightNumber()) + ".txt");

            if (flights.find(model.getFlightNumber()) != flights.end()) {
                return "Інформація: існуючий рейс змінено.";
            } else {
                return "Інформація: Створено новий рейс.";
            }
        } catch (const std::exception& ex) {
            return "Помилка створення або оновлення рейсу: " + std::string(ex.what());
        } catch (...) {
            return "Помилка: під час створення або оновлення рейсу сталася невідома помилка.";
        }
    });
}

std::future<std::string> FlightController::Upload() {
    return std::async(std::launch::async, [this]() -> std::string {
        try {
            if (!std::filesystem::exists(infoPath)) {
                return "Помилка: папка \"info\" не існує.";
            }

            for (const auto& entry : std::filesystem::directory_iterator(infoPath)) {
                if (entry.is_regular_file()) {
                    FlightModel flight = FlightModel::fromFile(entry.path());
                    flights[flight.getFlightNumber()] = flight;
                }
            }

            return "Інформація: дані про рейси вивантажено з файлу.";
        } catch (const std::exception& ex) {
            return "Помилка завантаження даних рейсу: " + std::string(ex.what());
        } catch (...) {
            return "Помилка: під час завантаження даних польоту сталася невідома помилка.";
        }
    });
}

std::future<std::string> FlightController::Delete(int flightNumber) {
    return std::async(std::launch::async, [this, flightNumber]() -> std::string {
        try {
            if (!std::filesystem::exists(infoPath)) {
                return "Помилка: папка \"info\" не існує.";
            }

            std::string fileName = "flight_data_" + std::to_string(flightNumber) + ".txt";
            std::filesystem::path filePath = infoPath / fileName;

            if (std::filesystem::exists(filePath)) {
                std::filesystem::remove(filePath);

                auto it = flights.find(flightNumber);
                if (it != flights.end()) {
                    flights.erase(it);
                }
                return "Інформація: файл " + fileName + " успішно видалено.";
            } else {
                return "Помилка: файл " + fileName + " не існує.";
            }
        } catch (const std::exception& ex) {
            return "Помилка видалення рейсу: " + std::string(ex.what());
        } catch (...) {
            return "Помилка: під час видалення рейсу сталася невідома помилка.";
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

std::future<std::vector<FlightModel>> FlightController::Filter(int minSeats, int maxSeats) {
    return std::async(std::launch::async, [this, minSeats, maxSeats]() -> std::vector<FlightModel> {
        std::vector<FlightModel> filteredFlights;
        for (const auto& [_, flight] : flights) {
            if (flight.getAvailableSeats() >= minSeats && flight.getAvailableSeats() <= maxSeats) {
                filteredFlights.push_back(flight);
            }
        }
        return filteredFlights;
    });
}

std::future<std::optional<FlightModel>> FlightController::FindByNumber(int flightNumber) {
    return std::async(std::launch::async, [this, flightNumber]() -> std::optional<FlightModel> {
        auto it = flights.find(flightNumber);
        if (it != flights.end()) {
            return it->second;
        }
        return std::nullopt;
    });
}