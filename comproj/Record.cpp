#include <iostream>
#include "Record.h"
#include <string>

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