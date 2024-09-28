//
// Created by User on 13.08.2024.
//

#ifndef AIRFLEET_DESTINATION_H
#define AIRFLEET_DESTINATION_H


#pragma once
#include <string>
#include <vector>
#include <unordered_map>

struct CountryInfo {
    std::string name;
    std::vector<std::string> cities;
};

class Destination
{
private:
    CountryInfo info;
    static const CountryInfo Empty;
    static const std::unordered_map<std::string, CountryInfo> countries;
public:
    Destination();
    explicit Destination(CountryInfo  countryInfo);

    Destination& operator=(const Destination& other);

    static Destination fromString(const std::string& str);
    [[nodiscard]] std::string toString() const; // Обов'язково використати результат при поверненні із функції


};
#endif //AIRFLEET_DESTINATION_H
