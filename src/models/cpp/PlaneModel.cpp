//
// Created by User on 13.08.2024.
//

#include <utility>
#include <stdexcept>
#include <sstream>

#include "../headers/PlaneModel.h"

PlaneModel::PlaneModel()
        : name(),
          maxSeats(0)
{
}

PlaneModel::PlaneModel(std::string name, int maxSeats)
        : name(std::move(name)),
          maxSeats(maxSeats)
{
}

PlaneModel::PlaneModel(const PlaneModel& other) {
    name = other.name;
    maxSeats = other.maxSeats;
}

PlaneModel::PlaneModel(PlaneModel&& other) noexcept
        : name(std::move(other.name)),
          maxSeats(other.maxSeats)
{
}

PlaneModel::~PlaneModel(){
}


std::string PlaneModel::toString() const {
    return name + "(" + std::to_string(maxSeats) + ")";
}

PlaneModel PlaneModel::fromString(const std::string& str) {
    if (str.empty()) {
        throw std::runtime_error("Input string is empty!");
    }

    size_t openBracket = str.find('(');
    size_t closeBracket = str.find(')');
    PlaneModel plane;

    plane.name = str.substr(0, openBracket);
    std::string seatStr = str.substr(openBracket + 1, closeBracket - openBracket - 1);
    plane.maxSeats = std::stoi(seatStr);

    return plane;
}

PlaneModel& PlaneModel::operator=(const PlaneModel& other) {
    if (this != &other) {
        this->name = other.name;
        this->maxSeats = other.maxSeats;
    }
    return *this;
}