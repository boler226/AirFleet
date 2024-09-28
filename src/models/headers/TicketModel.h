//
// Created by User on 13.08.2024.
//

#ifndef AIRFLEET_TICKETMODEL_H
#define AIRFLEET_TICKETMODEL_H

#pragma once
#include <string>
#include <vector>
#include <sstream>
#include "../../interfaces//Destination.h";

class TicketModel {
private:
    std::string firstName;
    std::string lastName;
    std::vector<int> seats; // Місця в літаку
    int numberSeats; // Кількість місць
    Destination whence;   // Звідки
    Destination whither;   // Куди
public:
    TicketModel();   // Конструктор за замовчуванням
    TicketModel(    // Конструктор з параметрами
            const std::string& firstName,
            const std::string& lastName,
            const std::vector<int>& seats,
            int numberSeats,
            const Destination& whence,
            const Destination& whither
            );
    TicketModel(const TicketModel& other);    // Конструктор копіювання
    TicketModel(TicketModel&& other) noexcept;    // Конструктор переміщення
    ~TicketModel();  // Деструктор

    TicketModel& operator=(const TicketModel& other);

    [[nodiscard]] std::string toString() const; // Обов'язково використати результат при поверненні із функції
};


#endif //AIRFLEET_TICKETMODEL_H
