#include<iostream>
#include<cmath>
#include<conio.h>
#include<clocale>
using namespace std;

int test()
{
	setlocale(LC_ALL, "russian");
	int a, a1, a2, a3;
	cout << "Введите трехзначное число" << endl;
	cin >> a;
	if (a % 2 == 0) cout << "Число четное" << endl;
	else cout << "Число нечетное" << endl;
	a1 = a / 100;
	a2 = (a - a1 * 100) / 10;
	a3 = a % 10;
	cout << "Среднее арифметическое цифр равно:" << (a1 + a2 + a3) / 3.0 << endl;
	return 0;
}
int main()
{
	test();
	setlocale(LC_ALL, "russian");
	int  i;
	cout << "Введите номер месяца" << endl;
	cin >> i;
	switch (i) {
	case 1: cout << "Январь, Зима" << endl; break;
	case 2: cout << "Февраль, Зима" << endl; break;
	case 3: cout << "Март, Весна" << endl; break;
	case 4: cout << "Апрель, Весна" << endl; break;
	case 5: cout << "Май, Весна" << endl; break;
	case 6: cout << "Июнь, Лето" << endl; break;
	case 7: cout << "Июль, Лето" << endl; break;
	case 8: cout << "Август, Лето" << endl; break;
	case 9: cout << "Сентябрь, Осень" << endl; break;
	case 10: cout << "Октябрь, Осень" << endl; break;
	case 11: cout << "Ноябрь, Осень" << endl; break;
	case 12: cout << "Декабрь, Зима" << endl; break;
		return 0;
	}
}


