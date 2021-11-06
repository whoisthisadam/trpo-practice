#include<iostream>
#include<cstdlib>
using namespace std;
double* createAndFillArray(int n)
{
	srand(time(0));
	double* arr = new double[n];
	for (int i = 0; i < n; i++)
	{
		arr[i] = rand() % 101-50;
	}
	return arr;
}
void printArray(double *arr, int n)
{
	for (int i = 0; i < n; i++)
	{
		cout << arr[i] << " ";
	}
	cout << endl;
}
double** createAndFillMatrix(int n, int m)
{
	srand(time(0));
	double** matrix = new double* [n];
	for (int i = 0; i < n; i++)
	{
		matrix[i] = new double[m];
	}
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			matrix[i][j] = rand() % 101-50;
		}
	}
	return matrix;
}
void printMatrix(double** matrix, int n, int m)
{
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			cout << matrix[i][j] << " ";
		}
		cout << endl;
	}
}
void deleteMatrix(double** matrix, int n)
{
	for (int i = 0; i < n; i++)
	{
		delete[]matrix[i];
	}
	delete[]matrix;
}
int printUserMatrix()
{
	int rows, cols;
	cout << "Rows:"; cin >> rows; cout << endl; cout << "Collumns:"; cin >> cols; cout << endl;
	double**matrix=createAndFillMatrix(rows,cols);
	cout << "Your matrix:" << endl;
	printMatrix(matrix, rows, cols);
	return 0;
}
int sumOfArray()
{
	int size;
	cout << "Enter the size of array" << endl; cin >> size; cout << endl;
	double* array = createAndFillArray(size);
	cout << "Your array:";
	printArray(array, size);
	double sum = 0;
	for (int i = 0; i < size; i++) {
		sum += array[i];
	}
	cout << endl;
	cout << "Number of elements:" << size << endl;
	cout << "Sum of elements:" << sum << endl;
	double meanVal = sum / size;
	cout << "Mean value of elements:" << meanVal << endl;
	delete[]array;
	return 0;
}
int matrixMultiplicate()
{
    int rowsA, colsA;
	cout << "Enter sizes of matrices" << endl;
	cout << "Matrix A" << "\nRows:"; cin >> rowsA; cout << "Collums:"; cin >> colsA;
	double** matrixA = createAndFillMatrix(rowsA,colsA);
	cout << "A=\n";
	printMatrix(matrixA, rowsA, colsA);
	int rowsB, colsB;
	cout << "Matrix B" << "\nRows:"; cin >> rowsB; cout << "Collums:"; cin >> colsB;
	if (colsA == rowsB)
	{
		double** matrixB = createAndFillMatrix(rowsB, colsB);
		printMatrix(matrixB, rowsB, colsB);
		double** matrixAB = new double* [rowsA];
		for (int i = 0; i < rowsA; i++)
		{
			matrixAB[i] = new double[colsB];
		}
		for (int i = 0; i < rowsA; i++)
		{
			for (int j = 0; j < colsB; j++)
			{
				matrixAB[i][j] = 0;
				for (int k = 0; k < colsA; k++)
				{
					matrixAB[i][j] += matrixA[i][k] * matrixB[k][j];
				}
			}
		}
	    cout << "A*B=\n";
	    printMatrix(matrixAB, rowsA, colsB);
	    deleteMatrix(matrixA, rowsA);
	    deleteMatrix(matrixB, rowsB);
		deleteMatrix(matrixAB, rowsA);
		}
	else 
	{
			cout << "Matrices are not consistent:the number of collums of the first matrix have to be the same as the number of rows of the second matrix. Try again" << endl;
	}
    return 0;
}
int deleteSameElementsAndMedian()
{
	int size;
	cout << "Enter the size of array:"; cin >> size; cout << endl;
	double* arr = createAndFillArray(size);
	cout << "Your array:";
	printArray(arr, size);
	int addValue;
	for (int i = 0; i < size-1; i++)
	{
		for (int j = i + 1; j < size; j++)
		{
			if (arr[i] > arr[j])
			{
				addValue = arr[i];
				arr[i] = arr[j];
				arr[j] = addValue;
			}
		}
	}
	double median;
	if (size % 2 == 0)
	{
		median = (arr[size / 2 - 1] + arr[size / 2]) / 2;
	}
	else
	{
		median = arr[size/ 2];
	}
	cout << "Median of array:" << median << endl<< "Sorted array without same elements:";
	for (int i = 0; i < size; i++)
	{
		if (arr[i] != arr[i + 1]) { cout << arr[i] << " "; }
	}
	cout << endl;
	return 0;
}
void MatrixMedianAndMinMax()
{
	int rows, cols;
	cout << "Enter the size of matrix\nRows:"; cin >> rows; cout << endl << "Collums:"; cin >> cols; cout << endl;
	double** matrix = createAndFillMatrix(rows, cols);
	printMatrix(matrix, rows, cols);
	int addVal;
	for (int k = 0; k < rows; k++)
	{
		for (int s = 0; s < cols; s++)
		{
			for (int i = 0; i < rows; i++)
			{
				for (int j = 0; j < cols; j++)
				{
					if (matrix[k][s] < matrix[i][j])
					{
						addVal = matrix[k][s];
						matrix[k][s] = matrix[i][j];
						matrix[i][j] = addVal;
					}
				}
			}
		}
	}
	cout << "Sorted matrix:" << endl;
	for (int i = 0; i < rows; i++)
	{
		for (int j = 0; j < cols; j++)
		{
		cout << matrix[i][j] << "\t";
		}
		cout << endl;
	}
	double median;
	if (rows % 2 == 1 && cols % 2 == 1)
	{
		median = matrix[rows / 2][cols / 2];
	}
	else if (rows % 2 == 1 && cols % 2 == 0)
	{
		median = (matrix[rows / 2][cols / 2 - 1] + matrix[rows / 2][cols / 2]) / 2;
	}
	else
	{
		median = (matrix[rows/2-1][cols-1] + matrix[rows/2][0]) / 2;
	}
	cout << "Median:" << median << endl;
	cout << "Max element:" << matrix[rows-1][cols-1] << endl << "Min element:" << matrix[0][0] << endl;
}
int main()
{
	for (;;) {
		int numTask;
		cout << "Choose a task number:"; cin >> numTask;
		switch (numTask)
		{
		case 0: return 0; break;
		case 1:printUserMatrix(); break;
		case 2:sumOfArray(); break;
		case 3:matrixMultiplicate(); break;
		case 4:deleteSameElementsAndMedian(); break;
		case 5:MatrixMedianAndMinMax(); break;
		}
}
	return 0;
}