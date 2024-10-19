//
// Created by User on 13.08.2024.
//

#include "../headers/FlightModel.h"

FlightModel::FlightModel()
        : flightNumber(0),
          departureTime(0),
          flightDays(0),
          availableSeats(0),
          whence(),
          whither(),
          intermediateStops(),
          seats(),
          plane()
{
}

FlightModel::FlightModel(
        int flightNumber,
        Destination whence,
        Destination whither,
        const std::vector<Destination>& intermediateStops,
        const std::time_t& departureTime,
        const std::time_t& flightDays,
        int availableSeats,
        const std::vector<TicketModel>& seats,
        PlaneModel& plane
)
        : flightNumber(flightNumber),
          whence(whence),
          whither(whither),
          intermediateStops(intermediateStops),
          departureTime(departureTime),
          flightDays(flightDays),
          availableSeats(availableSeats),
          seats(seats),
          plane(plane)
{
}

FlightModel::FlightModel(const FlightModel& other)
        : flightNumber(other.flightNumber),
          whence(other.whence),
          whither(other.whither),
          intermediateStops(other.intermediateStops),
          departureTime(other.departureTime),
          flightDays(other.flightDays),
          availableSeats(other.availableSeats),
          seats(other.seats),
          plane(other.plane)
{
}

FlightModel::FlightModel(FlightModel&& other) noexcept
        : flightNumber(other.flightNumber),
          whence(other.whence),
          whither(other.whither),
          intermediateStops(std::move(other.intermediateStops)),
          departureTime(other.departureTime),
          flightDays(other.flightDays),
          availableSeats(other.availableSeats),
          seats(std::move(other.seats)),
          plane(std::move(other.plane))
{
}

FlightModel::~FlightModel() {
}

std::string FlightModel::formatData(const FlightModel& model) {
    std::string data;
    data += "Flight Number: " + std::to_string(model.flightNumber) + "\n";
    data += "Whence Time: " + model.whence.toString() + "\n";
    data += "Whither Time: " + model.whither.toString() + "\n";

    for(int i = 0; i < model.intermediateStops.size(); i++)
    {
        data += "Intermedia Stop: " + model.intermediateStops[i].toString() + "\n";
    }
    data += "Departure Time: " + std::to_string(model.departureTime) + "\n";
    data += "Flight Days: " + std::to_string(model.flightDays) + "\n";
    data += "Available Seats: " + std::to_string(model.availableSeats) + "\n";

    for (const TicketModel& ticket : model.seats)
    {
        data += "Ticket Information: " + ticket.toString() + "\n";
    }

    data += "Plane: " + model.plane.toString();

    return data;
}

FlightModel FlightModel::fromFile(const std::string &filePath) {
    FlightModel model;
    std::ifstream file(filePath);

    if(!file) {
        std::cerr << "Error: Could not open the file " << filePath << std::endl;
        return model;
    }

    std::string line;
    while (std::getline(file, line)) {
        if (line.find("Flight Number:") != std::string::npos) {
            // Витягуємо частину рядка після "Flight Number:"
            std::string flightNumberStr = line.substr(line.find(":") + 1);
            // Вирізаємо пробіли з початку рядка
            flightNumberStr.erase(0, flightNumberStr.find_first_not_of(" \t"));

            // Перетворюємо рядок на число
            model.flightNumber = std::stoi(flightNumberStr);
        }
        if (line.find("Whence Time:") != std::string::npos) {
            // Витягуємо частину рядка після "Whence Time:"
            std::string whenceTimeStr = line.substr(line.find(":") + 1);
            // Вирізаємо пробіли з початку рядка
            whenceTimeStr.erase(0, whenceTimeStr.find_first_not_of(" \t"));

            model.whence = Destination::fromString(whenceTimeStr);
        }
    }
}

void FlightModel::saveDataToFile(const FlightModel &model, const std::string &fileName) {
    std::filesystem::path filePath = std::filesystem::current_path() / "..\\info" / fileName;

    std::cout << "File path: " << filePath << std::endl;

    // Перевіряємо, чи існує папка, і створюємо її, якщо необхідно
    std::filesystem::path infoDir = filePath.parent_path();
    if (!std::filesystem::exists(infoDir)) {
        std::filesystem::create_directory(infoDir);
    }

    std::ofstream outFile(filePath);

    if (!outFile) {
        std::cerr << "Error: Could not open the file for writing!" << filePath << std::endl;
        return;
    }

    std::string flightData = FlightModel::formatData(model);
    outFile << flightData;
    outFile.close();

    std::cout << "Data has been written to the file successfully!" << std::endl;
}