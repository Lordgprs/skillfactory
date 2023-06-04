#include "IElectronics.h"
#include "Device.h"
#include "Appliances.h"
#include "Player.h"
#include "Laptop.h"
#include "WashingMachine.h"
#include "Smartphone.h"
#include "Hob.h"
#include <iostream>

int main() {
	const int kGoodCount = 5;

	IElectronics *electronics[kGoodCount];
	electronics[0] = new Player("Sony", "Walkman NW-A105B", 72, 100);
	electronics[1] = new Laptop("Honor", "MagicBook 16 R5/16/512", 4, 1800,  15.6, 16384, 512);
	electronics[2] = new WashingMachine("Haier", "HW60-BP10959A", 64000, 8, 1200);
	electronics[3] = new Smartphone("Samsung", "Galaxy S22", 36, kAndroid, 8, 256);
	electronics[4] = new Hob("Haier", "HHY-Y53NVB", 7800, kInduction, 3, 8000);

	setlocale(LC_ALL, "");
	bool loop = true;
	do {
		int choice;
		std::cout << "\nВыберите продукт:\n1 - плеер,\n"
			"2 - ноутбук,\n"
			"3 - стиральная машина,\n"
			"4 - смартфон,\n"
			"5 - варочная панель;\n"
			"0 - выход" << std::endl;
		std::cin >> choice;
		if (choice == 0) {
			std::cout << "\nВыходим из программы..." << std::endl;
			loop = false;
		}
		else if (choice >= 1 && choice <= kGoodCount) {
			std::cout << "\n";
			electronics[choice - 1]->ShowSpec();
		}
		else {
			std::cout << "Неизвестный товар: повторите выбор, пожалуйста...\n" << std::endl;
		}
	} while (loop);

	for (int i = 0; i < kGoodCount; ++i) {
		delete electronics[i];
	}
	return 0;
}