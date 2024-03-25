#include "CMenu.h"
#include "CMenuItem.h"
#include "Hotel.h"
#include <iostream>

const int ITEM_NUMBER = 5;
const int SORT_QUANTITY = 5;
const int SEARCH_QUANTITY = 3;

bool operator==(const Date& d1, const Date& d2)
{
    return (d1.day == d2.day && d1.month == d2.month && d1.year == d2.year);
}
bool operator < (const Date& d1, const Date& d2) {
    if (d1.getYear() != d2.getYear()) return d1.getYear() < d2.getYear();
    if (d1.getMonth() != d2.getMonth()) return d1.getMonth() < d2.getMonth();
    return d1.getDay() < d2.getDay();
}
bool operator > (const Date& d1, const Date& d2) {
    if (d1.getYear() != d2.getYear()) return d1.getYear() > d2.getYear();
    if (d1.getMonth() != d2.getMonth()) return d1.getMonth() > d2.getMonth();
    return d1.getDay() > d2.getDay();
}

int getValue();

int Sorting(std::vector<Hotel>& data)
{
    std::cout << "Select an item to sort\n";
    CMenuItem items[SORT_QUANTITY]{
     CMenuItem{"Sort by body", (CMenuItem::FunctionHotel)Hotel::SortByBody},
     CMenuItem{"Sort by room type", (CMenuItem::FunctionHotel)Hotel::SortByRoomType},
     CMenuItem{"Sort by name", (CMenuItem::FunctionHotel)Hotel::SortByName},
     CMenuItem{"Sort by cost", (CMenuItem::FunctionHotel)Hotel::SortByCost},
     CMenuItem{"Sort by arrival date", (CMenuItem::FunctionHotel)Hotel::SortByArrivalDate},
    };
    CMenu menu("Choosing", items, SORT_QUANTITY);

    while (menu.runCommand(data)) {
    };

    return 4;
}

int Search(std::vector<Hotel>& data)
{
    std::cout << "Select an item to search\n";
    CMenuItem items[SEARCH_QUANTITY]{
     CMenuItem{"Search by room type", (CMenuItem::FunctionHotel)Hotel::SearchByRoomType},
     CMenuItem{"Search by favors type", (CMenuItem::FunctionHotel)Hotel::SortByRoomType},
     CMenuItem{"Search by arrival date", (CMenuItem::FunctionHotel)Hotel::SortByName}
    };
    CMenu menu("Choosing", items, SORT_QUANTITY);

    while (menu.runCommand(data)) {
    };

    return 5;
}

int main()
{
    setlocale(LC_ALL, "RU");

    std::vector<Hotel> data;

    Hotel::ReadDataFromFile(data);

    CMenuItem items[ITEM_NUMBER]{
         CMenuItem{"Print full information", (CMenuItem::FunctionHotel)Hotel::PrintFullInfo},
         CMenuItem{"Add information", (CMenuItem::FunctionHotel)Hotel::AddInfo},
         CMenuItem{"Delete information", (CMenuItem::FunctionHotel)Hotel::DeleteInfo},
         CMenuItem{"Sorting information", (CMenuItem::FunctionHotel)Sorting},
         CMenuItem{"Searching information", (CMenuItem::FunctionHotel)Search},
    };
    CMenu menu("Choosing", items, ITEM_NUMBER);

    while (menu.runCommand(data)) {
    };

    Hotel::UpdateDataInFile(data);

	return 0;
}