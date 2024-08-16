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
    const int maxSeats;
public:
    PlaneModel();
    PlaneModel(std::string name, int maxSeats);   // Конструктор з параметрами
    PlaneModel(const PlaneModel& other);	// Конструктор копіювання
    PlaneModel(PlaneModel&& other) noexcept;	// Конструктор переміщення
    ~PlaneModel();	// Деструктор
};


#endif //AIRFLEET_PLANEMODEL_H
