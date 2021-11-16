#include <iostream>
#include <conio.h>
#include "Menu.h"

using namespace std;
int main(){
	Menu *menu = new Menu();	//выделяем память под объект класса меню
	setlocale(LC_ALL, "Russian"); // задаём русский текст
	system("chcp 1251"); // настраиваем кодировку консоли 
	menu->Update();	//вызываем метод update
	delete menu; //по выходу из метода очищаем память из под объекта
	return 1;
}