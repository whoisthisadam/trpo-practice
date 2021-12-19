#include<iostream>
#include<time.h>
#include<cstdlib>
using namespace std;
enum firstNames { Mark, Victor, JohnFirst, Alex, Adam, Frank, Sasha, Janice, Gregory, Maeve };
enum maleMiddleNames { James, JohnMiddle, William, Thomas, David, Robert, Edward, Peter, Lee, Michael };
enum femaleMiddleNames { Rose, Grace, Louise, Jane, Anne };
enum lastNames { Smith, Johnson, Williams, Brown, Jones, Garcia, Miller, Davis, Jackson, Moore };
enum task{most_popular_name=1,sorted_by_mark,data_of_student,data_of_all_sudents,average_age};
struct Data
{
	int day;
	int month;
	int year;
};
struct Students
{
	string firstName;
	string middleName;
	string lastName;
	Data birth;
	int groupNumber;
	double averageMark;
};
Students* createArray(size_t size);
void fillArray(Students* arrayStudents, size_t size);
void printNames(Students* arr, size_t size);
string countsTheMostPopularName(Students* arr, size_t size);
Students* sortArray(Students* arr1, size_t size);
void printOneStudentData(Students* array, int number);
void printAllStudentsData(Students* array, size_t size);
int currentYear();
double averageAgeOfStudents(Students* arr, size_t size);
void main()
{
	int task;
	size_t amountOfStudents;
	cout << "Enter the number of students" << endl; cin >> amountOfStudents;
	Students* array = createArray(amountOfStudents);
	fillArray(array, amountOfStudents);
	cout << "STUDENTS:" << endl;
	printNames(array, amountOfStudents);
	cout << "Choose what to do\n1-Find the most popular name\n2-See the list of students sorted by average mark(from 10 to 0)\n3-See the data of chosen student\n4-See the list of all students and their data\n5-Count middle age of students" << endl;
	cin >> task;
	int continue_work=1;
	while (continue_work==1)
	{

		switch (task)
		{
		case most_popular_name: {cout << "The most popular name is " << countsTheMostPopularName(array, amountOfStudents) << endl; break; }
		case sorted_by_mark:
		{
			Students* array2 = sortArray(array, amountOfStudents);
			cout << "Sorted list:" << endl;
			int number = 1;
			for (int i = 0; i < amountOfStudents; i++)
			{
				cout << number<<"."<<array2[i].firstName << " " << array2[i].middleName << " " << array2[i].lastName << "(" << array2[i].averageMark << ")" << endl;
				number++;
			}
			break;
		}
		case data_of_student:
		{
			int numberOfStudent;
			cout << "Enter the number of student to check" << endl; cin >> numberOfStudent;
			if (numberOfStudent <= amountOfStudents)
			{
				printOneStudentData(array, numberOfStudent); break;
			}
			else cout << "There is no student with such number in this list" << endl; break;
		}
		case data_of_all_sudents:
		{
			printAllStudentsData(array, amountOfStudents); break;
		}
		case average_age:
		{
			cout << "Average age of students is " << averageAgeOfStudents(array, amountOfStudents) <<" years"<< endl; break;
		}
		default: cout << "ERROR!!!" << endl;
			break;
		}
		cout << "Press 0 to end work or press 1 to continue work" << endl;
		cin >> continue_work; 
		if (continue_work != 0 && continue_work != 1)
		{
			cout << "ERROR!\nYOU HAVE TO PRESS ONLY 1 OR 0\nTry Again" << endl;
			cin >> continue_work;
		}
		if (continue_work == 0)break;
		cout << "\n\n\n\n";
		cout << "Choose what to do\n1-Find the most popular name\n2-See the list of students sorted by average mark(from 10 to 0)\n3-See the data of chosen student\n4-See the list of all students and their data\n5-Count middle age of students" << endl;
		cin >> task;
	}
}
Students* createArray(size_t size)
{
	Students* arr = new Students[size];
	return arr;
}
void fillArray(Students* arrayStudents, size_t size)
{
	srand(time(NULL));
	for (int i = 0; i < size; i++)
	{
		char gender;//Для определения пола(для мужского имени-мужское отчество(middle name),для женского-женское.)//
		int firstName = rand() % 10;
		switch (firstName)
		{
		case Mark:arrayStudents[i].firstName = "Mark"; gender = 'M';  break;
		case Victor:arrayStudents[i].firstName = "Victor"; gender = 'M'; break;
		case JohnFirst:arrayStudents[i].firstName = "John"; gender = 'M';  break;
		case Alex:arrayStudents[i].firstName = "Alex"; gender = 'M';  break;
		case Adam:arrayStudents[i].firstName = "Adam"; gender = 'M'; break;
		case Frank:arrayStudents[i].firstName = "Frank"; gender = 'M'; break;
		case Sasha:arrayStudents[i].firstName = "Sasha"; gender = 'B'; break;
		case Janice:arrayStudents[i].firstName = "Janice"; gender = 'F'; break;
		case Gregory:arrayStudents[i].firstName = "Gregory"; gender = 'M'; break;
		case Maeve:arrayStudents[i].firstName = "Maeve"; gender = 'F'; break;
		}
		
	    if (gender == 'B')
		{
		int tag = rand() % 2;
		if (tag == 1)gender = 'M';
		else gender = 'F';
		}
	    if (gender == 'M')
		{
			int middleName = rand() % 10;
			switch (middleName)
			{
			case James:arrayStudents[i].middleName = "James"; break;
			case JohnMiddle:arrayStudents[i].middleName = "John"; break;
			case William:arrayStudents[i].middleName = "William"; break;
			case Thomas:arrayStudents[i].middleName = "Thomas"; break;
			case David:arrayStudents[i].middleName = "David"; break;
			case Robert:arrayStudents[i].middleName = "Robert"; break;
			case Edward:arrayStudents[i].middleName = "Edward"; break;
			case Peter:arrayStudents[i].middleName = "Peter"; break;
			case Lee:arrayStudents[i].middleName = "Lee"; break;
			case Michael:arrayStudents[i].middleName = "Michael"; break;
			}
		}
		else 
		{
			int middleName = rand() % 5;
			switch (middleName)
			{
			case Rose:arrayStudents[i].middleName = "Rose"; break;
			case Grace:arrayStudents[i].middleName = "Grace"; break;
			case Louise:arrayStudents[i].middleName = "Louise"; break;
			case Jane:arrayStudents[i].middleName = "Jane"; break;
			case Anne:arrayStudents[i].middleName = "Anne"; break;
			}
		}
	
		int lastName = rand() % 9;
		switch (lastName)
		{
		case Smith:arrayStudents[i].lastName = "Smith"; break;
		case Johnson:arrayStudents[i].lastName = "Johnson"; break;
		case Williams:arrayStudents[i].lastName = "Williams"; break;
		case Brown:arrayStudents[i].lastName = "Brown"; break;
		case Jones:arrayStudents[i].lastName = "Jones"; break;
		case Garcia:arrayStudents[i].lastName = "Garcia"; break;
		case Miller:arrayStudents[i].lastName = "Miller"; break;
		case Davis:arrayStudents[i].lastName = "Davis"; break;
		case Jackson:arrayStudents[i].lastName = "Jackson"; break;
		case Moore:arrayStudents[i].lastName = "Moore"; break;
		}
		arrayStudents[i].birth.year = rand() % 25 + 1980;
		arrayStudents[i].birth.month = rand() % 12 + 1;
		int monthCheck = arrayStudents[i].birth.month;
		if (monthCheck == 2)arrayStudents[i].birth.day = rand() % 28 + 1;
		else if (monthCheck == 4 || monthCheck == 6 || monthCheck == 9 || monthCheck == 11)arrayStudents[i].birth.day = rand() % 30 + 1;
		else arrayStudents[i].birth.day = rand() % 31 + 1;
		arrayStudents[i].groupNumber = rand() % 100001 + 100000;
		arrayStudents[i].averageMark = rand()%10+1-rand()%100*0.01;
	}
}
void printNames(Students* arr, size_t size)
{
	int numberOfStudent = 1;
	for (int i = 0; i < size; i++)
	{
		
		cout << numberOfStudent << "."<<arr[i].firstName << " " << arr[i].middleName << " " << arr[i].lastName << endl;
		numberOfStudent++;
	}
}
string countsTheMostPopularName(Students* arr, size_t size)
{
	int counter;
	int maxRepeatsOfName = 0;
	bool isNameRepeats=false;
	string mostPopularName;
	for (int i = 0; i < size; i++)
	{
		counter = 0;
		for (int j = i+1; j < size; j++)
		{
			if (arr[i].firstName == arr[j].firstName)counter++;
		}
		if (maxRepeatsOfName < counter)
		{
		    isNameRepeats=true;
			maxRepeatsOfName = counter;
			mostPopularName = arr[i].firstName;
		}
	}
	if (!isNameRepeats)return"!!!Each name appears only once";
	else return mostPopularName;
}
Students* sortArray(Students* arr1, size_t size)
{
	Students* arr2 = new Students[size];
	for (int i = 0; i < size; i++)
	{
		arr2[i]=arr1[i];
	}
	for (int i = 0; i < size; i++)
	{
		for (int j = i+1; j < size; j++)
		{
			if (arr2[i].averageMark < arr2[j].averageMark)swap(arr2[i], arr2[j]);
		}
	}
	return arr2;
}
void printOneStudentData(Students* array, int number)
{
	cout << array[number - 1].firstName << " " << array[number -1].middleName << " " << array[number -1].lastName << endl;
	cout << "Birthday:" << array[number - 1].birth.day << "." << array[number - 1].birth.month << "." << array[number - 1].birth.year << endl;
	cout << "Group number:" << array[number - 1].groupNumber << endl;
	cout << "Average mark:" << array[number - 1].averageMark << endl;
}
void printAllStudentsData(Students* array, size_t size)
{
	for (int i = 0; i < size; i++)
	{
		cout << array[i].firstName << " " << array[i].middleName << " " << array[i].lastName << endl;
		cout << "Birthday:" << array[i].birth.day << "." << array[i].birth.month << "." << array[i].birth.year << endl;
		cout << "Group number:" << array[i].groupNumber << endl;
		cout << "Average mark:" << array[i].averageMark << "\n\n\n\n";
	}
}
int currentYear()
{
	time_t seconds = time(NULL);
	tm* timeinfo = new tm;
    localtime_s(timeinfo,&seconds);
	return timeinfo->tm_year + 1900;
}
double averageAgeOfStudents(Students*arr,size_t size)
{
	int year = currentYear();
	int sumOfAges = 0;
	for (int i = 0; i < size; i++)
	{
		int ageOfStudent = year - arr[i].birth.year;
		sumOfAges += ageOfStudent;
	}
	return (double)sumOfAges / size;
}