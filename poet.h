#pragma once
#include "book.h"

class Poet : public Book {
public:
	Poet();
	Poet(std::string& name, std::string& years, std::string& works);
	~Poet();

	void setFCs(std::string& name);
	void setYearOfLife(std::string& years);
	void setWorks(std::string& _works);

	std::string getFullName() override;
	std::string getYearsOfLife();
	std::string getWorks();

private:
	std::string FCs;
	std::string years_of_life;
	std::string works;
};