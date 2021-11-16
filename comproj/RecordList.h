#ifndef __RECORDLIST_H__
#define __RECORDLIST_H__
#include <list>
#include "Record.h"
using namespace std;
class RecordList{
private:
	list<Record*> ptrRecord;	//��������� � ����������� �� ���������� ������ ������
	list<Record*>::iterator iter;	//��������
public:
	~RecordList();		//����������
	Record* FindId(int sid);	//����� ���������� �������� � ������ �� id
	void InsertRecord(Record*);	//�������� ������ �������� � ������
	void Display();	//����� ������
	void Delete(int sid);	//�������� �������� � id = ���������
};

#endif