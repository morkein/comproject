#ifndef __MENU_H__
#define __MENU_H__

#include "RecordList.h"

using namespace std;
class Menu{
private:
	RecordList* ptrRecordList;// ��������� �� ������ �������
public:
	Menu();//�����������
	~Menu();//����������
	void InputRecord();	//���� ������ � ������
	void EditRecord();	//�������������� ������
	void DeleteRecord();//�������� ������
	void DisplayList();//����� ������
	void Update();	//���������� ����
};

#endif