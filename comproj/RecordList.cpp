#include <iostream>
#include <string>
#include <iomanip>
#include "RecordList.h"
#include "GlobalFunc.h"

using namespace std;

RecordList::~RecordList(){//�������� ������ �������
	while (!ptrRecord.empty()){//���� �� ������
		iter = ptrRecord.begin();//�������� �� ������
		delete *iter;//������� ���������� ������
		ptrRecord.erase(iter);//������� �������
	}
}
Record* RecordList::FindId(int sid){
	if (ptrRecord.empty()){	//���� ������
		return NULL;	//���������� ������ ���������
	}
	else{	//�����
		iter = ptrRecord.begin();	//������ �������� � ������ ������
		while (iter != ptrRecord.end()){	//���� �� �����
			if ((*iter)->GetId() == sid)	//���������� �������� � id ��������� ������
				return *iter;	//���� ����� =, �� ���������� ��������� �� �������
			*iter++;	//���� �� �����, �� ��������� � ����. ��������
		}
	}
	return NULL;	//���� ������ �� �����, ���������� ������ ���������
}

void RecordList::InsertRecord(Record* ptrR){
	ptrRecord.push_back(ptrR); //��������� � ����� ����� ������
}

void RecordList::Display(){
	if (ptrRecord.empty())	//���� ������ ������
		cout << "\n\n������ ������� ����, �������� ������." << endl;	//�����, ��� ������
	else //�����
	{
		printHeader();	//������� ��������� �������
		printFooter();
		iter = ptrRecord.begin();	//�������� � ������ ������
		while (iter != ptrRecord.end()){	//���� �������� �� � �����
			(*iter)->Print();	//�� ������� ������� �� ��������� ��� ������ ������
			printFooter();
			*iter++;	//� ���������� ��������
		}
	}
	return;
}

void RecordList::Delete(int sid){	//������� ������ � �����. id
	if (*iter = FindId(sid)){	//���� ����� ����� ������ � ����� id, ��
		delete *iter;//������� ���������� ������
		ptrRecord.erase(iter);//������� ���������
		cout << "\n\n������ �������." << endl;
	}
	else
		cout << "������ �� �������" << endl;
}