#include "Hotel.h"

int getValue()
{
	int a{};
	while (true) // цикл продолжается до тех пор, пока пользователь не введет
	{
		std::cin >> a;

		if (std::cin.fail()) // если предыдущее извлечение оказалось неудачным,
		{
			std::cin.clear(); // то возвращаем cin в 'обычный' режим работы 
			std::cin.ignore(32767, '\n'); // и удаляем значения предыдущего
			std::cout << "Incorrect value, try again: ";
		}
		else // если всё хорошо, то возвращаем a 
			return a;
	}
}

Hotel::Hotel()
{
	this->id++;
}

int Hotel::GetId()
{
	return this->id;
}

int Hotel::GetCorpus()
{
	return this->corpus;
}

std::vector<Service> Hotel::GetFavors()
{
	return this->favors;
}

int Hotel::GetCost()
{
	return this->cost;
}

std::string Hotel::GetFullName()
{
	return this->fullName;
}

std::string Hotel::GetPhoneNumber()
{
	return this->phoneNumber;
}

std::string Hotel::GetEMail()
{
	return this->eMail;
}

Date Hotel::GetDate()
{
	return this->date;
}

int Hotel::GetNightsNumber()
{
	return this->nightsNumber;
}

int Hotel::GetFullCost()
{
	return this->fullCost;
}

int Hotel::AddInfo(std::vector<Hotel> &data)
{
	Hotel buff;
	int variant{};
	std::cout << "Choose corpus: \n1.Alpha; \n2.Beta;  \n3.Vega; \n4.Delta; \n5.Gamma. \nSelect: ";
	while (true) {
		variant = getValue();
		if (variant >= 1 && variant <= 5) break;
	}
	switch (variant)
	{
	case 1: buff.corpus = Alpha; break;
	case 2: buff.corpus = Beta; break;
	case 3: buff.corpus = Vega; break;
	case 4: buff.corpus = Delta; break;
	case 5: buff.corpus = Gamma; break;
	}

	std::cout << "Choose room type: \n1.Standard; \n2.Business class;  \n3.First class; \n4.Deluxe; \nSelect: ";
	while (true) {
		variant = getValue();
		if (variant >= 1 && variant <= 4) break;
	}

	switch (variant)
	{
	case 1: buff.room = Standard; break;
	case 2: buff.room = BusinessClass; break;
	case 3: buff.room = FirstClass; break;
	case 4: buff.room = Deluxe; break;
	}

	variant = 0;
	std::cout << "Choose service: \n1.Swimming Pool; \n2.Lunch;  \n3.Fitness room; \n4.Spa; \n5.Transport; \n6.Wifi. \nSelect(if more than 1, write it with space): ";
	while (std::cin >> variant)
	{
		switch (variant)
		{
		case 1: buff.favors.push_back(SwimmingPool); break;
		case 2: buff.favors.push_back(Lucnh); break;
		case 3: buff.favors.push_back(FitnessRoom); break;
		case 4: buff.favors.push_back(Spa); break;
		case 5: buff.favors.push_back(Transport); break;
		case 6: buff.favors.push_back(FreeWifi); break;
		}
	}

	std::cout << "Enter full name: ";
	std::getline(std::cin, buff.fullName);

	std::cout << "Enter phone number: ";
	std::getline(std::cin, buff.phoneNumber);

	std::cout << "Enter eMail: ";
	std::getline(std::cin, buff.eMail);

	int day, month, year;
	std::cout << "Enter date of entry \nEnter day: ";
	while (true) {
		day = getValue();
		if (variant >= 1 && variant <= 31) break;
	}

	std::cout << "Enter month: ";
	while (true) {
		month = getValue();
		if (variant >= 1 && variant <= 12) break;
	}

	std::cout << "Enter year: ";
	while (true) {
		year = getValue();
		if (variant >= 2000 && variant <= 2100) break;
	}

	buff.date = (day, month, year);

	std::cout << "Enter number of nights: ";
	while (true) {
		buff.nightsNumber = getValue();
		if (variant >= 1) break;
	}


	buff.fullCost = ((buff.nightsNumber)*buff.cost) + (1000 * buff.favors.size());

	data.push_back(buff);

	return 2;
}
void Hotel::PrintInfo() {
	std::cout << "ID: " << GetId() << std::endl;
	std::cout << "Body: ";
	switch (this->corpus) {
	case 1: std::cout << "Alpha"; break;
	case 2: std::cout << "Beta"; break;
	case 3: std::cout << "Vega"; break;
	case 4: std::cout << "Delta"; break;
	case 5: std::cout << "Gamma"; break;
	}
	std::cout << std::endl;

	std::cout << "Room type: ";
	switch (this->corpus) {
	case 1: std::cout << "Standard"; break;
	case 2: std::cout << "Business class"; break;
	case 3: std::cout << "First class"; break;
	case 4: std::cout << "Deluxe"; break;
	}
	std::cout << std::endl;

	std::cout << "Selected services: ";
	for (int i = 0; i < this->favors.size(); i++) {
		switch (this->favors[i]) {
		case 1: std::cout << "Swimming pool"; break;
		case 2: std::cout << "Lunch"; break;
		case 3: std::cout << "Fitness room"; break;
		case 4: std::cout << "Spa"; break;
		case 5: std::cout << "Transport"; break;
		case 6: std::cout << "Wifi"; break;
		}
		if (favors.size() > 1 && i != favors.size()-1) {
			std::cout << ", ";
		}
	}
	std::cout << std::endl;

	std::cout << "Price of one night: " << GetCost() << std::endl;
	std::cout << "Full name: " << GetFullName() << std::endl;
	std::cout << "Phone Number: " << GetPhoneNumber() << std::endl;
	std::cout << "E-Mail adress: " << GetEMail() << std::endl;
	std::cout << "Arrival date: ";
	this->date.PrintDate();

	std::cout << "Number of nights: " << GetNightsNumber() << std::endl;
	std::cout << "Full price: " << GetFullCost() << std::endl << std::endl;

}
int Hotel::PrintFullInfo(std::vector<Hotel> data)
{
	for (int i = 0; i < data.size(); i++) {
		data[i].PrintInfo();
		std::cout << std::endl;
	}
	return 1;
}
int Hotel::DeleteInfo(std::vector<Hotel>& data)
{
	PrintFullInfo(data);
	int variant{};
	std::cout << "Choose variant: ";
	while (true) {
		variant = getValue();
		if (variant >= 1 && variant <= data.size()) break;
	}

	variant--;

	data.erase(data.begin() + variant);
	return 3;
}

