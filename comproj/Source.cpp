#include <iostream>
#include <conio.h>
#include "Menu.h"

using namespace std;
int main(){
	Menu *menu = new Menu();	//�������� ������ ��� ������ ������ ����
	setlocale(LC_ALL, "Russian"); // ����� ������� �����
	system("chcp 1251"); // ����������� ��������� ������� 
	menu->Update();	//�������� ����� update
	delete menu; //�� ������ �� ������ ������� ������ �� ��� �������
	return 1;
}