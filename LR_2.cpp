#include <iostream>
#include <cstring>
#include <string>
#include <Windows.h>
#include "Stud.h"
#include "Teacher.h"

//@mail: nuckler228@gmail.com
//�����: NuckleR
//������: qw3543Ymcc

//--------------------------------------------------------------------------- ������ ------------------------------------------------------------------------------------
//class Student {
//	private:
//		std::string first_name, sec_name, third_name;
//		int id;
//		int mis_les;
//
//	public:
//		Student() {					//����������� �� ���������
//			id = 0;
//			mis_les = 0;
//		}
//		Student(int ID , int MIS ) {		//����������� �������������
//			id = ID;
//			mis_les = MIS;
//		}
//		~Student() {						//����������
//			std::cout << "\n\t\t����� ����������� ��������: " << first_name
//				<< "\n\t\t����� ����������� ��������: " << sec_name
//				<< "\n\t\t����� ����������� ��������: " << third_name
//				<< "\n\t\t����� ����������� ��������: " << id
//				<< "\n\t\t����� ����������� ��������: " << mis_les;
//			Sleep(2000);
//		}
//		Student(const Student& stud) :					//����������� �����������
//			first_name(stud.first_name), sec_name(stud.sec_name),
//			third_name(stud.third_name), id(stud.id),
//			mis_les(stud.mis_les)
//		{
//			std::cout << "\n\n\t\t��������� ����������� �����������";
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
//		friend class Teacher;		//������������� �����
//		friend void show_stud_data(Student& param);		//������������� �������
//		friend void show_cond(Student& param);
//};

//class Teacher {
//	public:
//		void set_mis_les(Student& param) {
//			int temp = param.mis_les;
//
//			do {
//		/*		system("CLS");*/
//				std::cout << "��� " << param.first_name << " " << param.sec_name
//					<< " " << param.third_name << " ���������� ���-�� ��������� (�� 0 �� 63): ";
//				std::cin >> param.mis_les;														//��������� ���-�� ���������
//				if (param.mis_les > 63) {
//				/*	system("CLS");*/
//					std::cout << "\n\n\t\t�� ����� �� �����!"
//						<<"\n\n\t\t������� ������!";
//					Sleep(2000);
//					continue;
//				}
//				break;
//			} while (true);
//			if (param.mis_les < 0) {
//				/*system("CLS");*/
//				std::cout << "\n\n\t\t��� ������!";
//				Sleep(2000);
//				param.mis_les = temp;
//			}
//		}
//};
//----------------------------------------------------------------------------------------------------------------------------------------------------------------------

//----------------------------------------------------------------------- ������� --------------------------------------------------------------------------------------
int menu();
void show_stud_data(Student& param);
void show_cond(Student& param);
//----------------------------------------------------------------------------------------------------------------------------------------------------------------------

//---------------------------------------------------------------- ���� ���� � ������� ---------------------------------------------------------------------------------
int main() {
	system("chcp 1251");
	system("CLS");

	int ID = 1;
	class Teacher teach;
	Student stud[5], stud_alone_1, 
		stud_alone_2(3000, 0), stud_alone_3;
	std::string f_name, s_name, t_name;

	for (int i = 0; i < 5; i++) {
		std::cout << "������� ��� ���������: ";
		std::getline(std::cin, f_name);
		std::cout << "������� ������� ���������: ";
		std::getline(std::cin, s_name);
		std::cout << "������� �������� ���������: ";
		std::getline(std::cin, t_name);
		stud[i].set_id(i+1);

		stud[i].set_name(f_name, s_name, t_name);
		system("CLS");
	}
	stud_alone_1.set_name("�������", "������", "���������"); stud_alone_1.set_id(2000);
	stud_alone_2.set_name("����", "���������", "�����������");
	stud_alone_3.set_name("�����", "�������", "����������"); stud_alone_3.set_id(4000);
	

	while (true) {
		switch (menu()) {
		case 1: 
			for (int i = 0; i < 5; i++) {		//������ �������� ��������� � ���������
			show_stud_data(stud[i]);
		}
			ID = 1;
			  do {
				  if (ID < 1 || ID>5) {
					  std::cout << "\n\n\t\t������ ��������� �� ����������!";
					  Sleep(1500); break;
				  }
				  std::cout << "\n\n�������� id ���������: ";
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
				std::cout << "\n\n�������� id ���������: ";
				std::cin >> ID;
				if (ID != stud_alone_1.get_id() && ID != stud_alone_2.get_id()
					&& ID != stud_alone_3.get_id()) {
					std::cout << "\n\n\t\t������ ��������� �� ����������!";
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

void show_cond(Student &param) {		//������� ����������� ������������� ��������
	class Teacher teach;

	Student studCOPY(param);
	std::cout << "\n\n����� �� ���������: \n";
	show_stud_data(studCOPY);
	teach.set_mis_les(param);
	std::cout << "\n\n����� ����� ���������: \n";
	show_stud_data(param);
	std::cout << "\n\n"; system("pause");
}

void show_stud_data(Student &param) {    //������������� ������� ��� ������ ������ ������� �� �����
	std::cout << "==================================\n" << param.id
		<< ".\n���: " << param.first_name
		<< "\n�������: " << param.sec_name
		<< "\n��������: " << param.third_name
		<< "\n���-�� ���������: " << param.mis_les
		<< "\n=================================\n\n";
}

int menu() {		//������� ���� ������ ��� �������� �� �����
	int k=0;

	do {
		system("CLS");
		if (k < 0 || k>2) {
			std::cout << "\n\n\t\t������ ������ � ���� �� ����������!";
			Sleep(2000);  system("CLS");
		}
		std::cout << "=================================\n"
			<< "1 - ����� �������� ��� ����������� ���������\n"
			<< "2 - ��������� ��������\n"
			<< "0 - �����\n"
			<< "=================================\n";
		std::cin >> k;
	} while (k < 0 || k >2);

	system("CLS");

	return k;
}
//---------------------------------------------------------------------------------------------------------------------------------------------------------------------