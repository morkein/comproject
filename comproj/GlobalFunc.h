#ifndef __GLOBALFUNC_H__
#define __GLOBALFUNC_H__
void printHeader();	//вывод заголовка таблицы
void printFooter(); //вывод линий(костей) таблицы
int checkNumber(long long snumber);	 //проверка диапазона номера телефона
int checkDay(int sday);	//проверка диапазона ввода дн¤
int checkMonth(int smonth);	//проверка диапазона ввода мес¤ца
int checkYear(int syear);	//проверка диапазона ввода года
int checkHour(int shour);	//проверка диапазона ввода часов
int checkMin(int smin);	//проверка диапазона ввода минут
int checkNegative(int num);	//проверка на отрицательное число
void enterInt(int* i);	//функци¤ ввода целого числа
void enterLongLong(long long* l);	//функци¤ ввода long long числа, дл¤ номера телефона
#endif