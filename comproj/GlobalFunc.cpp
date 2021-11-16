#include <iostream>
#include <iomanip>
#include "GlobalFunc.h"

using namespace std;

void printHeader(){
	cout << endl
		<< setw(3) << "id" << "|"
		<< setw(10) << "Дата" << "|"
		<< setw(6) << "Время" << "|"
		<< setw(12) << "Фамилия" << " "
		<< setw(12) << "Имя" << " "
		<< setw(12) << "Отчество" << "|"
		<< setw(12) << "Телефон" << "|"
		<< setw(12) << "Мастер" << "|"
		<< setw(15) << "Вид услуги" << "|"
		<< setw(4) << "Цена" << endl;
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

int checkNegative(int num){//прроверка на отрицательное число
	if (num < 0){
		cout << "Введите неотрицательное число" << endl;
		return 0;
	}
	return 1;
}

int checkNumber(long long snumber){//проверка диапазона ввода номера
	if (snumber < 0){
		cout << "Введите неотрицательное число" << endl;
		return 0;
	}
	if (snumber < 80000000000 || snumber > 90000000000){
		cout << "Ошибка ввода номера телефона" << endl;
		return 0;
	}
	return 1;
}

int checkDay(int sday){//проверка диапазона ввода дня
	if (checkNegative(sday)){
		if (sday > 31 || sday == 0){
			cout << "Ошибка ввода дня" << endl;
			return 0;
		}
	}
	else 
		return 0;
	return 1;
}

int checkMonth(int smonth){//проверка диапазона ввода месяца
	if (checkNegative(smonth)){
		if (smonth > 12 || smonth == 0){
			cout << "Ошибка ввода месяца" << endl;
			return 0;
		}
	}
	else 
		return 0;
	return 1;
}

int checkYear(int syear){//проверка диапазона ввода года
	if (syear < 2020 || syear > 2030){
		cout << "Ошибка ввода года" << endl;
		return 0;
	}
	else 
		return 0;
	return 1;
}

int checkHour(int shour){//проверка диапазона ввода часов
	if (checkNegative(shour)){
		if (shour > 23){
			cout << "Ошибка ввода часов" << endl;
			return 0;
		}
	}
	return 1;
}

int checkMin(int smin){//проверка диапазона ввода минут
	if (checkNegative(smin)){
		if (smin > 60){
			cout << "Ошибка ввода минут" << endl;
			return 0;
		}
	}
	return 1;
}

void enterInt(int *i){ //ввод целого числа
	while (!(cin >> *i)){	//пока ввод некорректен
		cin.clear();	//очищаем флаги ошибок
		cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');//пропускаем все символы
		cout << "Неверный ввод." << endl;
	}
	cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');	//еще раз пропускаем все символы
	//на случай, если остались \0 \n и др.
}

void enterLongLong(long long *l){
	while (!(cin >> *l)){//пока ввод некорректен
		cin.clear();//очищаем флаги ошибок
		cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');//пропускаем все символы
		cout << "Неверный ввод." << endl;
	}
	cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');	//еще раз пропускаем все символы
}																	//на случай, если остались \0 \n и др.