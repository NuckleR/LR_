#pragma once
#include <iostream>
#include <cstring>
#include <Windows.h>

class Student {
private:
	std::string first_name, sec_name, third_name;
	int id;
	int mis_les;

public:
	Student() {					//����������� �� ���������
		id = 0;
		mis_les = 0;
	}
	Student(int ID, int MIS) {		//����������� �������������
		id = ID;
		mis_les = MIS;
	}
	~Student() {						//����������
		std::cout << "\n\t\t����� ����������� ��������: " << first_name
			<< "\n\t\t����� ����������� ��������: " << sec_name
			<< "\n\t\t����� ����������� ��������: " << third_name
			<< "\n\t\t����� ����������� ��������: " << id
			<< "\n\t\t����� ����������� ��������: " << mis_les;
		Sleep(2000);
	}
	Student(const Student& stud) :					//����������� �����������
		first_name(stud.first_name), sec_name(stud.sec_name),
		third_name(stud.third_name), id(stud.id),
		mis_les(stud.mis_les)
	{
		std::cout << "\n\n\t\t��������� ����������� �����������";
		Sleep(1000);
	}
	void set_name(std::string f_name, std::string s_name,
		std::string t_name) {
		first_name = f_name;
		sec_name = s_name;
		third_name = t_name;
	}
	void set_id(int ID) {
		id = ID;
	}
	void set_mis(int MIS) {
		mis_les = MIS;
	}
	std::string get_f_name() {
		return first_name;
	}
	std::string get_s_name() {
		return sec_name;
	}
	std::string get_t_name() {
		return third_name;
	}
	int get_mis_les() {
		return mis_les;
	}
	int get_id() {
		return id;
	}

	friend class Teacher;		//������������� �����
	friend void show_stud_data(Student& param);		//������������� �������
	friend void show_cond(Student& param);
};
