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

	IElectronics *electronics[kGoodCount]; // ћассив указателей на абстрактный базовый класс
	electronics[0] = new Player("Sony", "Walkman NW-A105B", 72, 100); // Ёкземпл€р дочернего класса портативной электроники
	electronics[1] = new Laptop("Honor", "MagicBook 16 R5/16/512", 4, 1800,  15.6, 16384, 512);	// ѕример ромбовидного наследовани€
	electronics[2] = new WashingMachine("Haier", "HW60-BP10959A", 64000, 8, 1200); // Ёкземпл€р дочернего класса бытовой электроники
	electronics[3] = new Smartphone("Samsung", "Galaxy S22", 36, kAndroid, 8, 256); // Ёкземпл€р дочернего класса портативной электроники
	electronics[4] = new Hob("Haier", "HHY-Y53NVB", 7800, kInduction, 3, 8000); // Ёкземпл€р дочернего класса бытовой электроники

	setlocale(LC_ALL, "");
	bool loop = true;
	do {
		int choice;
		std::cout << "\n¬ыберите продукт:\n1 - плеер,\n"
			"2 - ноутбук,\n"
			"3 - стиральна€ машина,\n"
			"4 - смартфон,\n"
			"5 - варочна€ панель;\n"
			"0 - выход" << std::endl;
		std::cin >> choice;
		if (choice == 0) {
			std::cout << "\n¬ыходим из программы..." << std::endl;
			loop = false;
		}
		else if (choice >= 1 && choice <= kGoodCount) {
			std::cout << "\n";
			electronics[choice - 1]->ShowSpec();
		}
		else {
			std::cout << "Ќеизвестный товар: повторите выбор, пожалуйста...\n" << std::endl;
		}
	} while (loop);

	for (int i = 0; i < kGoodCount; ++i) {
		delete electronics[i];
	}
	return 0;
}