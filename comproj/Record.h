#ifndef __RECORD_H__
#define __RECORD_H__
#include <iostream>
using namespace std;
class Record{
private:
	int id;	//����/�����
	int day; //����
	int month; //�����
	int year; //���
	int hour; //���
	int min; //������
	string lname;  //�������
	string fname;  //���
	string patron; //��������
	long long number; //����� ��������
	string master; //��� �������
	string type; //��� ������
	int price; //����
public:
	Record(int sid, int sday, int smonth, int syear, int shour, int smin,	//�����������
		string slname, string sfname, string spatron, long long snumber, string smaster,
		string stype, int sprice);
	~Record(); //����������
	//�������
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
	//�������
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