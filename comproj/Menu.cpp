#include <iostream>
#include <string>
#include <iomanip>
#include <conio.h>
#include "GlobalFunc.h"
#include "Menu.h"

Menu::Menu(){
	ptrRecordList = new RecordList;//�������� ������ ��� ������
}

Menu::~Menu(){
	delete ptrRecordList;	//������� ����������������� ������
}
void Menu::DisplayList(){	//������� ������
	ptrRecordList->Display();	//����� ������ ������ �������
}

void Menu::DeleteRecord(){	//�������� ������ �� ������
	int sid;
	do{
		cout << "\n\n������� id ������ ��� ��������:";
		enterInt(&sid);	//������ ��
	} while (!checkNegative(sid));	//���� �������������
	ptrRecordList->Delete(sid);	//�������� ����� �������� ������ ������ �������
}

void Menu::Update(){	//���������� ����
	while (1){	//�����������, ���� �� ����� 0
		system("cls");
		cout << "1. �������� ������ �������\n"
			<< "2. �������� ����� ������\n"
			<< "3. ������������� ������������ ������\n"
			<< "4. ������� ������\n"
			<< "0. ����� �� ���������" << endl;
		switch (_getch()){	//���� ������� ������� 
		case 49:{	//1
					system("cls");
					DisplayList();
					break;
		}
		case 50:{	//2
					system("cls");
					InputRecord();
					break;
		}
		case 51:{	//3
					system("cls");
					EditRecord();
					break;
		}
		case 52:{	//4
					system("cls");
					DeleteRecord();
					break;
		}
		case 48:{	//0
					return;
					break;
		}
		default: break;
		}
		cout << "\n������� ����� ������� ��� ������������...";
		_getch();//������ ������, ��� �� �� ���������� � ��������� ��������
	}
}