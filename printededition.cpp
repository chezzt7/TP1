#include "printededition.h"

PrintedEdition::PrintedEdition()
{
}

PrintedEdition::~PrintedEdition()
{
}

void PrintedEdition::writeToFile()
{
	std::ofstream outFile("info.txt");

	try {
		if (!outFile.is_open()) {
			throw std::ios_base::failure("Unable to open file");
		}

		outFile << "poets:" << std::endl;
		outFile << poets.size() << std::endl;
		for (int i = 0; i < poets.size(); ++i) {
			outFile << poets[i].getFullName() << std::endl;
			outFile << poets[i].getYearsOfLife() << std::endl;
			outFile << poets[i].getWorks() << std::endl;
		}

		outFile << "fantasts:" << std::endl;
		outFile << fantasts.size() << std::endl;
		for (int i = 0; i < fantasts.size(); ++i) {
			outFile << fantasts[i].getFullName() << std::endl;
			outFile << fantasts[i].hasMoviesAdaptation() << std::endl;
			outFile << fantasts[i].getLiteraryWorks() << std::endl;
		}

		outFile << "romantics:" << std::endl;
		outFile << romantics.size() << std::endl;
		for (int i = 0; i < romantics.size(); ++i) {
			outFile << romantics[i].getFullName() << std::endl;
			outFile << romantics[i].getLifeYears() << std::endl;
			outFile << romantics[i].getBiography() << std::endl;
			outFile << romantics[i].getLiteraryWorks() << std::endl;
		}

		outFile.close();
	}
	catch (const std::exception& e) {
		std::cerr << "Exception: " << e.what() << std::endl;
	}
}


void PrintedEdition::readFromFile()
{
	std::ifstream inFile("info.txt");

	try {
		if (!inFile.is_open()) {
			throw std::ios_base::failure("Unable to open file");
		}

		
		std::string temp;
		std::getline(inFile, temp);

		std::getline(inFile, temp);
		int sizePoet = std::stoi(temp);

		for (int i = 0; i < sizePoet; ++i) {
			Poet poet;
			std::string str;

			std::getline(inFile, str);
			poet.setFCs(str);

			std::getline(inFile, str);
			poet.setYearOfLife(str);

			std::getline(inFile, str);
			poet.setWorks(str);

			poets.push_back(poet);
		}

		std::getline(inFile, temp);

		std::getline(inFile, temp);
		int sizeFantasyAuthor = std::stoi(temp);
		for (int i = 0; i < sizeFantasyAuthor; ++i) {
			FantasyAuthor fant;
			std::string str;

			std::getline(inFile, str);
			fant.setFullName(str);

			std::getline(inFile, str);
			fant.setMoviesAdaptation(str == "1" ? true : false);

			std::getline(inFile, str);
			fant.setLiteraryWorks(str);

			fantasts.push_back(fant);
		}

		std::getline(inFile, temp);

		std::getline(inFile, temp);
		int sizeRomanticist = std::stoi(temp);
		for (int i = 0; i < sizeRomanticist; ++i) {
			Romanticist romant;
			std::string str;

			std::getline(inFile, str);
			romant.setFullName(str);

			std::getline(inFile, str);
			romant.setLifeYears(str);
			
			std::getline(inFile, str);
			romant.setBiography(str);
			
			std::getline(inFile, str);
			romant.setLiteraryWorks(str);

			romantics.push_back(romant);
		}
	}
	catch (const std::exception& e) {
		std::cerr << "Exception: " << e.what() << std::endl;
	}
}



void PrintedEdition::push_backPoet()
{
	std::string name;
	std::cout << "Enter full name\n";
	std::getline(std::cin >> std::ws, name);

	std::string years;
	std::cout << "Enter years of life\n";
	std::getline(std::cin >> std::ws, years);

	std::string works;

	std::cout << "Enter works: \n";
	std::getline(std::cin >> std::ws, works);

	Poet poet;
	poet.setFCs(name);
	poet.setYearOfLife(years);
	poet.setWorks(works);

	poets.push_back(poet);

}

void PrintedEdition::push_backFantst()
{
	std::string name;
	std::cout << "Enter full name\n";
	std::getline(std::cin >> std::ws, name);

	std::string works;
	std::cout << "Enter works: \n";
	std::getline(std::cin >> std::ws, works);

	std::cout << "Movies adaptation (1 or 0): ";
	bool movies;
	std::cin >> movies;

	FantasyAuthor fant(name, works, movies);

	fantasts.push_back(fant);
}

void PrintedEdition::push_backRomantic()
{
	std::string name;
	std::cout << "Enter full name\n";
	std::getline(std::cin >> std::ws, name);

	std::string years;
	std::cout << "Enter years of life\n";
	std::getline(std::cin >> std::ws, years);

	std::string works;
	std::cout << "Enter works: \n";
	std::getline(std::cin >> std::ws, works);

	std::cout << "Enter biographi: ";
	std::string bio;
	std::getline(std::cin >> std::ws, bio);

	Romanticist romant(name, years, works, bio);

	romantics.push_back(romant);
}

