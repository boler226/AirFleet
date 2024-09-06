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
        Destination& whence,
        Destination& whither,
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

void FlightModel::saveDataToFile(const FlightModel &model, const std::string &fileName) {
    std::ofstream outFile(fileName);

    if (!outFile) {
        std::cerr << "Error: Could not open the file for writing!" << std::endl;
        return;
    }

    std::string flightData = model.formatData(model);

    outFile << flightData;

    outFile.close();

    std::cout << "Data has been written to the file successfully!" << std::endl;
}