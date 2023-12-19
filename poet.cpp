#include "poet.h"

Poet::Poet()
{
	std::cout << "Defualt constructor\n";
}

Poet::Poet(std::string& name, std::string& years, std::string& _works) : FCs(name), years_of_life(years), works(_works){
	std::cout << "Constructor with name: " << name;
}

Poet::~Poet()
{
	std::cout << "Call up destructor";
}

void Poet::setFCs(std::string& name)
{
	FCs = name;
}

void Poet::setYearOfLife(std::string& years)
{
	years_of_life = years;
}

void Poet::setWorks(std::string& _works)
{
	works = _works;
}

std::string Poet::getFullName()
{
	return FCs;
}

std::string Poet::getYearsOfLife()
{
	return years_of_life;
}

std::string Poet::getWorks()
{
	return works;
}


