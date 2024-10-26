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
    data += "Departure Time: " + timeToString(model.departureTime) + "\n";
    data += "Flight Days: " + timeToString(model.flightDays) + "\n";
    data += "Available Seats: " + std::to_string(model.availableSeats) + "\n";

    for (const TicketModel& ticket : model.seats)
    {
        data += "Ticket Information: " + ticket.toString() + "\n";
    }

    data += "Plane: " + model.plane.toString();

    return data;
}

FlightModel FlightModel::fromFile(const std::filesystem::path& filePath) {
    FlightModel model;
    std::ifstream file(filePath);

    if(!file) {
        std::cerr << "Error: Could not open the file " << filePath << std::endl;
        return model;
    }

    std::string line;
    while (std::getline(file, line)) {
        if (line.find("Flight Number:") != std::string::npos) {
            std::string flightNumberStr = line.substr(line.find(':') + 1);
            flightNumberStr.erase(0, flightNumberStr.find_first_not_of(" \t"));

            model.setFlightNumber(std::stoi(flightNumberStr));
        }
        if (line.find("Whence Time:") != std::string::npos) {
            std::string whenceTimeStr = line.substr(line.find(':') + 1);
            whenceTimeStr.erase(0, whenceTimeStr.find_first_not_of(" \t"));

            model.setWhence(Destination::fromString(whenceTimeStr));
        }
        if (line.find("Whither Time:") != std::string::npos) {
            std::string whiterTimeStr = line.substr(line.find(':') + 1);
            whiterTimeStr.erase(0, whiterTimeStr.find_first_not_of(" \t"));

            model.setWhither(Destination::fromString(whiterTimeStr));
        }
        if (line.find("Intermedia Stop:") != std::string::npos) {
            std::string intermediaStopStr = line.substr(line.find(':') + 1);
            intermediaStopStr.erase(0, intermediaStopStr.find_first_not_of(" \t"));

            model.intermediateStops.push_back(Destination::fromString(intermediaStopStr));
        }
        if (line.find("Departure Time:") != std::string::npos) {
            std::string departureTimeStr = line.substr(line.find(':') + 1);
            departureTimeStr.erase(0, departureTimeStr.find_first_not_of(" \t"));

            model.setDepartureTime(stringToTime(departureTimeStr));
        }
        if (line.find("Flight Days:") != std::string::npos) {
            std::string flightDaysStr = line.substr(line.find(':') + 1);
            flightDaysStr.erase(0, flightDaysStr.find_first_not_of(" \t"));

            model.setFlightDays(stringToTime(flightDaysStr));
        }
        if (line.find("Available Seats:") != std::string::npos) {
            std::string availableSeats = line.substr(line.find(':') + 1);
            availableSeats.erase(0, availableSeats.find_first_not_of(" \t"));

            model.setAvailableSeats(std::stoi(availableSeats));
        }
        if (line.find("Ticket Information:") != std::string::npos) {
            std::string ticketInformation = line.substr(line.find(':') + 1);
            ticketInformation.erase(0, ticketInformation.find_first_not_of(" \t"));

            model.seats.push_back(TicketModel::fromString(ticketInformation));
        }
        if (line.find("Plane:") != std::string::npos) {
            std::string plane = line.substr(line.find(':') + 1);
            plane.erase(0, plane.find_first_not_of(" \t"));

            model.setPlane(PlaneModel::fromString(plane));
        }
    }
    return model;
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

time_t FlightModel::stringToTime(const std::string& timeStr) {
    std::tm tm = {};
    int year, month, day, hour, minute, second;
    char dash1, dash2, colon1, colon2;

    std::istringstream ss(timeStr);
    if (ss >> year >> dash1 >> month >> dash2 >> day >> hour >> colon1 >> minute >> colon2 >> second) {
        if (dash1 != '-' || dash2 != '-' || colon1 != ':' || colon2 != ':') {
            throw std::runtime_error("Invalid time format");
        }
        tm = {0};
        tm.tm_year = year - 1900;
        tm.tm_mon = month - 1;
        tm.tm_mday = day;
        tm.tm_hour = hour;
        tm.tm_min = minute;
        tm.tm_sec = second;
    } else {
        throw std::runtime_error("Invalid time format");
    }

    // Конвертуємо std::tm у time_t
    return std::mktime(&tm);
}

std::string FlightModel::timeToString(time_t timeValue) {
    if (timeValue == 0) {
        return "Invalid time";
    }

    std::tm* tmPtr = std::localtime(&timeValue); // Конвертуємо time_t в tm

    std::stringstream ss;
    ss << std::put_time(tmPtr, "%Y-%m-%d %H:%M:%S");

    return ss.str();
}

std::string FlightModel::getFlight(const FlightModel &model) {
    std::ostringstream result;
    std::string stops;

    for (auto& stop : model.intermediateStops) {
        stops += stop.toString() + ", ";
    }
    stops.resize(stops.size() - 2);

    result << "Flight Number: " << model.getFlightNumber() << " | "
           << "Whence: " << model.getWhence().toString() << " | "
           << "Whither: " << model.getWhither().toString() << " | "
           << "Intermedia Stop: " << stops << " | "
           << "Departure Time: " << timeToString(model.getDepartureTime()) << " | "
           << "Flight Days: " << timeToString(model.getFlightDays()) << " | "
           << "Available Seats: " << model.getAvailableSeats() << " | "
           << "Plane: " << model.getPlane().toString() << " | ";

    return result.str();
}
