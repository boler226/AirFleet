//
// Created by User on 13.08.2024.
//

#include <utility>

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

PlaneModel::PlaneModel(const PlaneModel& other)
        : name(other.name),
          maxSeats(other.maxSeats)
{
}

PlaneModel::PlaneModel(PlaneModel&& other) noexcept
        : name(std::move(other.name)),
          maxSeats(other.maxSeats)
{
}

PlaneModel::~PlaneModel(){
}