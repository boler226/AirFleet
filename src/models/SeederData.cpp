//
// Created by User on 06.09.2024.
//
#include "SeederData.h"

SeederData::SeederData() {

}

std::future<std::string> SeederData::SeedData() {
    return std::async(std::launch::async, [this]() -> std::string {

        TicketModel ticket1("John", "Doe", {1, 2, 3}, 3,
                             (Destination &) Destination::Albania, (Destination &) Destination::Andorra);
        PlaneModel plane1("AAN 120", 120);


        std::vector<FlightModel> testFlights = {
                FlightModel(1, (Destination &) Destination::Albania, (Destination &) Destination::Andorra, {(Destination &) Destination::Belgium, (Destination &) Destination::Croatia}, 0, 0, 21, {ticket1}, plane1),
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
    });
}