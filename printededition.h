#pragma once

#include "vector.h"

#include "poet.h"
#include "fantast.h"
#include "romanticist.h"

#include <fstream>
#include <sstream>

class PrintedEdition {
public:
	PrintedEdition();
	~PrintedEdition();

	void writeToFile();
	void readFromFile();

	void push_backPoet();
	void push_backFantst();
	void push_backRomantic();

	void deletePoet();
	void deleteFantst();
	void deleteRomantic();

	void editPoet();
	void editFantst();
	void editRomantic();

	void print();

private:
	MyVector<Poet> poets;
	MyVector<FantasyAuthor> fantasts;
	MyVector<Romanticist> romantics;
};