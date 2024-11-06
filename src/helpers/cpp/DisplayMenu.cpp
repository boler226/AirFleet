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
        std::cout << "\n--- Навігаційне меню ---\n";
        std::cout << "1. Список рейсів\n";
        std::cout << "2. Пошук рейсу\n";
        std::cout << "3. Додати або оновити\n";
        std::cout << "4. Видалити рейс\n";
        std::cout << "5. Сортування рейсу\n";
        std::cout << "6. Фільтруйте рейси за наявними місцями\n";
        std::cout << "7. Посібник користувача\n";
        std::cout << "8. Вихід\n";
        std::cout << "Виберіть опцію: ";
        std::cin >> choice;

        if (std::cin.fail()) {
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); // Ігноруємо залишки у буфері
            std::cout << "Помилка: невірний вхід. Введіть дійсне ціле число.\n";
        } else {
            switch (choice) {
                case 1: {  // Відобразити список рейсів
                    try {
                        std::future<void> listFuture = controller.List();
                        listFuture.get();
                    } catch (const std::exception &e) {
                        std::cerr << "Помилка: " << e.what() << std::endl;
                    }
                    //1waitForUserInput();
                    break;
                }
                case 2: {  // Пошук рейсу за номером
                    int flightNumber;
                    std::cout << "Введіть номер рейсу: ";
                    std::cin >> flightNumber;

                    try {
                        std::future<std::optional<FlightModel>> findFuture = controller.FindByNumber(flightNumber);
                        std::optional<FlightModel> foundFlight = findFuture.get();

                        if (foundFlight.has_value()) {
                            FlightModel flight = foundFlight.value();
                            std::cout << "Рейс знайдено: \n" << FlightModel::formatData(flight) << std::endl;
                        } else {
                            std::cout << "Рейс не знайдено." << std::endl;
                        }
                    } catch (const std::exception &e) {
                        std::cerr << "Помилка: " << e.what() << std::endl;
                    }
                    break;
                }
                case 3: {  // Додати новий рейс
                    int flightNumber;
                    while (true) {
                        std::cout << "Введіть новий номер рейсу: ";
                        std::cin >> flightNumber;
                        if (std::cin.fail()) {
                            std::cin.clear(); // Очищаємо прапор помилки
                            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); // Пропускаємо некоректний ввід
                            std::cout << "Помилка: введіть дійсне ціле число для номера рейсу.\n";
                        } else {
                            break; // Вийти з циклу, якщо ввід коректний
                        }
                    }

                    std::string whenceName, whitherName;
                    std::cout << "Введіть пункт відправлення: ";
                    std::cin >> whenceName;
                    std::cout << "Введіть пункт призначення: ";
                    std::cin >> whitherName;

                    Destination whence = Destination::fromString(whenceName);
                    Destination whither = Destination::fromString(whitherName);

                    std::vector<Destination> intermediateStops;
                    std::string stopName;
                    char addMore;

                    do {
                        std::cout << "Додайте проміжну зупинку? (y/n): ";
                        std::cin >> addMore;
                        if (addMore == 'y' || addMore == 'Y') {
                            std::cout << "Введіть назву проміжної зупинки: ";
                            std::cin >> stopName;
                            intermediateStops.push_back(Destination::fromString(stopName));
                        }
                    } while (addMore == 'y' || addMore == 'Y');

                    std::time_t departureTime;
                    while (true) {
                        std::cout << "Введіть час відправлення (формат epoch: 1730061355): ";
                        std::cin >> departureTime;
                        if (std::cin.fail()) {
                            std::cin.clear();
                            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                            std::cout << "Помилка: введіть дійсне ціле число для часу відправлення.\n";
                        } else {
                            break;
                        }
                    }

                    std::time_t flightDays;
                    while (true) {
                        std::cout << "Введіть дні польоту (як ціле число): ";
                        std::cin >> flightDays;
                        if (std::cin.fail()) {
                            std::cin.clear();
                            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                            std::cout << "Помилка: введіть дійсне ціле число для днів польоту.\n";
                        } else {
                            break;
                        }
                    }

                    int availableSeats;
                    while (true) {
                        std::cout << "Введіть кількість вільних місць: ";
                        std::cin >> availableSeats;
                        if (std::cin.fail()) {
                            std::cin.clear();
                            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                            std::cout << "Помилка: введіть дійсне ціле число для доступних місць.\n";
                        } else {
                            break;
                        }
                    }

                    std::vector<std::shared_ptr<TicketModel>> seats;
                    char addTicket;

                    do {
                        std::string firstName, lastName;
                        int seatNumber;

                        std::cout << "Додайте квиток? (y/n): ";
                        std::cin >> addTicket;
                        if (addTicket == 'y' || addTicket == 'Y') {
                            std::cout << "Введіть ім'я: ";
                            std::cin >> firstName;
                            std::cout << "Введіть прізвище: ";
                            std::cin >> lastName;

                            while (true) {
                                std::cout << "Введіть номер місця: ";
                                std::cin >> seatNumber;
                                if (std::cin.fail()) {
                                    std::cin.clear();
                                    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                                    std::cout << "Помилка: введіть дійсне ціле число для номера місця.\n";
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
                    std::cout << "Введіть модель літака: ";
                    std::cin >> planeModel;

                    while (true) {
                        std::cout << "Введіть максимальну кількість місць у літаку: ";
                        std::cin >> maxSeats;
                        if (std::cin.fail()) {
                            std::cin.clear();
                            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                            std::cout << "Помилка: введіть дійсне ціле число для максимальної кількості місць.\n";
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
                        std::cerr << "Помилка: " << e.what() << std::endl;
                    }
                    break;
                }
                case 4: {  // Видалити рейс за номером
                    int flightNumber;
                    std::cout << "Введіть номер рейсу для видалення: ";
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
                    std::cout << "Введіть ключ сортування (flightNumber, wither, availableSeats): ";
                    std::cin >> key;

                    std::future<std::vector<FlightModel>> sortFuture = controller.Sort(key);
                    std::vector<FlightModel> sortedFlights = sortFuture.get();

                    std::cout << "\n--- Відсортовані рейси ---\n";
                    for (const auto& flight : sortedFlights) {
                        std::cout << FlightModel::getFlight(flight) << std::endl;
                    }
                    break;
                }
                case 6: { // Фільтрація рейсів
                    int minSeats, maxSeats;
                    std::cout << "Введіть мінімальну кількість доступних місць: ";
                    std::cin >> minSeats;
                    std::cout << "Введіть максимальну кількість доступних місць: ";
                    std::cin >> maxSeats;

                    std::future<std::vector<FlightModel>> filterFuture = controller.Filter(minSeats, maxSeats);
                    std::vector<FlightModel> filteredFlights = filterFuture.get();

                    std::cout << "\n--- Відфільтровані рейси ---\n";
                    for (const auto& flight : filteredFlights) {
                        std::cout << FlightModel::getFlight(flight) << std::endl;
                    }
                    break;
                }
                case 7: {
                    getGuide();
                    break;
                }
                case 8: {
                    std::cout << "Вихід з програми." << std::endl;
                    return 0;
                }
                default:
                    std::cout << "Недійсний варіант. Спробуйте ще раз." << std::endl;
                    break;
            }
        }
    }
}

void DisplayMenu::getGuide() {
    std::cout << "\n--- Посібник користувача ---\n";

    std::cout << "1. Список рейсів - відображає список усіх доступних рейсів.\n";
    std::cout << "   - 1.1 Перегляньте всі рейси з повною інформацією (номер рейсу, пункт призначення, час, місця тощо).\n";

    std::cout << "\n2. Пошук рейсу - пошук рейсу за його номером.\n";
    std::cout << "   - 2.1 Введіть номер рейсу, щоб переглянути деталі рейсу.\n";

    std::cout << "\n3. Додати або оновити: додайте новий рейс або оновіть відомості про наявний рейс.\n";
    std::cout << "   - 3.1 Додайте новий рейс, ввівши його деталі (номер рейсу, пункт призначення, час, місця тощо).\n";
    std::cout << "   - 3.2 Оновіть наявну інформацію про рейс, надавши його номер.\n";

    std::cout << "\n4. Видалити рейс – видалити рейс із системи за його номером.\n";
    std::cout << "   - 4.1 Введіть номер рейсу, щоб підтвердити видалення.\n";

    std::cout << "\n5. Сортувати рейси – сортувати список рейсів за вибраним атрибутом.\n";
    std::cout << "   - 5.1 Сортувати за номером рейсу в порядку зростання або спадання.\n";
    std::cout << "   - 5.2 Сортувати за призначенням за алфавітом.\n";
    std::cout << "   - 5.3 Сортуйте за доступними місцями від найвищого до найнижчого.\n";
    std::cout << "   - 5.4 Сортувати за часом відправлення.\n";

    std::cout << "\n6. Фільтрувати рейси за наявними місцями – показувати рейси з наявністю місць у вказаному діапазоні.\n";
    std::cout << "   - 6.1 Установіть мінімальну та максимальну кількість місць, щоб фільтрувати рейси.\n";

    std::cout << "\n7. Вийти - закрити програму.\n";
    std::cout << "   - 7.1 Збережіть усі зміни перед виходом.\n";
    std::cout << "   - 7.2 Підтвердьте вихід, щоб уникнути втрати незбережених даних.\n";

    std::cout << "\nЩоб скористатися опцією, введіть відповідний номер, коли буде запропоновано.\n";
}


