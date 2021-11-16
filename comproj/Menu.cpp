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
	if (ptrRecordList->FindId(sid)){
		ptrRecordList->Delete(sid);	//вызываем метод удаления класса списка записей
	}
	else
		cout << "Запись не найдена." << endl;
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

void Menu::InputRecord(){	//ввод записи
	int sid; //ид
	int sday;	//день
	int smonth;	//месяц
	int syear;	//год
	int shour;	//час
	int smin;	//минуты
	string slname;	//фамилия
	string sfname;	//имя
	string spatron;	//отчество
	long long snumber;	//номер
	string smaster;	//имя мастера
	string stype;	//тип
	int sprice;	//стоимость
	do{
		cout << "\n\nВведите id записи:";
		enterInt(&sid);//функция ввода целого числа
		if (sid > 900)
			cout << "Слишком большое id" << endl;
		if (ptrRecordList->FindId(sid) != NULL)
			cout << "Запись с таким id уже существует, повторите ввод." << endl;
	} while ((!checkNegative(sid)) || (sid > 900) || (ptrRecordList->FindId(sid) != NULL)); //условие выполнения, не отриц, 
	//не больше 900, нет такого ид
	do{
		cout << "Введите день:";
		enterInt(&sday);
	} while (!checkDay(sday));
	////////////////////////
	do{
		cout << "Введите месяц:";
		enterInt(&smonth);
	} while (!checkMonth(smonth));
	////////////////////////
	cout << "Введите год:";
	do{
		enterInt(&syear);
	} while (!checkYear(syear));
	////////////////////////
	do{
		cout << "Введите часы:";
		enterInt(&shour);
	} while (!checkHour(shour));
	////////////////////////

	do{
		cout << "Введите минуты:";
		enterInt(&smin);
	} while (!checkMin(smin));
	////////////////////////
	do{
		cout << "Введите Имя:";
		sfname.clear();
		getline(cin, sfname);
		if (sfname.size() > 12)
			cout << "Слишком длинная строка" << endl;
	} while (sfname.size() > 12);
	////////////////////////
	do{
		cout << "Введите Фамилию:";
		slname.clear();
		getline(cin, slname);
		if (slname.size() > 12)
			cout << "Слишком длинная строка" << endl;
	} while (slname.size() > 12);
	////////////////////////
	do{
		cout << "Введите Отчество:";
		spatron.clear();
		getline(cin, spatron);
		if (spatron.size() > 12)
			cout << "Слишком длинная строка" << endl;
	} while (spatron.size() > 12);
	////////////////////////
	do{
		cout << "Введите номер телефона(В формате 89000000000):";
		enterLongLong(&snumber);
	} while (!checkNumber(snumber));
	////////////////////////
	do{
		cout << "Введите имя мастера:";
		smaster.clear();
		getline(cin, smaster);
		if (smaster.size() > 12)
			cout << "Слишком длинная строка" << endl;
	} while (smaster.size() > 12);
	////////////////////////
	do{
		cout << "Введите вид услуги:";
		stype.clear();
		getline(cin, stype);
		if (stype.size() > 15)
			cout << "Слишком длинная строка" << endl;
	} while (stype.size() > 15);
	////////////////////////
	do{
		cout << "Введите стоимость:";
		enterInt(&sprice);
	} while (!checkNegative(sprice));
	Record *ptrNewRec = new Record(sid, sday, smonth, syear, shour, smin, sfname, slname, spatron, snumber, smaster, stype, sprice);
	ptrRecordList->InsertRecord(ptrNewRec);
}

void Menu::EditRecord(){
	int sid;
	int sday;
	int smonth;
	int syear;
	int shour;
	int smin;
	string slname;
	string sfname;
	string spatron;
	long long snumber;
	string smaster;
	string stype;
	int sprice;
	Record* eRec;
	do{
		cout << "\n\nВведите id записи для редактирования:";
		enterInt(&sid);
	} while (!checkNegative(sid));
	if (eRec = ptrRecordList->FindId(sid)){
		printHeader();
		printFooter();
		eRec->Print();
		printFooter();
		cout << endl;
		do{
			cout << "Введите день:";
			enterInt(&sday);
		} while (!checkDay(sday));
		eRec->SetDay(sday);
		////////////////////////
		do{
			cout << "Введите месяц:";
			enterInt(&smonth);
		} while (!checkMonth(smonth));
		eRec->SetMonth(smonth);
		////////////////////////
		do{
			cout << "Введите год(В формате 0000):";
			enterInt(&syear);
		} while (!checkYear(syear));
		eRec->SetYear(syear);
		////////////////////////
		do{
			cout << "Введите часы:";
			enterInt(&shour);
		} while (!checkHour(shour));
		eRec->SetHour(shour);
		////////////////////////
		do{
			cout << "Введите минуты:";
			enterInt(&smin);
		} while (!checkMin(smin));
		eRec->SetMin(smin);
		////////////////////////
		do{
			cout << "Введите Имя:";
			sfname.clear();
			getline(cin, sfname);
			if (sfname.size() > 12)
				cout << "Слишком длинная строка" << endl;
		} while (sfname.size() > 12);
		eRec->SetFname(sfname);
		////////////////////////
		do{
			cout << "Введите Фамилию:";
			slname.clear();
			getline(cin, slname);
			if (slname.size() > 12)
				cout << "Слишком длинная строка" << endl;
		} while (slname.size() > 12);
		eRec->SetLname(slname);
		////////////////////////
		do{
			cout << "Введите Отчество:";
			spatron.clear();
			getline(cin, spatron);
			if (spatron.size() > 12)
				cout << "Слишком длинная строка" << endl;
		} while (spatron.size() > 12);
		eRec->SetPatron(spatron);
		////////////////////////
		do{
			cout << "Введите номер телефона(В формате 89000000000):";
			enterLongLong(&snumber);
		} while (!checkNumber(snumber));
		eRec->SetNumber(snumber);
		////////////////////////
		do{
			cout << "Введите имя мастера:";
			smaster.clear();
			getline(cin, smaster);
			if (smaster.size() > 12)
				cout << "Слишком длинная строка" << endl;
		} while (smaster.size() > 12);
		eRec->SetMaster(smaster);
		////////////////////////
		do{
			cout << "Введите вид услуги:";
			stype.clear();
			getline(cin, stype);
			if (stype.size() > 15)
				cout << "Слишком длинная строка" << endl;
		} while (stype.size() > 15);
		eRec->SetType(stype);
		////////////////////////
		do{
			cout << "Введите стоимость:";
			enterInt(&sprice);
		} while (!checkNegative(sprice));
		eRec->SetPrice(sprice);
	}
	else
		cout << "Запись не найдена" << endl;
}