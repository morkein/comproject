#ifndef __RECORDLIST_H__
#define __RECORDLIST_H__
#include <list>
#include "Record.h"
using namespace std;
class RecordList{
private:
	list<Record*> ptrRecord;	//контейнер с указателями на экземпляры класса запись
	list<Record*>::iterator iter;	//итератор
public:
	~RecordList();		//деструктор
	Record* FindId(int sid);	//метод нахождения элемента в списке по id
	void InsertRecord(Record*);	//Введение нового элемента в список
	void Display();	//вывод списка
	void Delete(int sid);	//удаление элемента с id = аргументу
};

#endif