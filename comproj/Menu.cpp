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
	if (ptrRecordList->FindId(sid)){
		ptrRecordList->Delete(sid);	//�������� ����� �������� ������ ������ �������
	}
	else
		cout << "������ �� �������." << endl;
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

void Menu::InputRecord(){	//���� ������
	int sid; //��
	int sday;	//����
	int smonth;	//�����
	int syear;	//���
	int shour;	//���
	int smin;	//������
	string slname;	//�������
	string sfname;	//���
	string spatron;	//��������
	long long snumber;	//�����
	string smaster;	//��� �������
	string stype;	//���
	int sprice;	//���������
	do{
		cout << "\n\n������� id ������:";
		enterInt(&sid);//������� ����� ������ �����
		if (sid > 900)
			cout << "������� ������� id" << endl;
		if (ptrRecordList->FindId(sid) != NULL)
			cout << "������ � ����� id ��� ����������, ��������� ����." << endl;
	} while ((!checkNegative(sid)) || (sid > 900) || (ptrRecordList->FindId(sid) != NULL)); //������� ����������, �� �����, 
	//�� ������ 900, ��� ������ ��
	do{
		cout << "������� ����:";
		enterInt(&sday);
	} while (!checkDay(sday));
	////////////////////////
	do{
		cout << "������� �����:";
		enterInt(&smonth);
	} while (!checkMonth(smonth));
	////////////////////////
	cout << "������� ���:";
	do{
		enterInt(&syear);
	} while (!checkYear(syear));
	////////////////////////
	do{
		cout << "������� ����:";
		enterInt(&shour);
	} while (!checkHour(shour));
	////////////////////////

	do{
		cout << "������� ������:";
		enterInt(&smin);
	} while (!checkMin(smin));
	////////////////////////
	do{
		cout << "������� ���:";
		sfname.clear();
		getline(cin, sfname);
		if (sfname.size() > 12)
			cout << "������� ������� ������" << endl;
	} while (sfname.size() > 12);
	////////////////////////
	do{
		cout << "������� �������:";
		slname.clear();
		getline(cin, slname);
		if (slname.size() > 12)
			cout << "������� ������� ������" << endl;
	} while (slname.size() > 12);
	////////////////////////
	do{
		cout << "������� ��������:";
		spatron.clear();
		getline(cin, spatron);
		if (spatron.size() > 12)
			cout << "������� ������� ������" << endl;
	} while (spatron.size() > 12);
	////////////////////////
	do{
		cout << "������� ����� ��������(� ������� 89000000000):";
		enterLongLong(&snumber);
	} while (!checkNumber(snumber));
	////////////////////////
	do{
		cout << "������� ��� �������:";
		smaster.clear();
		getline(cin, smaster);
		if (smaster.size() > 12)
			cout << "������� ������� ������" << endl;
	} while (smaster.size() > 12);
	////////////////////////
	do{
		cout << "������� ��� ������:";
		stype.clear();
		getline(cin, stype);
		if (stype.size() > 15)
			cout << "������� ������� ������" << endl;
	} while (stype.size() > 15);
	////////////////////////
	do{
		cout << "������� ���������:";
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
		cout << "\n\n������� id ������ ��� ��������������:";
		enterInt(&sid);
	} while (!checkNegative(sid));
	if (eRec = ptrRecordList->FindId(sid)){
		printHeader();
		printFooter();
		eRec->Print();
		printFooter();
		cout << endl;
		do{
			cout << "������� ����:";
			enterInt(&sday);
		} while (!checkDay(sday));
		eRec->SetDay(sday);
		////////////////////////
		do{
			cout << "������� �����:";
			enterInt(&smonth);
		} while (!checkMonth(smonth));
		eRec->SetMonth(smonth);
		////////////////////////
		do{
			cout << "������� ���(� ������� 0000):";
			enterInt(&syear);
		} while (!checkYear(syear));
		eRec->SetYear(syear);
		////////////////////////
		do{
			cout << "������� ����:";
			enterInt(&shour);
		} while (!checkHour(shour));
		eRec->SetHour(shour);
		////////////////////////
		do{
			cout << "������� ������:";
			enterInt(&smin);
		} while (!checkMin(smin));
		eRec->SetMin(smin);
		////////////////////////
		do{
			cout << "������� ���:";
			sfname.clear();
			getline(cin, sfname);
			if (sfname.size() > 12)
				cout << "������� ������� ������" << endl;
		} while (sfname.size() > 12);
		eRec->SetFname(sfname);
		////////////////////////
		do{
			cout << "������� �������:";
			slname.clear();
			getline(cin, slname);
			if (slname.size() > 12)
				cout << "������� ������� ������" << endl;
		} while (slname.size() > 12);
		eRec->SetLname(slname);
		////////////////////////
		do{
			cout << "������� ��������:";
			spatron.clear();
			getline(cin, spatron);
			if (spatron.size() > 12)
				cout << "������� ������� ������" << endl;
		} while (spatron.size() > 12);
		eRec->SetPatron(spatron);
		////////////////////////
		do{
			cout << "������� ����� ��������(� ������� 89000000000):";
			enterLongLong(&snumber);
		} while (!checkNumber(snumber));
		eRec->SetNumber(snumber);
		////////////////////////
		do{
			cout << "������� ��� �������:";
			smaster.clear();
			getline(cin, smaster);
			if (smaster.size() > 12)
				cout << "������� ������� ������" << endl;
		} while (smaster.size() > 12);
		eRec->SetMaster(smaster);
		////////////////////////
		do{
			cout << "������� ��� ������:";
			stype.clear();
			getline(cin, stype);
			if (stype.size() > 15)
				cout << "������� ������� ������" << endl;
		} while (stype.size() > 15);
		eRec->SetType(stype);
		////////////////////////
		do{
			cout << "������� ���������:";
			enterInt(&sprice);
		} while (!checkNegative(sprice));
		eRec->SetPrice(sprice);
	}
	else
		cout << "������ �� �������" << endl;
}