int Hotel::SortByBody(std::vector<Hotel>& data)
{
	int variant{};
	std::cout << "1. Ascending. " << std::endl << "2. Descending. " << std::endl << "Select: ";
	while (true) {
		variant = getValue();
		if (variant >= 1 && variant <= 2) break;
	}
	for (int l = 0; l < data.size() - 1; l++) {
		for (int j = 0; j < data.size() - l - 1; j++) {
			if (variant == 1 && data[j].corpus < data[j + 1].corpus) {
				std::swap(data[j], data[j + 1]);
			}
			if (variant == 2 && data[j].corpus > data[j + 1].corpus) {
				std::swap(data[j], data[j + 1]);
			}
		}
	}
	PrintFullInfo(data);
	return 1;
}
int Hotel::SortByRoomType(std::vector<Hotel>& data)
{
	int variant{};
	std::cout << "1. Ascending. " << std::endl << "2. Descending. " << std::endl << "Select: ";
	while (true) {
		variant = getValue();
		if (variant >= 1 && variant <= 2) break;
	}
	for (int l = 0; l < data.size() - 1; l++) {
		for (int j = 0; j < data.size() - l - 1; j++) {
			if (variant == 1 && data[j].room < data[j + 1].room) {
				std::swap(data[j], data[j + 1]);
			}
			if (variant == 2 && data[j].room > data[j + 1].room) {
				std::swap(data[j], data[j + 1]);
			}
		}
	}
	PrintFullInfo(data);
	return 1;
}
int Hotel::SortByName(std::vector<Hotel>& data) 
{
	int variant{};
	std::cout << "1. Ascending. " << std::endl << "2. Descending. " << std::endl << "Select: ";
	while (true) {
		variant = getValue();
		if (variant >= 1 && variant <= 2) break;
	}
	for (int l = 0; l < data.size() - 1; l++) {
		for (int j = 0; j < data.size() - l - 1; j++) {
			if (variant == 1 && strcmp(data[j].fullName.c_str(), data[j + 1].fullName.c_str()) < 0) {
				std::swap(data[j], data[j + 1]);
			}
			if (variant == 2 && strcmp(data[j].fullName.c_str(), data[j + 1].fullName.c_str()) > 0) {
				std::swap(data[j], data[j + 1]);
			}
		}
	}
	PrintFullInfo(data);
	return 1;
}
int Hotel::SortByArrivalDate(std::vector<Hotel>& data)
{
	int variant{};
	std::cout << "1. Ascending. " << std::endl << "2. Descending. " << std::endl << "Select: ";
	while (true) {
		variant = getValue();
		if (variant >= 1 && variant <= 2) break;
	}
	for (int l = 0; l < data.size() - 1; l++) {
		for (int j = 0; j < data.size() - l - 1; j++) {
			if (variant == 1 && data[j].date < data[j+1].date) {
				std::swap(data[j], data[j + 1]);
			}
			if (variant == 2 && data[j].date > data[j + 1].date) {
				std::swap(data[j], data[j + 1]);
			}
		}
	}
	PrintFullInfo(data);
	return 1;
}
int Hotel::SortByCost(std::vector<Hotel>& data) 
{
	int variant{};
	std::cout << "1. Ascending. " << std::endl << "2. Descending. " << std::endl << "Select: ";
	while (true) {
		variant = getValue();
		if (variant >= 1 && variant <= 2) break;
	}
	for (int l = 0; l < data.size() - 1; l++) {
		for (int j = 0; j < data.size() - l - 1; j++) {
			if (variant == 1 && data[j].cost < data[j + 1].cost) {
				std::swap(data[j], data[j + 1]);
			}
			if (variant == 2 && data[j].cost > data[j + 1].cost) {
				std::swap(data[j], data[j + 1]);
			}
		}
	}
	return 1;
}

