#include "src/models/SeederData.h"

int main() {
    SeederData seeder;
    FlightController controller;
//
    try {
        std::string result = seeder.SeedData().get();
        std::cout << "Result of seeding: " << result << std::endl;
    } catch (const std::exception& e) {
        std::cerr << "Exception caught during get: " << e.what() << std::endl;
    } catch (...) {
        std::cerr << "Unknown exception caught during get" << std::endl;
    }

//    controller.List().get();

//    std::cout << std::time(nullptr);
//    std::cout <<FlightModel::timeToString(std::time(0));
//    FlightModel::stringToTime("2024-10-25 20:06:23");
    return 0;
}
