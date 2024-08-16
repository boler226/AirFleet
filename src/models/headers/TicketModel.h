//
// Created by User on 13.08.2024.
//

#ifndef AIRFLEET_TICKETMODEL_H
#define AIRFLEET_TICKETMODEL_H

#pragma once
#include <string>
#include <vector>
#include "../../interfaces//Destination.h";

class TicketModel {
private:
    std::string firstName;
    std::string lastName;
    std::vector<int> seat; // Місця в літаку
    int numberSeats; // Кількість місць
    Destination whence;   // Звідки
    Destination whither;   // Куди
public:
    TicketModel();   // Конструктор за замовчуванням
    TicketModel(    // Конструктор з параметрами
            std::string first,
            std::string last,
            const std::vector<int> seat,
            int num,
            Destination& whence,
            Destination& whither
            );
    TicketModel(const TicketModel& other);    // Конструктор копіювання
    TicketModel(TicketModel&& other) noexcept;    // Конструктор переміщення
    ~TicketModel();  // Деструктор
};


#endif //AIRFLEET_TICKETMODEL_H
