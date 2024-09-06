#include "Destination.h"

Destination::Destination()
        : info(Destination::Empty)
{
}

std::string Destination::toString() const {
    return std::string(info.name);
}

const CountryInfo Destination::Empty = { "", {} };
const CountryInfo Destination::Albania = { "Albania", {"Tirana", "Durres", "Vlore", "Shkoder"} };
const CountryInfo Destination::Andorra = { "Andorra", {"Andorra la Vella", "Escaldes-Engordany", "Encamp", "La Massana"} };
const CountryInfo Destination::Armenia = { "Armenia", {"Yerevan", "Gyumri", "Vanadzor", "Hrazdan"} };
const CountryInfo Destination::Austria = { "Austria", {"Vienna", "Graz", "Linz", "Salzburg"} };
const CountryInfo Destination::Azerbaijan = { "Azerbaijan", {"Baku", "Ganja", "Sumqayit", "Mingachevir"} };
const CountryInfo Destination::Belarus = { "Belarus", {"Minsk", "Gomel", "Mogilev", "Vitebsk"} };
const CountryInfo Destination::Belgium = { "Belgium", {"Brussels", "Antwerp", "Ghent", "Charleroi"} };
const CountryInfo Destination::BosniaAndHerzegovina = { "Bosnia and Herzegovina", {"Sarajevo", "Banja Luka", "Tuzla", "Zenica"} };
const CountryInfo Destination::Bulgaria = { "Bulgaria", {"Sofia", "Plovdiv", "Varna", "Burgas"} };
const CountryInfo Destination::Croatia = { "Croatia", {"Zagreb", "Split", "Rijeka", "Osijek"} };
const CountryInfo Destination::Cyprus = { "Cyprus", {"Nicosia", "Limassol", "Larnaca", "Famagusta"} };
const CountryInfo Destination::CzechRepublic = { "Czech Republic", {"Prague", "Brno", "Ostrava", "Plzen"} };
const CountryInfo Destination::Denmark = { "Denmark", {"Copenhagen", "Aarhus", "Odense", "Aalborg"} };
const CountryInfo Destination::Estonia = { "Estonia", {"Tallinn", "Tartu", "Narva", "Parnu"} };
const CountryInfo Destination::Finland = { "Finland", {"Helsinki", "Espoo", "Tampere", "Vantaa"} };
const CountryInfo Destination::France = { "France", {"Paris", "Marseille", "Lyon", "Toulouse"} };
const CountryInfo Destination::Georgia = { "Georgia", {"Tbilisi", "Kutaisi", "Batumi", "Rustavi"} };
const CountryInfo Destination::Germany = { "Germany", {"Berlin", "Hamburg", "Munich", "Cologne"} };
const CountryInfo Destination::Greece = { "Greece", {"Athens", "Thessaloniki", "Patras", "Heraklion"} };
const CountryInfo Destination::Hungary = { "Hungary", {"Budapest", "Debrecen", "Szeged", "Miskolc"} };
const CountryInfo Destination::Iceland = { "Iceland", {"Reykjavik", "Kopavogur", "Hafnarfjordur", "Akureyri"} };
const CountryInfo Destination::Ireland = { "Ireland", {"Dublin", "Cork", "Limerick", "Galway"} };
const CountryInfo Destination::Italy = { "Italy", {"Rome", "Milan", "Naples", "Turin"} };
const CountryInfo Destination::Kazakhstan = { "Kazakhstan", {"Nur-Sultan", "Almaty", "Shymkent", "Karaganda"} };
const CountryInfo Destination::Kosovo = { "Kosovo", {"Pristina", "Mitrovica", "Peja", "Gjakova"} };
const CountryInfo Destination::Latvia = { "Latvia", {"Riga", "Daugavpils", "Liepaja", "Jelgava"} };
const CountryInfo Destination::Liechtenstein = { "Liechtenstein", {"Vaduz", "Schaan", "Balzers", "Triesen"} };
const CountryInfo Destination::Lithuania = { "Lithuania", {"Vilnius", "Kaunas", "Klaipeda", "Siauliai"} };
const CountryInfo Destination::Luxembourg = { "Luxembourg", {"Luxembourg City", "Esch-sur-Alzette", "Differdange", "Dudelange"} };
const CountryInfo Destination::Malta = { "Malta", {"Valletta", "Birkirkara", "Mosta", "Qormi"} };
const CountryInfo Destination::Moldova = { "Moldova", {"Chisinau", "Balti", "Tiraspol", "Bender"} };
const CountryInfo Destination::Monaco = { "Monaco", {"Monaco", "Monte Carlo", "La Condamine", "Fontvieille"} };
const CountryInfo Destination::Montenegro = { "Montenegro", {"Podgorica", "Niksic", "Herceg Novi", "Pljevlja"} };
const CountryInfo Destination::Netherlands = { "Netherlands", {"Amsterdam", "Rotterdam", "The Hague", "Utrecht"} };
const CountryInfo Destination::NorthMacedonia = { "North Macedonia", {"Skopje", "Bitola", "Kumanovo", "Prilep"} };
const CountryInfo Destination::Norway = { "Norway", {"Oslo", "Bergen", "Stavanger", "Trondheim"} };
const CountryInfo Destination::Poland = { "Poland", {"Warsaw", "Krakow", "Lodz", "Wroclaw"} };
const CountryInfo Destination::Portugal = { "Portugal", {"Lisbon", "Porto", "Braga", "Coimbra"} };
const CountryInfo Destination::Romania = { "Romania", {"Bucharest", "Cluj-Napoca", "Timisoara", "Iasi"} };
const CountryInfo Destination::SanMarino = { "San Marino", {"San Marino", "Serravalle", "Borgo Maggiore", "Domagnano"} };
const CountryInfo Destination::Serbia = { "Serbia", {"Belgrade", "Novi Sad", "Nis", "Kragujevac"} };
const CountryInfo Destination::Slovakia = { "Slovakia", {"Bratislava", "Kosice", "Presov", "Zilina"} };
const CountryInfo Destination::Slovenia = { "Slovenia", {"Ljubljana", "Maribor", "Celje", "Kranj"} };
const CountryInfo Destination::Spain = { "Spain", {"Madrid", "Barcelona", "Valencia", "Seville"} };
const CountryInfo Destination::Sweden = { "Sweden", {"Stockholm", "Gothenburg", "Malmo"} };
const CountryInfo Destination::Turkey = { "Turkey", {"Ankara", "Istanbul", "Izmir", "Antalya"} };
const CountryInfo Destination::Ukraine = { "Ukraine", {"Kyiv", "Kharkiv", "Lviv", "Odesa"} };
const CountryInfo Destination::UnitedKingdom = { "United Kingdom", {"London", "Manchester", "Birmingham", "Edinburgh"} };
const CountryInfo Destination::VaticanCity = { "Vatican City", {"Vatican City"} };
