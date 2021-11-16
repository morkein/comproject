#include <iostream>
#include "Record.h"

using namespace std;
int main(){
	Record rec(1, 2, 3, 4, 12, 30, "Sta", "Liza", "Ale", 89000000000, "Liza", "nogti", 500);
	cout << rec.GetDay() << endl;
	system("pause");
	return 1;
}