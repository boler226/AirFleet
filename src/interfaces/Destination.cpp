#include <cstring>
#include <utility>
#include "Destination.h"

Destination::Destination()
        : info(Destination::Empty)
{
}
Destination::Destination(CountryInfo  countryInfo)
        : info(std::move(countryInfo))
{
}

Destination Destination::fromString(const std::string &str) {
    if (!str.empty()) {
        auto item = countries.find(str);
        if (item != countries.end()) {
            return (Destination &)item->second;
        }
    }
    return Destination(Destination::Empty);
}

std::string Destination::toString() const {
    return info.name;
}

const CountryInfo Destination::Empty = {"", {}};


const std::unordered_map<std::string, CountryInfo> Destination::countries = {
        { "Albania", { "Albania", { "Tirana", "Durres", "Vlore", "Shkoder" } }},
        { "Andorra", { "Andorra", { "Andorra la Vella", "Escaldes-Engordany", "Encamp", "La Massana" } }},
        { "Armenia", { "Armenia", { "Yerevan", "Gyumri", "Vanadzor", "Hrazdan" } }},
        { "Austria", { "Austria", { "Vienna", "Graz", "Linz", "Salzburg" } }},
        { "Azerbaijan", { "Azerbaijan", { "Baku", "Ganja", "Sumqayit", "Mingachevir" } }},
        { "Belarus", { "Belarus", { "Minsk", "Gomel", "Mogilev", "Vitebsk" } }},
        { "Belgium", { "Belgium", { "Brussels", "Antwerp", "Ghent", "Charleroi" } }},
        { "Bosnia and Herzegovina", { "Bosnia and Herzegovina", { "Sarajevo", "Banja Luka", "Tuzla", "Zenica" } }},
        { "Bulgaria", { "Bulgaria", { "Sofia", "Plovdiv", "Varna", "Burgas" } }},
        { "Croatia", { "Croatia", { "Zagreb", "Split", "Rijeka", "Osijek" } }},
        { "Cyprus", { "Cyprus", { "Nicosia", "Limassol", "Larnaca", "Famagusta" } }},
        { "Czech Republic", { "Czech Republic", { "Prague", "Brno", "Ostrava", "Plzen" } }},
        { "Denmark", { "Denmark", { "Copenhagen", "Aarhus", "Odense", "Aalborg" } }},
        { "Estonia", { "Estonia", { "Tallinn", "Tartu", "Narva", "Parnu" } }},
        { "Finland", { "Finland", { "Helsinki", "Espoo", "Tampere", "Vantaa" } }},
        { "France", { "France", { "Paris", "Marseille", "Lyon", "Toulouse" } }},
        { "Georgia", { "Georgia", { "Tbilisi", "Kutaisi", "Batumi", "Rustavi" } }},
        { "Germany", { "Germany", { "Berlin", "Hamburg", "Munich", "Cologne" } }},
        { "Greece", { "Greece", { "Athens", "Thessaloniki", "Patras", "Heraklion" } }},
        { "Hungary", { "Hungary", { "Budapest", "Debrecen", "Szeged", "Miskolc" } }},
        { "Iceland", { "Iceland", { "Reykjavik", "Kopavogur", "Hafnarfjordur", "Akureyri" } }},
        { "Ireland", { "Ireland", { "Dublin", "Cork", "Limerick", "Galway" } }},
        { "Italy", { "Italy", { "Rome", "Milan", "Naples", "Turin" } }},
        { "Kazakhstan", { "Kazakhstan", { "Astana", "Almaty", "Shymkent", "Karaganda" } }},
        { "Latvia", { "Latvia", { "Riga", "Daugavpils", "Liepaja", "Jelgava" } }},
        { "Lithuania", { "Lithuania", { "Vilnius", "Kaunas", "Klaipeda", "Siauliai" } }},
        { "Luxembourg", { "Luxembourg", { "Luxembourg", "Esch-sur-Alzette", "Differdange", "Dudelange" } }},
        { "Malta", { "Malta", { "Valletta", "Birkirkara", "Mosta", "Qormi" } }},
        { "Moldova", { "Moldova", { "Chisinau", "Balti", "Tiraspol", "Bender" } }},
        { "Monaco", { "Monaco", { "Monaco-Ville", "Monte Carlo", "La Condamine", "Fontvieille" } }},
        { "Montenegro", { "Montenegro", { "Podgorica", "Niksic", "Herceg Novi", "Budva" } }},
        { "Netherlands", { "Netherlands", { "Amsterdam", "Rotterdam", "The Hague", "Utrecht" } }},
        { "North Macedonia", { "North Macedonia", { "Skopje", "Bitola", "Kumanovo", "Prilep" } }},
        { "Norway", { "Norway", { "Oslo", "Bergen", "Stavanger", "Trondheim" } }},
        { "Poland", { "Poland", { "Warsaw", "Krakow", "Lodz", "Wroclaw" } }},
        { "Portugal", { "Portugal", { "Lisbon", "Porto", "Amadora", "Braga" } }},
        { "Romania", { "Romania", { "Bucharest", "Cluj-Napoca", "Timisoara", "Iasi" } }},
        { "Russia", { "Russia", { "Moscow", "Saint Petersburg", "Novosibirsk", "Yekaterinburg" } }},
        { "San Marino", { "San Marino", { "San Marino", "Serravalle", "Borgo Maggiore", "Domagnano" } }},
        { "Serbia", { "Serbia", { "Belgrade", "Novi Sad", "Niš", "Kragujevac" } }},
        { "Slovakia", { "Slovakia", { "Bratislava", "Kosice", "Presov", "Zilina" } }},
        { "Slovenia", { "Slovenia", { "Ljubljana", "Maribor", "Celje", "Kranj" } }},
        { "Spain", { "Spain", { "Madrid", "Barcelona", "Valencia", "Seville" } }},
        { "Sweden", { "Sweden", { "Stockholm", "Gothenburg", "Malmo", "Uppsala" } }},
        { "Switzerland", { "Switzerland", { "Bern", "Zurich", "Geneva", "Basel" } }},
        { "Turkey", { "Turkey", { "Ankara", "Istanbul", "Izmir", "Bursa" } }},
        { "Ukraine", { "Ukraine", { "Kyiv", "Kharkiv", "Odessa", "Dnipro" } }},
        { "United Kingdom", { "United Kingdom", { "London", "Birmingham", "Glasgow", "Liverpool" } }},
        { "Vatican City", { "Vatican City", { "Vatican City" } }}
};