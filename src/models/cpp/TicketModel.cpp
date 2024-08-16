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
        std::string& firstName,
        std::string& lastName,
        const std::vector<int>& seat,
        int numberSeats,
        Destination& whence,
        Destination& whither
        )
        : firstName(firstName),
          lastName(lastName),
          seats(seats),
          numberSeats(numberSeats),
          whence(whence),
          whither(whither)
{
}

TicketModel::TicketModel(const TicketModel& other)
        : firstName(other.firstName),
          lastName(other.lastName),
          seats(other.seats),
          numberSeats(other.numberSeats),
          whence(other.whence),
          whither(other.whither)
{
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

[[nodiscard]] std::string TicketModel::toString() const {
    std::stringstream model; // Для форматування складних рядків
    model << firstName << ", " << lastName << ", ";

    for (int i = 0; i < seats.size() - 1; i++) {
        model << seats[i];
        if (i != seats.size() - 1) {
            model << ", ";
        }
    }
    model << whence.toString() << ", " << whither.toString();
    return model.str();
}