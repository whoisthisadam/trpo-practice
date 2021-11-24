#include<iostream>
#include<string>
#include<sstream>
#include<math.h>
using namespace std;
int* createArray(int size);
void fillArray(int* arr, int size);
void printArray(int* arr, int size);
int numberOfUsersElement(int* arr, int size, int UserElement);
string firstNSymbolsToString(int number, int amount);
string toStr(int number);
string toStr(double number);
string toStr(long int number);
int countsUsersElement(int* arr, int size, int userNum);
int countsUsersElement(string* arr, int size, string userNum);
string* arrayString(int *arr, int size);
void printArray(string* arr, int size);
string toStr(double numberDouble);
int main()
{
	while (1)
	{
		size_t task;
		cout << "Enter the task number(0-finish your work)" << endl; cin >> task; cout << endl;
		switch (task)
		{
		case 0:return 0; break; break;
		case 1:
		{
			cout << "Converting integer number to string" << endl;
		    int number1;
		    cout << "Number="; cin >> number1;
		    cout << "Number in string:" << toStr(number1) << endl;
		    break;
		}
		case 2: 
		{
			cout << "Converting double number to string" << endl;
			double number; cout << "Number(double)="; cin >> number; cout << "Number in string:" << toStr(number) << endl; break;
        }
		case 3:
		{
			cout << "Converting only part of integer number to string" << endl;
			int number;
			cout << "Enter a number:"; cin >> number;
			int amount; cout << "How many symbols of this number do you want to convert to string?" << " "; cin >> amount;
			cout << "The first " << amount << " symbols of number to string:";
			cout << firstNSymbolsToString(number, amount) << endl;
			break;
		}
		case 4:
		{
			int size; int userNumber;
		    cout << "Enter size of array" << endl; cin >> size; int* arr = createArray(size); fillArray(arr, size);
		    cout << "Your array:"; printArray(arr, size);
			cout << "Enter the number" << endl;
			cin >> userNumber;
			cout << "This number occurs " << countsUsersElement(arr, size, userNumber) << " times in this array" << endl;
			break;
		}
		case 5:
		{
			int size; int userNumber;
			cout << "Enter size of array" << " "; cin >> size;
			int* arr = createArray(size); fillArray(arr, size);
			string* arrStr = arrayString(arr, size);
			cout << "Enter a number to count" << " "; cin >> userNumber;
			string userNumStr = toStr(userNumber);
			cout << "Your string array:" << endl;
			printArray(arrStr, size);
			int count = countsUsersElement(arrStr, size, userNumStr); \
			cout << "This symbol occurs " << count << " times in this string array" << endl;
			break;
		}
	    }
	}
	return 0;
}
int* createArray(int size)
{
	int* arr = new int[size];
	return arr;
}
void fillArray(int* arr, int size)
{
	srand(time(0));
	for (int i = 0; i < size; i++)
	{
		arr[i] = rand() % 21 - 10;
	}
}
void printArray(int* arr, int size)
{
	for(int i=0;i<size;i++)
	{
		cout << arr[i] << " ";
	}
	cout << endl;
}
int numberOfUsersElement(int* arr, int size, int UserElement)
{
	int counter = 0;
	for (int i = 0; i < size; i++)
	{
		if (arr[i] == UserElement)counter++;
	}
	return counter;
}
string firstNSymbolsToString(int number, int amount)
{
	if (number < 0)number = -number;
	while (number >= pow(10, amount))
	{
		number = number / 10;
	}
	string firstAmountOfNumber=toStr(number);
	return firstAmountOfNumber;
}
string toStr(int numberInt)
{
	int numberOfSymbols = 1, i = 0;
	string numberString;
	if (numberInt == 0)
	{
		numberString = "0";
		return numberString;
	}
	if (numberInt < 0)
	{
		numberString += "-";
		numberInt *= -1;
	}
	short oneSymbol;
	int lenght = numberInt;
	while ((lenght /= 10) > 0)
		numberOfSymbols++;
	int* array = new int[numberOfSymbols];

	while (numberInt >= 1)
	{
		oneSymbol = numberInt % 10;
		numberInt = numberInt / 10;
		array[i] = oneSymbol;
		i++;
	}
	for (int i = numberOfSymbols - 1; i > -1; --i)
	{
		numberString += (char)array[i] + 48;
	}
	delete[] array;
	return numberString;
}
string toStr(double numberDouble)
{
	string numberString;
	if (numberDouble < 0)
	{
		numberString += '-';
		numberDouble = -numberDouble;
	}
	if (numberDouble == 0)
	{
		numberString = "0";
		return numberString;
	}
	int intPartOfNumber = (int)numberDouble;
	double fractPartOfNumber = numberDouble - intPartOfNumber;
	string intPart = toStr(intPartOfNumber);
	fractPartOfNumber *= 10000;
	int fractPartOfNumber1 = (int)fractPartOfNumber;
	string fractPart = toStr(fractPartOfNumber1);
	numberString += intPart + "." + fractPart;
	return numberString;
}

int countsUsersElement(int* arr, int size, int userNum)
{
	int counter = 0;
	for (int i =0;i< size; i++)
	{
		if (arr[i] == userNum)counter++;
	}
	return counter;
}
string* arrayString(int *arr, int size)
{
	string symbol;
	string* arrStr = new string[size];
	for (int i = 0; i < size; i++)
	{
		arrStr[i] = toStr(arr[i]);
	}
	return arrStr;
}
int countsUsersElement(string* arr, int size, string userNum)
{
	int counter = 0;
	for (int i = 0; i < size; i++)
	{
		if (arr[i] == userNum)counter++;
	}
	return counter;
}
void printArray(string* arr, int size)
{
	for (int i = 0; i < size; i++)
	{
		cout << arr[i] << " ";
	}
	cout << endl;
}
