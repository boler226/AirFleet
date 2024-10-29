//
// Created by User on 13.08.2024.
//

#include "../headers/TicketModel.h"


TicketModel::TicketModel()
        : firstName(),
          lastName(),
          seats(),
          numberSeats(0),
          whence(),
          whither()
{
}

TicketModel::TicketModel(
        const std::string& firstName,
        const std::string& lastName,
        const std::vector<int>& seats,
        int numberSeats,
        const Destination& whence,
        const Destination& whither
        )
        : firstName(firstName),
          lastName(lastName),
          seats(seats),
          numberSeats(numberSeats),
          whence(whence),
          whither(whither)
{
}

TicketModel::TicketModel(const TicketModel& other) {
    firstName = other.firstName;
    lastName = other.lastName;
    seats = other.seats;
    numberSeats = other.numberSeats;
    whence = other.whence;
    whither = other.whither;
}

TicketModel::TicketModel(TicketModel &&other) noexcept
        : firstName(other.firstName),
          lastName(other.lastName),
          seats(std::move(other.seats)),
          numberSeats(other.numberSeats),
          whence(other.whence),
          whither(other.whither)
{
}

TicketModel::~TicketModel() {
}

TicketModel TicketModel::fromString(const std::string& str) {
    if (str.empty()) {
        throw std::runtime_error("Input string is empty!");
    }

    std::istringstream ss(str);
    TicketModel ticket;

    std::string seatStr, whenceStr, whitherStr;
    if (std::getline(ss, ticket.firstName, ',') &&
        std::getline(ss, ticket.lastName, ',') &&
        std::getline(ss, seatStr, ',') &&
        std::getline(ss, whenceStr, ',') &&
        std::getline(ss, whitherStr)) {

        ticket.numberSeats = std::stoi(seatStr);
        ticket.whence = Destination::fromString(whenceStr.erase(0,1));
        ticket.whither = Destination::fromString(whitherStr.erase(0,1));

        for (int i = 1; i <= ticket.numberSeats; ++i) {
            ticket.seats.push_back(i);
        }
    }
    return ticket;
}

[[nodiscard]] std::string TicketModel::toString() const {
    std::stringstream model; // Для форматування складних рядків
    model << firstName << ", " << lastName << ", ";

    for (int seat : seats) {
        model << seat << ", ";
    }
    model << whence.toString() << ", " << whither.toString();
    return model.str();
}