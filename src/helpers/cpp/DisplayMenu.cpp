//
// Created by User on 27.10.2024.
//

#include <iostream>
#include <future>
#include "../headers/DisplayMenu.h"
#include "../../controllers/headers/FlightController.h"

int DisplayMenu::getMenu() {
    int choice;
    FlightController controller;

    while (true) {
        std::cout << "\n--- Navigation Menu ---\n";
        std::cout << "1. List of flights\n";
        std::cout << "2. Flight search\n";
        std::cout << "3. Add or update\n";
        std::cout << "4. Delete flight\n";
        std::cout << "5. Sort flights\n";
        std::cout << "6. Filter flights by available seats\n";
        std::cout << "7. Exit\n";
        std::cout << "Select option: ";
        std::cin >> choice;

        if (std::cin.fail()) {
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); // Ігноруємо залишки у буфері
            std::cout << "Error: Invalid input. Please enter a valid integer.\n";
        } else {
            switch (choice) {
                case 1: {  // Відобразити список рейсів
                    try {
                        std::future<void> listFuture = controller.List();
                        listFuture.get();
                    } catch (const std::exception &e) {
                        std::cerr << "Error: " << e.what() << std::endl;
                    }
                    //1waitForUserInput();
                    break;
                }
                case 2: {  // Пошук рейсу за номером
                    int flightNumber;
                    std::cout << "Enter flight number: ";
                    std::cin >> flightNumber;

                    try {
                        std::future<std::optional<FlightModel>> findFuture = controller.FindByNumber(flightNumber);
                        std::optional<FlightModel> foundFlight = findFuture.get();

                        if (foundFlight.has_value()) {
                            FlightModel flight = foundFlight.value();
                            std::cout << "Flight found: \n" << FlightModel::formatData(flight) << std::endl;
                        } else {
                            std::cout << "Flight not found." << std::endl;
                        }
                    } catch (const std::exception &e) {
                        std::cerr << "Error: " << e.what() << std::endl;
                    }
                    break;
                }
                case 3: {  // Додати новий рейс
                    int flightNumber;
                    while (true) {
                        std::cout << "Enter the new flight number: ";
                        std::cin >> flightNumber;
                        if (std::cin.fail()) {
                            std::cin.clear(); // Очищаємо прапор помилки
                            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); // Пропускаємо некоректний ввід
                            std::cout << "Error: Please enter a valid integer for flight number.\n";
                        } else {
                            break; // Вийти з циклу, якщо ввід коректний
                        }
                    }

                    std::string whenceName, whitherName;
                    std::cout << "Enter departure destination: ";
                    std::cin >> whenceName;
                    std::cout << "Enter arrival destination: ";
                    std::cin >> whitherName;

                    Destination whence = Destination::fromString(whenceName);
                    Destination whither = Destination::fromString(whitherName);

                    std::vector<Destination> intermediateStops;
                    std::string stopName;
                    char addMore;

                    do {
                        std::cout << "Add an intermediate stop? (y/n): ";
                        std::cin >> addMore;
                        if (addMore == 'y' || addMore == 'Y') {
                            std::cout << "Enter intermediate stop name: ";
                            std::cin >> stopName;
                            intermediateStops.push_back(Destination::fromString(stopName));
                        }
                    } while (addMore == 'y' || addMore == 'Y');

                    std::time_t departureTime;
                    while (true) {
                        std::cout << "Enter departure time (epoch format: 1730061355): ";
                        std::cin >> departureTime;
                        if (std::cin.fail()) {
                            std::cin.clear();
                            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                            std::cout << "Error: Please enter a valid integer for departure time.\n";
                        } else {
                            break;
                        }
                    }

                    std::time_t flightDays;
                    while (true) {
                        std::cout << "Enter flight days (as an integer): ";
                        std::cin >> flightDays;
                        if (std::cin.fail()) {
                            std::cin.clear();
                            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                            std::cout << "Error: Please enter a valid integer for flight days.\n";
                        } else {
                            break;
                        }
                    }

                    int availableSeats;
                    while (true) {
                        std::cout << "Enter the number of available seats: ";
                        std::cin >> availableSeats;
                        if (std::cin.fail()) {
                            std::cin.clear();
                            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                            std::cout << "Error: Please enter a valid integer for available seats.\n";
                        } else {
                            break;
                        }
                    }

                    std::vector<std::shared_ptr<TicketModel>> seats;
                    char addTicket;

                    do {
                        std::string firstName, lastName;
                        int seatNumber;

                        std::cout << "Add a ticket? (y/n): ";
                        std::cin >> addTicket;
                        if (addTicket == 'y' || addTicket == 'Y') {
                            std::cout << "Enter first name: ";
                            std::cin >> firstName;
                            std::cout << "Enter last name: ";
                            std::cin >> lastName;

                            while (true) {
                                std::cout << "Enter seat number: ";
                                std::cin >> seatNumber;
                                if (std::cin.fail()) {
                                    std::cin.clear();
                                    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                                    std::cout << "Error: Please enter a valid integer for seat number.\n";
                                } else {
                                    break;
                                }
                            }

                            std::shared_ptr<TicketModel> newTicket = std::make_shared<TicketModel>(
                                    firstName, lastName, std::vector<int>{seatNumber}, 1, whence, whither
                            );
                            seats.push_back(newTicket);
                        }
                    } while (addTicket == 'y' || addTicket == 'Y');

                    PlaneModel plane;
                    std::string planeModel;
                    int maxSeats;
                    std::cout << "Enter plane model: ";
                    std::cin >> planeModel;

                    while (true) {
                        std::cout << "Enter maximum seats in plane: ";
                        std::cin >> maxSeats;
                        if (std::cin.fail()) {
                            std::cin.clear();
                            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                            std::cout << "Error: Please enter a valid integer for maximum seats.\n";
                        } else {
                            break;
                        }
                    }

                    plane = PlaneModel(planeModel, maxSeats);

                    FlightModel newFlight(flightNumber, whence, whither, intermediateStops,
                                          departureTime, flightDays, availableSeats, seats, plane);

                    try {
                        std::future<std::string> createFuture = controller.CreateOrUpdate(newFlight);
                        std::cout << createFuture.get() << std::endl;
                    } catch (const std::exception &e) {
                        std::cerr << "Error: " << e.what() << std::endl;
                    }
                    break;
                }
                case 4: {  // Видалити рейс за номером
                    int flightNumber;
                    std::cout << "Enter the flight number to delete: ";
                    std::cin >> flightNumber;

                    try {
                        std::future<std::string> deleteFuture = controller.Delete(flightNumber);
                        std::cout << deleteFuture.get() << std::endl;
                    } catch (const std::exception &e) {
                        std::cerr << "Помилка: " << e.what() << std::endl;
                    }
                    break;
                }
                case 5: { // Сортування рейсів
                    std::string key;
                    std::cout << "Enter sort key (flightNumber, whither, availableSeats): ";
                    std::cin >> key;

                    std::future<std::vector<FlightModel>> sortFuture = controller.Sort(key);
                    std::vector<FlightModel> sortedFlights = sortFuture.get();

                    std::cout << "\n--- Sorted Flights ---\n";
                    for (const auto& flight : sortedFlights) {
                        std::cout << FlightModel::getFlight(flight) << std::endl;
                    }
                    break;
                }
                case 6: { // Фільтрація рейсів
                    int minSeats, maxSeats;
                    std::cout << "Enter minimum available seats: ";
                    std::cin >> minSeats;
                    std::cout << "Enter maximum available seats: ";
                    std::cin >> maxSeats;

                    std::future<std::vector<FlightModel>> filterFuture = controller.Filter(minSeats, maxSeats);
                    std::vector<FlightModel> filteredFlights = filterFuture.get();

                    std::cout << "\n--- Filtered Flights ---\n";
                    for (const auto& flight : filteredFlights) {
                        std::cout << FlightModel::getFlight(flight) << std::endl;
                    }
                    break;
                }
                case 7: {
                    std::cout << "Exiting program." << std::endl;
                    return 0;
                }
                default:
                    std::cout << "Invalid option. Please try again." << std::endl;
                    break;
            }
        }
    }

}
