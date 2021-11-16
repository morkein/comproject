#include <iostream>
#include "Record.h"
#include <string>
#include <iomanip>

Record::Record(int sid, int sday, int smonth, int syear, int shour, int smin,//конструктор
	string slname, string sfname, string spatron, long long snumber, string smaster,
	string stype, int sprice) :id(sid), day(sday), month(smonth), year(syear),
	hour(shour), min(smin), lname(slname), fname(sfname), patron(spatron),
	number(snumber), master(smaster), type(stype), price(sprice){
}
Record::~Record(){//деструктор

}
//Геттеры
int Record::GetId(){
	return id;
}
int Record::GetDay(){
	return day;
}
int Record::GetMonth(){
	return month;
}
int Record::GetYear(){
	return year;
}
int Record::GetHour(){
	return hour;
}
int Record::GetMin(){
	return min;
}
string Record::GetLname(){
	return lname;
}
string Record::GetFname(){
	return fname;
}
string Record::GetPatron(){
	return patron;
}
long long Record::GetNumber(){
	return number;
}
string Record::GetMaster(){
	return master;
}
string Record::GetType(){
	return type;
}
int Record::GetPrice(){
	return price;
}

//Сеттеры
void Record::SetId(int sid){
	id = sid;
	return;
}
void Record::SetDay(int sday){
	day = sday;
	return;
}
void Record::SetMonth(int smonth){
	month = smonth;
	return;
}
void Record::SetYear(int syear){
	year = syear;
	return;
}
void Record::SetHour(int shour){
	hour = shour;
	return;
}
void Record::SetMin(int smin){
	min = smin;
	return;
}
void Record::SetLname(string slname){
	lname = slname;
	return;
}
void Record::SetFname(string sfname){
	fname = sfname;
	return;
}
void Record::SetPatron(string spatron){
	patron = spatron;
	return;
}
void Record::SetNumber(long long snumber){
	number = snumber;
	return;
}
void Record::SetMaster(string smaster){
	master = smaster;
	return;
}
void Record::SetType(string stype){
	type = stype;
	return;
}
void Record::SetPrice(int sprice){
	price = sprice;
	return;
}
void Record::Print(){	//метод вывода полей класса запись
	cout << endl
		<< setw(3) << GetId() << "|"
		<< setw(2) << GetDay() << "."
		<< setw(2) << GetMonth() << "."
		<< setw(4) << GetYear() << "|"
		<< setw(3) << GetHour() << ":"
		<< setw(2) << GetMin() << "|"
		<< setw(12) << GetLname() << " "
		<< setw(12) << GetFname() << " "
		<< setw(12) << GetPatron() << "|"
		<< setw(12) << GetNumber() << "|"
		<< setw(12) << GetMaster() << "|"
		<< setw(15) << GetType() << "|"
		<< setw(4) << GetPrice() << endl;
}