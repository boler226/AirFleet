//
// Created by User on 06.09.2024.
//
#include "SeederData.h"

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
                TicketModel ticket1("John", "Doe", {1, 2}, 3,
                                    Destination::fromString("Hungary"), Destination::fromString("Andorra"));
                PlaneModel plane1("AAN 120", 120);


                std::vector<FlightModel> testFlights = {
                        FlightModel(1, Destination::fromString("Albania"), Destination::fromString("Andorra"),
                                    {Destination::fromString("Belgium"), Destination::fromString("Croatia")},
                                    0, 0, 21, {ticket1}, plane1),
                };
                std::vector<std::future<std::string>> results;
                for (const auto& flight : testFlights) {
                    results.push_back(flightController.Create(flight));
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