#include <iostream>
#include <string>
#include <iomanip>
#include "RecordList.h"

using namespace std;

RecordList::~RecordList(){//удаление списка записей
	while (!ptrRecord.empty()){//пока не пустой
		iter = ptrRecord.begin();//итератор на начало
		delete *iter;//очищаем выделенную память
		ptrRecord.erase(iter);//удаляем элемент
	}
}
Record* RecordList::FindId(int sid){
	if (ptrRecord.empty()){	//если пустой
		return NULL;	//возврашаем пустой указатель
	}
	else{	//иначе
		iter = ptrRecord.begin();	//ставим итератор в начало списка
		while (iter != ptrRecord.end()){	//пока не конец
			if ((*iter)->GetId() == sid)	//сравниваем аргумент с id элементов списка
				return *iter;	//если нашли =, то возвращаем указатель на элемент
			*iter++;	//если не нашли, то переходим к след. элементу
		}
	}
	return NULL;	//если ничего не нашли, возвращаем пустой указатель
}

void RecordList::InsertRecord(Record* ptrR){
	ptrRecord.push_back(ptrR); //вставляем в конец новую запись
}

void RecordList::Delete(int sid){	//удаляем запись с соотв. id
	if (*iter = FindId(sid)){	//если метод нашел запись с таким id, то
		delete *iter;//очищаем выделенную память
		ptrRecord.erase(iter);//удаляем указатель
		cout << "\n\nЗапись удалена." << endl;
	}
	else
		cout << "Запись не найдена" << endl;
}