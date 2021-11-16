#ifndef __MENU_H__
#define __MENU_H__

#include "RecordList.h"

using namespace std;
class Menu{
private:
	RecordList* ptrRecordList;// указатель на список записей
public:
	Menu();//конструктор
	~Menu();//деструктор
	void InputRecord();	//ввод записи в список
	void EditRecord();	//редактирование записи
	void DeleteRecord();//удаление записи
	void DisplayList();//вывод списка
	void Update();	//обновление меню
};

#endif