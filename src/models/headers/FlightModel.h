//
// Created by User on 13.08.2024.
//
#ifndef AIRFLEET_FLIGHTMODEL_H
#define AIRFLEET_FLIGHTMODEL_H

#pragma once
#include <string>
#include <fstream>
#include <filesystem>
#include <iostream>
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
    std::vector<Destination> intermediateStops;	// Пункти проміжної посадки
    std::time_t departureTime;	// Час відправлення
    std::time_t  flightDays;	// Дні польоту
    int availableSeats;	// Кількість вільних місць
    std::vector<TicketModel> seats;
    PlaneModel plane;	// Літак
public:
    FlightModel();	// Конструктор за замовчуванням
    FlightModel(   // Конструктор з параметрами
            int flightNumber,
            Destination whence,
            Destination whither,
            const std::vector<Destination>& intermediateStops,
            const std::time_t& departureTime,
            const std::time_t& flightDays,
            int availableSeats,
            const std::vector<TicketModel>& seats,
            PlaneModel& plane
    );
    FlightModel(const FlightModel& other);	// Конструктор копіювання
    FlightModel(FlightModel&& other) noexcept;	// Конструктор переміщення
    ~FlightModel();	// Деструктор

    static std::string formatData(const FlightModel& model);
    static FlightModel fromFile(const std::string& filePath);
    static void saveDataToFile(const FlightModel& model, const std::string& fileName);
    static std::string timeToString(time_t timeValue);
    static time_t stringToTime(const std::string& timeStr);
    static std::string getFlight(const FlightModel& model);



    // Setters
    void setFlightNumber(int number) { flightNumber = number; }
    void setWhence(const Destination& from) { whence = from; }
    void setWhither(const Destination& to) { whither = to; }
    void setIntermediateStops(const std::vector<Destination>& stops) { intermediateStops = stops; }
    void setDepartureTime(std::time_t time) { departureTime = time; }
    void setFlightDays(std::time_t days) { flightDays = days; }
    void setAvailableSeats(int seats) { availableSeats = seats; }
    void setSeats(const std::vector<TicketModel>& ticketSeats) { this->seats = ticketSeats; }
    void setPlane(const PlaneModel& model) { plane = model; }

    // Getters
    [[nodiscard]] int getFlightNumber() const { return flightNumber; }
    [[nodiscard]] Destination getWhence() const { return whence; }
    [[nodiscard]] Destination getWhither() const { return whither; }
    [[nodiscard]] std::vector<Destination> getIntermediateStops() const { return intermediateStops; }
    [[nodiscard]] std::time_t getDepartureTime() const { return departureTime; }
    [[nodiscard]] std::time_t getFlightDays() const { return flightDays; }
    [[nodiscard]] int getAvailableSeats() const { return availableSeats; }
    [[nodiscard]] std::vector<TicketModel> getSeats() const { return seats; }
    [[nodiscard]] PlaneModel getPlane() const { return plane; }
};



#endif //AIRFLEET_FLIGHTMODEL_H
