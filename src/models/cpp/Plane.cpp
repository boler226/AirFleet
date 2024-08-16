//
// Created by User on 13.08.2024.
//

#include <utility>

#include "../headers/Plane.h"

Plane::Plane()
        : name(),
          maxSeats(0)
{
}

Plane::Plane(std::string name, int maxSeats)
        : name(std::move(name)),
          maxSeats(maxSeats)
{
}

Plane::Plane(const Plane& other)
        : name(other.name),
          maxSeats(other.maxSeats)
{
}

Plane::Plane(Plane&& other) noexcept
        : name(std::move(other.name)),
          maxSeats(other.maxSeats)
{
}

Plane::~Plane(){
}