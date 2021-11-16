#include <iostream>
#include <string>
#include <iomanip>
#include <conio.h>
#include "GlobalFunc.h"
#include "Menu.h"

Menu::Menu(){
	ptrRecordList = new RecordList;//выделяем память под список
}

Menu::~Menu(){
	delete ptrRecordList;	//очищаем зарезервированную память
}
void Menu::DisplayList(){	//выводим список
	ptrRecordList->Display();	//метод класса списка записей
}

void Menu::DeleteRecord(){	//Удаление записи из списка
	int sid;
	do{
		cout << "\n\nВведите id записи для удаления:";
		enterInt(&sid);	//вводим ид
	} while (!checkNegative(sid));	//пока отрицательное
	ptrRecordList->Delete(sid);	//вызываем метод удаления класса списка записей
}

void Menu::Update(){	//обновление меню
	while (1){	//бесконечный, пока не нажат 0
		system("cls");
		cout << "1. Просмотр списка записей\n"
			<< "2. Добавить новую запись\n"
			<< "3. Редактировать существующую запись\n"
			<< "4. Удалить запись\n"
			<< "0. Выйти из программы" << endl;
		switch (_getch()){	//ждем нажатия клавиши 
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
		cout << "\nНажмите любую клавишу для продолженния...";
		_getch();//читаем символ, что бы не переходило к следуюшей итерации
	}
}