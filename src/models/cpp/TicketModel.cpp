//
// Created by User on 13.08.2024.
//

#include "../headers/TicketModel.h"

TicketModel::TicketModel()
        : firstName(),
          lastName(),
          seat(),
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
          seat(seat),
          numberSeats(numberSeats),
          whence(whence),
          whither(whither)
{
}

TicketModel::TicketModel(const TicketModel& other)
        : firstName(other.firstName),
          lastName(other.lastName),
          seat(other.seat),
          numberSeats(other.numberSeats),
          whence(other.whence),
          whither(other.whither)
{
}

TicketModel::TicketModel(TicketModel &&other) noexcept
        : firstName(other.firstName),
          lastName(other.lastName),
          seat(std::move(other.seat)),
          numberSeats(other.numberSeats),
          whence(other.whence),
          whither(other.whither)
{
}

TicketModel::~TicketModel() {
}