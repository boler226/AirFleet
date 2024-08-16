//
// Created by User on 13.08.2024.
//

#ifndef AIRFLEET_PLANE_H
#define AIRFLEET_PLANE_H


#pragma once
#include <string>

class Plane
{
private:
    std::string name;
    const int maxSeats;
public:
    Plane();
    Plane(std::string name, int maxSeats);   // Конструктор з параметрами
    Plane(const Plane& other);	// Конструктор копіювання
    Plane(Plane&& other) noexcept;	// Конструктор переміщення
    ~Plane();	// Деструктор
};


#endif //AIRFLEET_PLANE_H