int Hotel::SearchByRoomType(std::vector<Hotel>& data)
{
	int variant{};
	std::cout << "Choose search item: " << std::endl << "1.Standard. \n" << "2. Business First. \n" << "3. First Class. \n" << "4. Deluxe. \n" << "Select: ";
	while (true) {
		variant = getValue();
		if (variant >= 1 && variant <= 4) break;
	}
	for (int i{}; i < data.size(); i++) 
	{
		if (data[i].room == variant) 
		{
			data[i].PrintInfo();
		}
	}
	return 1;
}
int Hotel::SearchByFavors(std::vector<Hotel>& data)
{
	int variant{};
	std::cout << "Choose search item: \n" << "1.Swimming pool. \n" << "2. Lunch. \n" << "3. Fitness room. \n" << "4. Spa \n." << "5. Transport. \n" << "6. FreeWifi. \n" << "Select: ";
	while (true) {
		variant = getValue();
		if (variant >= 1 && variant <= 6) break;
	}
	for (int i{}; i < data.size(); i++)
	{
		for (int j{}; j < data[i].favors.size(); j++) {
			if (data[i].favors[j] == variant)
			{
				data[i].PrintInfo();
				break;
			}
		}
	}
	return 1;
}
int Hotel::SeatchByDate(std::vector<Hotel>& data)
{
	int d{}, m{}, y{};
	std::cout << "Enter day: ";
	while (true) {
		d = getValue();
		if (d >= 1 && d <= 31) break;
	}
	std::cout << "Enter month: ";
	while (true) {
		m = getValue();
		if (m >= 1 && m <= 12) break;
	}
	std::cout << "Enter year: ";
	while (true) {
		y = getValue();
		if (y >= 2000 && y <= 2100) break;
	}
	
	Date buff = (d, m, y);

	for (int i{}; i < data.size(); i++)
	{
		if (data[i].date == buff)
		{
			data[i].PrintInfo();
		}
	}
	return 0;
}

void Hotel::ReadDataFromFile(std::vector<Hotel> data)
{
	int i{};
	std::ifstream fin("Hotel.txt");
	Hotel buff;
	int room;
	int corpus;
	int d, m, y;
	std::string n, f, o;
	int favor[6]{};
	while (fin >> buff.id >> corpus >> room >> favor[0] >> favor[1] >> favor[2] >> favor[3] >> favor[4] >> favor[5] >> buff.cost >> n >> f >> o >> buff.phoneNumber >> buff.eMail >> d >> m >> y >> buff.nightsNumber >> buff.fullCost) {
		switch (corpus)
		{
		case 1: buff.corpus = Alpha; break;
		case 2: buff.corpus = Beta; break;
		case 3: buff.corpus = Vega; break;
		case 4: buff.corpus = Delta; break;
		case 5: buff.corpus = Gamma; break;
		}
		switch (room)
		{
		case 1: buff.room = Standard; break;
		case 2: buff.room = BusinessClass; break;
		case 3: buff.room = FirstClass; break;
		case 4: buff.room = Deluxe; break;
		}
		for (int i{}; i < 6; i++) {
			switch (favor[i]) {
			case 1: buff.favors.push_back(SwimmingPool); break;
			case 2: buff.favors.push_back(Lucnh); break;
			case 3: buff.favors.push_back(FitnessRoom); break;
			case 4: buff.favors.push_back(Spa); break;
			case 5: buff.favors.push_back(Transport); break;
			case 6: buff.favors.push_back(FreeWifi); break;
			}
		}
		buff.date = Date(d, m, y); 
		buff.fullName = n + f + o;
		data.push_back(buff);
	}
	fin.close();
}

void Hotel::UpdateDataInFile(std::vector<Hotel> data)
{
	std::ofstream fout("Hotel.txt");
	for (int i{}; i < data.size(); i++)
	{
		int favors[6]{};
		for (int j{}; j < 6; j++) {
			for (int r{}; r < data[i].favors.size(); r++) {
				if (data[i].favors[r] == j + 1) {
					favors[j] = data[i].favors[r];
				}
			}
		}

		fout << data[i].GetId() << '\t' << data[i].corpus << '\t' << data[i].room << '\t' << favors[0] << '\t' << favors[1] << '\t' << favors[2] << '\t' << favors[3] << '\t' << favors[4] << '\t' << favors[5] << '\t' << data[i].GetCost() << '\t' << data[i].GetFullName() << '\t' << data[i].GetPhoneNumber() << '\t' << data[i].GetEMail() << '\t' << data[i].date.GetFullDate() << '\t' << data[i].GetNightsNumber() << '\t' << data[i].GetFullCost() << std::endl;

	}
	fout.close();

}
