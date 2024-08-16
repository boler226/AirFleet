//
// Created by User on 13.08.2024.
//
#ifndef AIRFLEET_FLIGHTMODEL_H
#define AIRFLEET_FLIGHTMODEL_H

#pragma once
#include <string>
#include <vector>
#include <ctime>
#include "../../interfaces//Destination.h"
#include "TicketModel.h"
#include "PlaneModel.h"

class FlightModel
{
private:
    int flightNumber;	// Номер рейсу
    Destination whence;   // Звідки
    Destination whither;   // Куди
    std::vector<Destination> intermeditateStops;	// Пункти проміжної посадки
    std::time_t departureTime;	// Час відправлення
    std::time_t  flightDays;	// Дні польоту
    int availableSeats;	// Кількість вільних місць
    std::vector<TicketModel> seats;
    PlaneModel plane;	// Літак
public:
    FlightModel();	// Конструктор за замовчуванням
    FlightModel(   // Конструктор з параметрами
            int flightNumber,
            Destination& whence,
            Destination& whither,
            const std::vector<Destination>& intermeditateStops,
            const std::time_t& departureTime,
            const std::time_t& flightDays,
            int availableSeats,
            const std::vector<TicketModel>& seats,
            PlaneModel& plane
    );
    FlightModel(const FlightModel& other);	// Конструктор копіювання
    FlightModel(FlightModel&& other) noexcept;	// Конструктор переміщення
    ~FlightModel();	// Деструктор
};



#endif //AIRFLEET_FLIGHTMODEL_H