void PrintedEdition::deletePoet()
{
	for (int i = 0; i < poets.size(); ++i) {
		std::cout << i + 1 << ") " << poets[i].getFullName() << std::endl;
	}
	std::cout << "Choice poet: ";
	int index;
	std::cin >> index;
	poets.remove(index - 1);
}

void PrintedEdition::deleteFantst()
{
	for (int i = 0; i < fantasts.size(); ++i) {
		std::cout << i + 1 << ") " << fantasts[i].getFullName() << std::endl;
	}
	std::cout << "Choice fantast: ";
	int index;
	std::cin >> index;
	poets.remove(index - 1);
}

void PrintedEdition::deleteRomantic()
{
	for (int i = 0; i < romantics.size(); ++i) {
		std::cout << i + 1 << ") " << romantics[i].getFullName() << std::endl;
	}
	std::cout << "Choice romantc: ";
	int index;
	std::cin >> index;
	poets.remove(index - 1);
}

void PrintedEdition::editPoet()
{
	for (int i = 0; i < poets.size(); ++i) {
		std::cout << i + 1 << ") " << poets[i].getFullName() << std::endl;
	}
	std::cout << "\nChoice poet: ";
	int index;
	std::cin >> index;
	Poet poet = poets[index - 1];

	std::cout << "1. Full name\n";
	std::cout << "2. Years of life\n";
	std::cout << "3. Works\n";
	std::cout << "What do you want to change: ";
	
	int change;
	std::cin >> change;

	if (change == 1) {
		std::string name;
		std::cout << "Enter full name\n";
		std::getline(std::cin >> std::ws, name);
		poet.setFCs(name);
	}

	if (change == 2) {
		std::string years;
		std::cout << "Enter years of life\n";
		std::getline(std::cin >> std::ws, years);
		poet.setYearOfLife(years);
	}

	if (change == 3) {
		std::string works;
		std::cout << "Enter works: \n";
		std::getline(std::cin >> std::ws, works);

		poet.setWorks(works);
	}

	poets[index - 1] = poet;
}

void PrintedEdition::editFantst()
{
	for (int i = 0; i < fantasts.size(); ++i) {
		std::cout << i + 1 << ") " << fantasts[i].getFullName() << std::endl;
	}
	std::cout << "\nChoice poet: ";
	int index;
	std::cin >> index;
	FantasyAuthor fant = fantasts[index - 1];

	std::cout << "1. Full name\n";
	std::cout << "2. Works\n";
	std::cout << "3. Movies adaptation\n";
	std::cout << "What do you want to change: ";

	int change;
	std::cin >> change;

	if (change == 1) {
		std::string name;
		std::cout << "Enter full name\n";
		std::getline(std::cin >> std::ws, name);
		fant.setFullName(name);
	}

	if (change == 2) {
		std::string works;
		std::cout << "Enter works: \n";
		std::getline(std::cin >> std::ws, works);
		fant.setLiteraryWorks(works);
	}

	if (change == 3) {
		std::cout << "Movies adaptation (1 or 0): ";
		bool movies;
		std::cin >> movies;
		fant.setMoviesAdaptation(movies);
	}

	fantasts[index - 1] = fant;
}

void PrintedEdition::editRomantic()
{
	for (int i = 0; i < romantics.size(); ++i) {
		std::cout << i + 1 << ") " << romantics[i].getFullName() << std::endl;
	}
	std::cout << "\nChoice romantics: ";
	int index;
	std::cin >> index;
	Romanticist romant = romantics[index - 1];

	std::cout << "1. Full name\n";
	std::cout << "2. Life of years\n";
	std::cout << "3. Works\n";
	std::cout << "4. Biography\n";
	std::cout << "What do you want to change: ";

	int change;
	std::cin >> change;

	if (change == 1) {
		std::string name;
		std::cout << "Enter full name\n";
		std::getline(std::cin >> std::ws, name);
		romant.setFullName(name);
	}

	if (change == 2) {
		std::string years;
		std::cout << "Enter years of life\n";
		std::getline(std::cin >> std::ws, years);
		romant.setLifeYears(years);
	}

	if (change == 3) {
		std::string works;
		std::cout << "Enter works: \n";
		std::getline(std::cin >> std::ws, works);
		romant.setLiteraryWorks(works);
	}

	if (change == 4) {
		std::cout << "Enter biographi";
		std::string bio;
		std::getline(std::cin >> std::ws, bio);
		romant.setBiography(bio);
	}

	romantics[index - 1] = romant;
}

void PrintedEdition::print()
{
	std::cout << "Poets:\n";
	for (int i = 0; i < poets.size(); ++i) {
		std::cout << i + 1 << ") " << poets[i].getFullName() << std::endl;
	}
	std::cout << std::endl;

	std::cout << "Romantics:\n";
	for (int i = 0; i < romantics.size(); ++i) {
		std::cout << i + 1 << ") " << romantics[i].getFullName() << std::endl;
	}
	std::cout << std::endl;

	std::cout << "Fantastics:\n";
	for (int i = 0; i < fantasts.size(); ++i) {
		std::cout << i + 1 << ") " << fantasts[i].getFullName() << std::endl;
	}
	std::cout << std::endl;
}
