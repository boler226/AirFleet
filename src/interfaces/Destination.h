//
// Created by User on 13.08.2024.
//

#ifndef AIRFLEET_DESTINATION_H
#define AIRFLEET_DESTINATION_H


#pragma once
#include <vector>

struct CountryInfo {
    const char* name;
    std::vector<const char*> cities;
};

class Destination
{
public:
    static const CountryInfo Albania;
    static const CountryInfo Andorra;
    static const CountryInfo Armenia;
    static const CountryInfo Austria;
    static const CountryInfo Azerbaijan;
    static const CountryInfo Belarus;
    static const CountryInfo Belgium;
    static const CountryInfo BosniaAndHerzegovina;
    static const CountryInfo Bulgaria;
    static const CountryInfo Croatia;
    static const CountryInfo Cyprus;
    static const CountryInfo CzechRepublic;
    static const CountryInfo Denmark;
    static const CountryInfo Estonia;
    static const CountryInfo Finland;
    static const CountryInfo France;
    static const CountryInfo Georgia;
    static const CountryInfo Germany;
    static const CountryInfo Greece;
    static const CountryInfo Hungary;
    static const CountryInfo Iceland;
    static const CountryInfo Ireland;
    static const CountryInfo Italy;
    static const CountryInfo Kazakhstan;
    static const CountryInfo Kosovo;
    static const CountryInfo Latvia;
    static const CountryInfo Liechtenstein;
    static const CountryInfo Lithuania;
    static const CountryInfo Luxembourg;
    static const CountryInfo Malta;
    static const CountryInfo Moldova;
    static const CountryInfo Monaco;
    static const CountryInfo Montenegro;
    static const CountryInfo Netherlands;
    static const CountryInfo NorthMacedonia;
    static const CountryInfo Norway;
    static const CountryInfo Poland;
    static const CountryInfo Portugal;
    static const CountryInfo Romania;
    static const CountryInfo SanMarino;
    static const CountryInfo Serbia;
    static const CountryInfo Slovakia;
    static const CountryInfo Slovenia;
    static const CountryInfo Spain;
    static const CountryInfo Sweden;
    static const CountryInfo Switzerland;
    static const CountryInfo Turkey;
    static const CountryInfo Ukraine;
    static const CountryInfo UnitedKingdom;
    static const CountryInfo VaticanCity;
};
#endif //AIRFLEET_DESTINATION_H
