#include<iostream>
#include<conio.h>
#include<cmath>
#include<clocale>
using namespace std;
int number1()
{
	setlocale(LC_ALL, "russian");
	int a, b, i, j, S, P;
	cout << "Ширина:"; cin >> a;
	cout << "Длина:"; cin >> b;
	S = a * b;
	P = 2 * (a + b);
	cout << "Периметр равен " << P;
	cout << "\nПлощадь равна " << S;
	cout << " " << endl;
	for (i = 0; i < a; i++)
	{
		for (j = 0; j < b; j++)
		{
			if (i == 0 || i == a - 1) { cout << "*"; continue; }
			if (i != 0 || i != a - 1)
				if (j == 0 || j == b - 1) cout << "*";
				else cout << " ";
		}
		cout << "\n";
	}
	return 0;
}
int number2()
{
	unsigned long int n, f1, f2, f, i;
	cout << "n= "; cin >> n;
	f1 = 0;
	f = 0;
	f2 = 1;
	for (i = 0; i < n; i++)
	{
		f = f2;
		f2 += f1;
		f1 = f;
		cout << " " << f;
	}
	int fact = 1;
	for (int j = 2; j <= n; j++) {
		fact*= j;
	}
	cout << "\nn!= " << fact;
	return 0;
}
int number3()
{
	setlocale(LC_ALL, "russian");
	int firstNum, secNum;
	int flag1 = 0, flag2 = 0, i, j;
	cout << "\nВведите первое число:"; cin >> firstNum;
	cout << "\nВведите второе число:"; cin >> secNum;
	if (firstNum < 0) cout << "Первое число отрицательное. Отрицательное число всегда не является простым" << endl;
	else {
		for (i = 2; i <= firstNum / 2; i++) {
			if (firstNum % i == 0) {
				cout << "1 число составное" << endl;
				flag1 = 1;
				break;
			}
		}
		if (flag1 == 0)cout << "1 число простое" << endl;
	}
	if (secNum < 0)cout << "Второе число отрицательное. Отрицательное число всегда не является простым" << endl;
	else {
		for (j = 2; j <= secNum / 2; j++) {
			if (secNum % j == 0) {
				cout << "2 число составное" << endl;
				flag2 = 1;
				break;
			}
		}
		if (flag2 == 0)cout << "2 число простое" << endl;
	}
	if (firstNum < 0)firstNum = -firstNum;
	if (secNum < 0)secNum = -secNum;
	while (firstNum != secNum) {
		if (firstNum > secNum)
			firstNum = firstNum - secNum;
		else secNum = secNum - firstNum;
		}
	cout << "Наибольший общий делитель равен " << firstNum << endl;
	return 0;
}
int number4()
{
	setlocale(LC_ALL, "RUS");
	int dec, bin;
	int i = 0;
	cout << "Введите число для перевода в двоичную систему счисления:"; cin >> dec;
	cout << "-";
	if (dec == 0)
		cout << "0";
	else {
		int* binNum = new int[dec];
		while (dec >= 1) {
			bin = dec % 2;
			dec = dec / 2;
			binNum[i] = bin;
			i++;
		}
		cout << "Двоичное представление числа:";
		for (int j = i; j > 0; j--) {
			cout << binNum[j - 1];
		}
	}
	return 0;
}
int main()
{
	setlocale(LC_ALL, "rus");
	int task; int z=0;
	while (z<1){
	cout << "\nВыберите номер задания(число от 1 до 4):"; cin >> task;
	    switch (task) {
		case 1:number1(); break;
		case 2:number2(); break;
		case 3:number3(); break;
		case 4:number4(); break;
		default:cout << "ОШИБКА!!!!Выберите число от 1 до 5" << endl; break;
		}
	}
	return 0;
}


  


