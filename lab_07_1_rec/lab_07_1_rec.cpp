#include<iostream>
#include<time.h>
#include<iomanip>
#include<locale>
#include<windows.h>

using namespace std;

void CreateRow(int** a, const int rowNo, const int colCount, const int Low, const int High, const int colNo);
void CreateRows(int** a, const int rowCount, const int colCount, const int Low, const int High, const int rowNo);

void PrintRow(int** a, const int rowNo, const int colNo, const int colCount);
void PrintRows(int** a, const int rowCount, const int colCount, const int rowNo);

bool NeedSwap(int** a, const int i1);

void SortPass(int** a, const int rowCount, const int colCount, const int i0, int i1);
void Sort(int** a, const int rowCount, const int colCount, int i0);


void Change(int** a, const int row1, const int row2, const int colCount, const int colNo);

void CalcRow(int** a, const int rowNo, const int colCount, const int colNo,int& S, int& k);
void CalcRows(int** a, const int rowCount, const int colCount,const int rowNo,int& S, int& k);

int main()
{
	SetConsoleOutputCP(65001);
	SetConsoleCP(65001);

	srand((unsigned)time(NULL));

	int Low = 11;
	int High = 74;

	int rowCount = 8;
	int colCount = 9;

	int** a = new int*[rowCount];       
	for (int i = 0; i < rowCount; i++)
		a[i] = new int[colCount];
	
	CreateRows(a, rowCount, colCount, Low, High, 0);
	cout << "Початкова матриця" << endl;
	PrintRows(a, rowCount, colCount, 0);
	Sort(a, rowCount, colCount, 0);
	cout << "Відсортована матриця" << endl;
	PrintRows(a, rowCount, colCount, 0);

	int S = 0;
	int k = 0;

	CalcRows(a, rowCount, colCount, 0, S, k);
	cout << "S=" << S << endl;
	cout << "k=" << k << endl;
	cout << endl;
	cout << "Кінцева матриця" << endl;
	PrintRows(a, rowCount, colCount, 0);

	for (int i = 0; i < rowCount; i++)
		delete [] a[i];
	delete [] a;

	return 0;
}



void CreateRow(int** a, const int rowNo, const int colCount, const int Low, const int High, const int colNo)
{
	a[rowNo][colNo] = Low + rand() % (High - Low + 1);
	if (colNo < colCount - 1)
		CreateRow(a, rowNo, colCount, Low, High, colNo + 1);
}

void CreateRows(int** a, const int rowCount, const int colCount, const int Low, const int High, const int rowNo)
{
	CreateRow(a, rowNo, colCount, Low, High, 0);
	if (rowNo < rowCount - 1)
		CreateRows(a, rowCount, colCount, Low, High, rowNo + 1);

}



void PrintRow(int** a, const int rowNo, const int colNo, const int colCount)
{
	cout << setw(4) << a[rowNo][colNo];
	if (colNo < colCount - 1)
		PrintRow(a, rowNo, colNo + 1, colCount);
}


void PrintRows(int** a, const int rowCount, const int colCount, const int rowNo)
{
	if (rowNo == 0)
		cout << endl;
	PrintRow(a, rowNo, 0, colCount);
	cout << endl;
	if (rowNo < rowCount - 1)
		PrintRows(a, rowCount, colCount, rowNo + 1);
	else
		cout << endl;

}

bool NeedSwap(int** a, const int i1)
{
	return (a[i1][0] > a[i1 + 1][0])
		|| (a[i1][0] == a[i1 + 1][0] && a[i1][1] < a[i1 + 1][1])
		|| (a[i1][0] == a[i1 + 1][0] && a[i1][1] == a[i1 + 1][1] && a[i1][3] < a[i1 + 1][3]);
}


void Change(int** a, const int row1, const int row2, const int colCount, int colNo)
{
	int tmp = a[row1][colNo];
	a[row1][colNo] = a[row2][colNo];
	a[row2][colNo] = tmp;
	if (colNo < colCount - 1)
		Change(a, row1, row2, colCount, colNo + 1);
}

void SortPass(int** a, const int rowCount, const int colCount, const int i0, int i1)
{
	if (i1 < rowCount - i0 - 1)
	{
		if (NeedSwap(a, i1))
			Change(a, i1, i1 + 1, colCount, 0);
		SortPass(a, rowCount, colCount, i0, i1 + 1);
	}
}


void Sort(int** a, const int rowCount, const int colCount, int i0)
{
	if (i0 < rowCount - 1)
	{
		SortPass(a, rowCount, colCount, i0, 0);
		Sort(a, rowCount, colCount, i0 + 1);
	}

}

void CalcRow(int** a, const int rowNo, const int colCount, const int colNo , int& S, int& k)
{
	if (a[rowNo][colNo] % 6 == 0 && (rowNo + colNo) % 5 != 0)
	{
		S += a[rowNo][colNo];
		k++;
		a[rowNo][colNo] = 0;
	}
	if (colNo < colCount - 1)
		CalcRow(a, rowNo, colCount, colNo + 1, S, k);
}


void CalcRows(int** a, const int rowCount, const int colCount, int rowNo, int& S, int& k)
{
	CalcRow(a, rowNo, colCount, 0, S, k);
	if (rowNo < rowCount - 1)
		CalcRows(a, rowCount, colCount, rowNo + 1, S, k);
}