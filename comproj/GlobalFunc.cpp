#include <iostream>
#include <iomanip>
#include "GlobalFunc.h"

using namespace std;

void printHeader(){
	cout << endl
		<< setw(3) << "id" << "|"
		<< setw(10) << "����" << "|"
		<< setw(6) << "�����" << "|"
		<< setw(12) << "�������" << " "
		<< setw(12) << "���" << " "
		<< setw(12) << "��������" << "|"
		<< setw(12) << "�������" << "|"
		<< setw(12) << "������" << "|"
		<< setw(15) << "��� ������" << "|"
		<< setw(4) << "����" << endl;
}

void printFooter(){
	cout << setw(3) << "---" << "+"
		<< setw(10) << "----------" << "+"
		<< setw(6) << "------" << "+"
		<< setw(12) << "-------------"
		<< setw(12) << "-------------"
		<< setw(12) << "------------" << "+"
		<< setw(12) << "------------" << "+"
		<< setw(12) << "------------" << "+"
		<< setw(15) << "---------------" << "+"
		<< setw(4) << "----";
}

int checkNegative(int num){//��������� �� ������������� �����
	if (num < 0){
		cout << "������� ��������������� �����" << endl;
		return 0;
	}
	return 1;
}

int checkNumber(long long snumber){//�������� ��������� ����� ������
	if (snumber < 0){
		cout << "������� ��������������� �����" << endl;
		return 0;
	}
	if (snumber < 80000000000 || snumber > 90000000000){
		cout << "������ ����� ������ ��������" << endl;
		return 0;
	}
	return 1;
}

int checkDay(int sday){//�������� ��������� ����� ���
	if (checkNegative(sday)){
		if (sday > 31 || sday == 0){
			cout << "������ ����� ���" << endl;
			return 0;
		}
	}
	else 
		return 0;
	return 1;
}

int checkMonth(int smonth){//�������� ��������� ����� ������
	if (checkNegative(smonth)){
		if (smonth > 12 || smonth == 0){
			cout << "������ ����� ������" << endl;
			return 0;
		}
	}
	else 
		return 0;
	return 1;
}

int checkYear(int syear){//�������� ��������� ����� ����
	if (syear < 2020 || syear > 2030){
		cout << "������ ����� ����" << endl;
		return 0;
	}
	else 
		return 0;
	return 1;
}

int checkHour(int shour){//�������� ��������� ����� �����
	if (checkNegative(shour)){
		if (shour > 23){
			cout << "������ ����� �����" << endl;
			return 0;
		}
	}
	return 1;
}

int checkMin(int smin){//�������� ��������� ����� �����
	if (checkNegative(smin)){
		if (smin > 60){
			cout << "������ ����� �����" << endl;
			return 0;
		}
	}
	return 1;
}

void enterInt(int *i){ //���� ������ �����
	while (!(cin >> *i)){	//���� ���� �����������
		cin.clear();	//������� ����� ������
		cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');//���������� ��� �������
		cout << "�������� ����." << endl;
	}
	cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');	//��� ��� ���������� ��� �������
	//�� ������, ���� �������� \0 \n � ��.
}

void enterLongLong(long long *l){
	while (!(cin >> *l)){//���� ���� �����������
		cin.clear();//������� ����� ������
		cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');//���������� ��� �������
		cout << "�������� ����." << endl;
	}
	cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');	//��� ��� ���������� ��� �������
}																	//�� ������, ���� �������� \0 \n � ��.