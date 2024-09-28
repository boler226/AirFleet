//
// Created by User on 13.08.2024.
//

#ifndef AIRFLEET_PLANEMODEL_H
#define AIRFLEET_PLANEMODEL_H


#pragma once
#include <string>

class PlaneModel
{
private:
    std::string name;
    int maxSeats;
public:
    PlaneModel();   // Конструктор за замовчуванням
    PlaneModel(std::string name, int maxSeats);   // Конструктор з параметрами
    PlaneModel(const PlaneModel& other);	// Конструктор копіювання
    PlaneModel(PlaneModel&& other) noexcept;	// Конструктор переміщення
    ~PlaneModel();	// Деструктор

    PlaneModel& operator=(const PlaneModel& other);

    [[nodiscard]] std::string toString() const; // Обов'язково використати результат при поверненні із функції
};


#endif //AIRFLEET_PLANEMODEL_H
