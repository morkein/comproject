#ifndef __GLOBALFUNC_H__
#define __GLOBALFUNC_H__
void printHeader();	//����� ��������� �������
void printFooter(); //����� �����(������) �������
int checkNumber(long long snumber);	 //�������� ��������� ������ ��������
int checkDay(int sday);	//�������� ��������� ����� ��
int checkMonth(int smonth);	//�������� ��������� ����� �����
int checkYear(int syear);	//�������� ��������� ����� ����
int checkHour(int shour);	//�������� ��������� ����� �����
int checkMin(int smin);	//�������� ��������� ����� �����
int checkNegative(int num);	//�������� �� ������������� �����
void enterInt(int* i);	//������ ����� ������ �����
void enterLongLong(long long* l);	//������ ����� long long �����, �� ������ ��������
#endif