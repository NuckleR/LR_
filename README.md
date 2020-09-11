#include <iostream>
#include <cstring>
#include <string>
#include <Windows.h>
#include "Stud.h"
#include "Teacher.h"

//--------------------------------------------------------------------------- Классы ------------------------------------------------------------------------------------
//class Student {
//	private:
//		std::string first_name, sec_name, third_name;
//		int id;
//		int mis_les;
//
//	public:
//		Student() {					//Конструктор по умолчанию
//			id = 0;
//			mis_les = 0;
//		}
//		Student(int ID , int MIS ) {		//Конструктор инициализации
//			id = ID;
//			mis_les = MIS;
//		}
//		~Student() {						//Деструктор
//			std::cout << "\n\t\tВызов деструктора удаление: " << first_name
//				<< "\n\t\tВызов деструктора удаление: " << sec_name
//				<< "\n\t\tВызов деструктора удаление: " << third_name
//				<< "\n\t\tВызов деструктора удаление: " << id
//				<< "\n\t\tВызов деструктора удаление: " << mis_les;
//			Sleep(2000);
//		}
//		Student(const Student& stud) :					//Конструктор копирования
//			first_name(stud.first_name), sec_name(stud.sec_name),
//			third_name(stud.third_name), id(stud.id),
//			mis_les(stud.mis_les)
//		{
//			std::cout << "\n\n\t\tЗаработал конструктор копирования";
//			Sleep(1000);
//		}
//		void set_name(std::string f_name, std::string s_name, 
//							std::string t_name) {
//			first_name = f_name;
//			sec_name = s_name;
//			third_name = t_name;
//		}
//		void set_id(int ID) {
//			id = ID;
//		}
//		void set_mis(int MIS) {
//			mis_les = MIS;
//		}
//		std::string get_f_name() {
//			return first_name;
//		}
//		std::string get_s_name() {
//			return sec_name;
//		}
//		std::string get_t_name() {
//			return third_name;
//		}
//		int get_mis_les() {
//			return mis_les;
//		}
//		int get_id() {
//			return id;
//		}
//
//		friend class Teacher;		//Дружественный класс
//		friend void show_stud_data(Student& param);		//Дружественная функция
//		friend void show_cond(Student& param);
//};

//class Teacher {
//	public:
//		void set_mis_les(Student& param) {
//			int temp = param.mis_les;
//
//			do {
//		/*		system("CLS");*/
//				std::cout << "Для " << param.first_name << " " << param.sec_name
//					<< " " << param.third_name << " установите кол-во пропусков (от 0 до 63): ";
//				std::cin >> param.mis_les;														//Установка кол-ва пропусков
//				if (param.mis_les > 63) {
//				/*	system("CLS");*/
//					std::cout << "\n\n\t\tВы вышли за рамки!"
//						<<"\n\n\t\tВведите заново!";
//					Sleep(2000);
//					continue;
//				}
//				break;
//			} while (true);
//			if (param.mis_les < 0) {
//				/*system("CLS");*/
//				std::cout << "\n\n\t\tБез замены!";
//				Sleep(2000);
//				param.mis_les = temp;
//			}
//		}
//};
//----------------------------------------------------------------------------------------------------------------------------------------------------------------------

//----------------------------------------------------------------------- Функции --------------------------------------------------------------------------------------
int menu();
void show_stud_data(Student& param);
void show_cond(Student& param);
//----------------------------------------------------------------------------------------------------------------------------------------------------------------------

//---------------------------------------------------------------- Тело кода и функций ---------------------------------------------------------------------------------
int main() {
	system("chcp 1251");
	system("CLS");

	int ID = 1;
	class Teacher teach;
	Student stud[5], stud_alone_1, 
		stud_alone_2(3000, 0), stud_alone_3;
	std::string f_name, s_name, t_name;

	for (int i = 0; i < 5; i++) {
		std::cout << "Введите имя школьника: ";
		std::getline(std::cin, f_name);
		std::cout << "Введите фамилию школьника: ";
		std::getline(std::cin, s_name);
		std::cout << "Введите отчество школьника: ";
		std::getline(std::cin, t_name);
		stud[i].set_id(i+1);

		stud[i].set_name(f_name, s_name, t_name);
		system("CLS");
	}
	stud_alone_1.set_name("Василий", "Анонов", "Гуппиевич"); stud_alone_1.set_id(2000);
	stud_alone_2.set_name("Иван", "Горемыков", "Григорьевич");
	stud_alone_3.set_name("Артем", "Обломов", "Кириллович"); stud_alone_3.set_id(4000);
	

	while (true) {
		switch (menu()) {
		case 1: 
			for (int i = 0; i < 5; i++) {		//Случай внесения изменений в школьника
			show_stud_data(stud[i]);
		}
			ID = 1;
			  do {
				  if (ID < 1 || ID>5) {
					  std::cout << "\n\n\t\tТакого школьника не существует!";
					  Sleep(1500); break;
				  }
				  std::cout << "\n\nВыберите id школьника: ";
					  std::cin >> ID;
			  } while (ID < 1 && ID>5);
			  if (ID >= 1 && ID <= 5) {
				  show_cond(stud[ID-1]);
			  }
			  continue;
		case 2: 
			show_stud_data(stud_alone_1);
			show_stud_data(stud_alone_2);
			show_stud_data(stud_alone_3);
			ID = 1;
			do {
				std::cout << "\n\nВыберите id школьника: ";
				std::cin >> ID;
				if (ID != stud_alone_1.get_id() && ID != stud_alone_2.get_id()
					&& ID != stud_alone_3.get_id()) {
					std::cout << "\n\n\t\tТакого школьника не существует!";
					Sleep(1500); break;
				}
			} while (ID != stud_alone_1.get_id() && ID != stud_alone_2.get_id()
				&& ID != stud_alone_3.get_id());
			if (ID == stud_alone_1.get_id()) {
				show_cond(stud_alone_1);
			}
			else if (ID == stud_alone_2.get_id()) {
				show_cond(stud_alone_2);
			}
			else if (ID == stud_alone_3.get_id()) {
				show_cond(stud_alone_3);
			}
			continue;
		case 0: return 0;
		}
	}

}

void show_cond(Student &param) {		//Функция мониторинга промежуточных операций
	class Teacher teach;

	Student studCOPY(param);
	std::cout << "\n\nВывод до обработки: \n";
	show_stud_data(studCOPY);
	teach.set_mis_les(param);
	std::cout << "\n\nВывод после обработки: \n";
	show_stud_data(param);
	std::cout << "\n\n"; system("pause");
}

void show_stud_data(Student &param) {    //Дружественная функция для вывода данных объекта на экран
	std::cout << "==================================\n" << param.id
		<< ".\nИмя: " << param.first_name
		<< "\nФамилия: " << param.sec_name
		<< "\nОтчество: " << param.third_name
		<< "\nКол-во пропусков: " << param.mis_les
		<< "\n=================================\n\n";
}

int menu() {		//Обычное меню выбора без проверки на числа
	int k=0;

	do {
		system("CLS");
		if (k < 0 || k>2) {
			std::cout << "\n\n\t\tТакого пункта в меню не существует!";
			Sleep(2000);  system("CLS");
		}
		std::cout << "=================================\n"
			<< "1 - вывод учеников для выставления пропусков\n"
			<< "2 - обработка одиночек\n"
			<< "0 - выход\n"
			<< "=================================\n";
		std::cin >> k;
	} while (k < 0 || k >2);

	system("CLS");

	return k;
}
//---------------------------------------------------------------------------------------------------------------------------------------------------------------------
