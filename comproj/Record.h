#ifndef __RECORD_H__
#define __RECORD_H__
#include <iostream>
using namespace std;
class Record{
private:
	int id;	//айди/номер
	int day; //день
	int month; //месяц
	int year; //год
	int hour; //час
	int min; //минута
	string lname;  //фамилия
	string fname;  //имя
	string patron; //отчество
	long long number; //номер телефона
	string master; //имя мастера
	string type; //вид услуги
	int price; //цена
public:
	Record(int sid, int sday, int smonth, int syear, int shour, int smin,	//конструктор
		string slname, string sfname, string spatron, long long snumber, string smaster,
		string stype, int sprice);
	~Record(); //деструктор
	//Геттеры
	int GetId();
	int GetDay();
	int GetMonth();
	int GetYear();
	int GetHour();
	int GetMin();
	string GetLname();
	string GetFname();
	string GetPatron();
	long long GetNumber();
	string GetMaster();
	string GetType();
	int GetPrice();
	//Сеттеры
	void SetId(int sid);
	void SetDay(int sday);
	void SetMonth(int smonth);
	void SetYear(int syear);
	void SetHour(int shour);
	void SetMin(int smin);
	void SetLname(string slname);
	void SetFname(string sfname);
	void SetPatron(string spatron);
	void SetNumber(long long snumber);
	void SetMaster(string smaster);
	void SetType(string stype);
	void SetPrice(int sprice);
};
#endif