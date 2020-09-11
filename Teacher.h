#pragma once
#include <iostream>
#include <cstring>
#include <Windows.h>
#include "Stud.h"

class Teacher {
public:
	void set_mis_les(Student& param) {
		int temp = param.mis_les;

		do {
			/*		system("CLS");*/
			std::cout << "Для " << param.first_name << " " << param.sec_name
				<< " " << param.third_name << " установите кол-во пропусков (от 0 до 63): ";
			std::cin >> param.mis_les;														//Установка кол-ва пропусков
			if (param.mis_les > 63) {
				/*	system("CLS");*/
				std::cout << "\n\n\t\tВы вышли за рамки!"
					<< "\n\n\t\tВведите заново!";
				Sleep(2000);
				continue;
			}
			break;
		} while (true);
		if (param.mis_les < 0) {
			/*system("CLS");*/
			std::cout << "\n\n\t\tБез замены!";
			Sleep(2000);
			param.mis_les = temp;
		}
	}
};