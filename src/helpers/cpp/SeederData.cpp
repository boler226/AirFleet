//
// Created by User on 06.09.2024.
//
#include "../headers/SeederData.h"

SeederData::SeederData() {

}

std::future<std::string> SeederData::SeedData() {
        return std::async(std::launch::async, [this]() -> std::string {
            std::filesystem::path filePath = std::filesystem::current_path() / "..\\info";

            if(!std::filesystem::exists(filePath)) {
                std::filesystem::create_directory(filePath);
            }

            if(std::filesystem::is_empty(filePath))
            {
                std::shared_ptr<TicketModel> ticket1 = std::make_shared<TicketModel>(
                        "John", "Doe", std::vector<int>{1, 2}, 3,
                        Destination::fromString("Hungary"), Destination::fromString("Andorra")
                );

                std::shared_ptr<TicketModel> ticket2 = std::make_shared<TicketModel>(
                        "Jane", "Smith", std::vector<int>{4, 5}, 4,
                        Destination::fromString("France"), Destination::fromString("Germany")
                );

                std::shared_ptr<TicketModel> ticket3 = std::make_shared<TicketModel>(
                        "Alice", "Johnson", std::vector<int>{6, 7}, 5,
                        Destination::fromString("Italy"), Destination::fromString("Netherlands")
                );

                std::shared_ptr<TicketModel> ticket4 = std::make_shared<TicketModel>(
                        "Bob", "Brown", std::vector<int>{8, 9}, 6,
                        Destination::fromString("Poland"), Destination::fromString("Sweden")
                );

                std::shared_ptr<TicketModel> ticket5 = std::make_shared<TicketModel>(
                        "Charlie", "White", std::vector<int>{10, 11}, 7,
                        Destination::fromString("Spain"), Destination::fromString("Portugal")
                );

                PlaneModel plane1("AAN 120", 120);
                PlaneModel plane2("BBN 220", 180);
                PlaneModel plane3("CCN 320", 150);
                PlaneModel plane4("DDN 420", 200);
                PlaneModel plane5("EEN 520", 160);


                std::time_t departure1 = 1622505600; // 1 червня 2021 р.
                std::time_t departure2 = 1625097600; // 1 липня 2021 р.
                std::time_t departure3 = 1627776000; // 1 серпня 2021 р.
                std::time_t departure4 = 1630454400; // 1 вересня 2021 р.
                std::time_t departure5 = 1633046400; // 1 жовтня 2021 р.

                std::vector<FlightModel> testFlights = {
                        FlightModel(1, Destination::fromString("Albania"), Destination::fromString("Andorra"),
                                    {Destination::fromString("Belgium"), Destination::fromString("Croatia")},
                                    departure1, 3, 21, {ticket1}, plane1), // вилітає кожного вівторка

                        FlightModel(2, Destination::fromString("France"), Destination::fromString("Germany"),
                                    {Destination::fromString("Switzerland"), Destination::fromString("Austria")},
                                    departure2, 5, 30, {ticket2}, plane2), // вилітає кожної п’ятниці

                        FlightModel(3, Destination::fromString("Italy"), Destination::fromString("Netherlands"),
                                    {Destination::fromString("Belgium"), Destination::fromString("Luxembourg")},
                                    departure3, 1, 25, {ticket3}, plane3), // вилітає кожного понеділка

                        FlightModel(4, Destination::fromString("Poland"), Destination::fromString("Sweden"),
                                    {Destination::fromString("Denmark"), Destination::fromString("Norway")},
                                    departure4, 4, 40, {ticket4}, plane4), // вилітає кожної середи

                        FlightModel(5, Destination::fromString("Spain"), Destination::fromString("Portugal"),
                                    {Destination::fromString("Morocco"), Destination::fromString("Italy")},
                                    departure5, 6, 50, {ticket5}, plane5)  // вилітає кожної суботи
                };
                std::vector<std::future<std::string>> results;
                for (const auto& flight : testFlights) {
                    results.push_back(flightController.CreateOrUpdate(flight));
                }

                // Завершення всіх задач
                for (auto& result : results) {
                    std::cout << result.get() << std::endl;
                }

                return "Seeding completed.";
            }
            else
            {
                return "Seeding not completed. Maybe data already exist.";
            }

        });
}