#include <iostream>

#include "printededition.h"

int main() {
	PrintedEdition pe;

	bool run = true;

	while (run) {
		system("cls");
		std::cout << "1. Add\n";
		std::cout << "2. Delete\n";
		std::cout << "3. Edit\n";
		std::cout << "4. Print\n";
		std::cout << "5. Read from file\n";
		std::cout << "6. Write to file\n";
		std::cout << "7. Exit\n";

		int index = 0;
		std::cout << "Choose index: ";
		std::cin >> index;

		if (index == 1) {
			system("cls");
			std::cout << "1. Poet\n";
			std::cout << "2. Fantast\n";
			std::cout << "3. Romantic\n";
			std::cout << "Choose index: ";
			int choice;
			std::cin >> choice;

			if (choice == 1) {
				pe.push_backPoet();
			}
			if (choice == 2) {
				pe.push_backFantst();
			}
			if (choice == 3) {
				pe.push_backRomantic();
			}

			system("pause");
		}

		if (index == 2) {
			system("cls");
			std::cout << "1. Poet\n";
			std::cout << "2. Fantast\n";
			std::cout << "3. Romantic\n";
			std::cout << "Choose index: ";
			int choice;
			std::cin >> choice;

			if (choice == 1) {
				pe.deletePoet();
			}
			if (choice == 2) {
				pe.deleteFantst();
			}
			if (choice == 3) {
				pe.deleteRomantic();
			}
			system("pause");
		}

		if (index == 3) {
			system("cls");
			std::cout << "1. Poet\n";
			std::cout << "2. Fantast\n";
			std::cout << "3. Romantic\n";
			std::cout << "Choose index: ";
			int choice;
			std::cin >> choice;

			if (choice == 1) {
				pe.editPoet();
			}
			if (choice == 2) {
				pe.editFantst();
			}
			if (choice == 3) {
				pe.editRomantic();
			}
			system("pause");
		}

		if (index == 4) {
			system("cls");
			pe.print();
			system("pause");
		}


		if (index == 5) {
			system("cls");
			pe.readFromFile();
			system("pause");
		}

		if (index == 6) {
			system("cls");
			pe.writeToFile();
			system("pause");
		}

		if (index == 7) {
			run = false;
		}
		else {
			std::cout << "Erorr index\n";
		}
	}
}

