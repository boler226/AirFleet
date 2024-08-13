//
// Created by User on 13.08.2024.
//
#ifndef AIRFLEET_FLIGHT_H
#define AIRFLEET_FLIGHT_H

#pragma once
#include <string>
#include <vector>
#include <ctime>
#include "../../interfaces//Destination.h";
#include "Plane.h";

class Flight
{
private:
    int flightNumber;	// Номер рейсу
    Destination whence;   // Звідки
    Destination whither;   // Куди
    std::vector<Destination> intermeditateStops;	// Пункти проміжної посадки
    std::time_t departureTime;	// Час відправлення
    std::time_t  flightDays;	// Дні польоту
    int availableSeats;	// Кількість вільних місць
    Plane plane;	// Літак
public:
    Flight();	// Конструктор за замовчуванням
    Flight(   // Конструктор з параметрами
            int num,
            Destination& whence,
            Destination& whither,
            const std::vector<Destination>& stops,
            const std::time_t& time,
            const std::time_t& days,
            int seats,
            Plane& plane
    );
    Flight(const Flight& other);	// Конструктор копіювання
    Flight(Flight&& other) noexcept;	// Конструктор переміщення
    ~Flight();	// Деструктор


    static void showInfo();
};



#endif //AIRFLEET_FLIGHT_H
