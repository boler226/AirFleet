//
// Created by User on 13.08.2024.
//

#include "../headers/Flight.h"

Flight::Flight()
        : flightNumber(0),
          departureTime(0),
          flightDays(0),
          availableSeats(0),
          whence(),
          whither(),
          intermeditateStops(),
          seats(),
          plane()
{
}

Flight::Flight(
        int flightNumber,
        Destination& whence,
        Destination& whither,
        const std::vector<Destination>& intermeditateStops,
        const std::time_t& departureTime,
        const std::time_t& flightDays,
        int availableSeats,
        const std::vector<Ticket>& seats,
        Plane& plane
)
        : flightNumber(flightNumber),
          whence(whence),
          whither(whither),
          intermeditateStops(intermeditateStops),
          departureTime(departureTime),
          flightDays(flightDays),
          availableSeats(availableSeats),
          seats(seats),
          plane(plane)
{
}

Flight::Flight(const Flight& other)
        : flightNumber(other.flightNumber),
          whence(other.whence),
          whither(other.whither),
          intermeditateStops(other.intermeditateStops),
          departureTime(other.departureTime),
          flightDays(other.flightDays),
          availableSeats(other.availableSeats),
          seats(other.seats),
          plane(other.plane)
{
}

Flight::Flight(Flight&& other) noexcept
        : flightNumber(other.flightNumber),
          whence(other.whence),
          whither(other.whither),
          intermeditateStops(std::move(other.intermeditateStops)),
          departureTime(other.departureTime),
          flightDays(other.flightDays),
          availableSeats(other.availableSeats),
          seats(std::move(other.seats)),
          plane(std::move(other.plane))
{
}

Flight::~Flight() {
}