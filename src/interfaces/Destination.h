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
    const std::string name;
    std::vector<std::string> cities;
};

class Destination
{
private:
    const CountryInfo info;
    static const CountryInfo Empty;
    static const std::unordered_map<std::string, CountryInfo> countries;
public:
    Destination();
    explicit Destination(CountryInfo  countryInfo);

    static Destination fromString(const std::string& str);
    [[nodiscard]] std::string toString() const; // Обов'язково використати результат при поверненні із функції


};
#endif //AIRFLEET_DESTINATION_H
