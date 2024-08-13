//
// Created by User on 13.08.2024.
//

#ifndef AIRFLEET_TICKET_H
#define AIRFLEET_TICKET_H

#pragma once
#include <string>
#include <vector>
#include "../../interfaces//Destination.h";

class Ticket {
private:
    std::string firstName;
    std::string lastName;
    std::vector<int> seat; // Місця в літаку
    int numberSeats; // Кількість місць
    Destination whence;   // Звідки
    Destination whither;   // Куди
public:
    Ticket();   // Конструктор за замовчуванням
    Ticket(    // Конструктор з параметрами
            std::string first,
            std::string last,
            const std::vector<int> seat,
            int num,
            Destination& whence,
            Destination& whither
            );
    Ticket(const Ticket& other);    // Конструктор копіювання
    Ticket(Ticket&& other) noexcept;    // Конструктор переміщення
    ~Ticket();  // Деструктор
};


#endif //AIRFLEET_TICKET_H
