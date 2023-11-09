
#include <iostream>
#include <iomanip>
#include <cstdlib>
#include <ctime>
using namespace std;

void Create(int** a, const int rowCount, const int colCount, const int Low, const int High, int i = 0, int j = 0) {
	if (i >= rowCount) {
		return;
	}
	if (j < colCount) {
		a[i][j] = Low + rand() % (High - Low + 1);
		Create(a, rowCount, colCount, Low, High, i, j + 1);
	}
	else {
		Create(a, rowCount, colCount, Low, High, i + 1, 0);
	}
}

void Print(int** a, const int rowCount, const int colCount, int i = 0) {
	if (i >= rowCount) {
		return;
	}
	for (int j = 0; j < colCount; j++) {
		cout << setw(4) << a[i][j];
	}
	cout << endl;
	Print(a, rowCount, colCount, i + 1);
}


void Change(int** a, const int row1, const int row2, const int colCount, int j = 0) {
	if (j >= colCount) {
		return;
	}
	int tmp = a[row1][j];
	a[row1][j] = a[row2][j];
	a[row2][j] = tmp;
	Change(a, row1, row2, colCount, j + 1);
}

void Sort(int** a, const int rowCount, const int colCount, int i = 0) {
	if (i >= rowCount - 1) {
		return;
	}
	for (int j = 0; j < rowCount - i - 1; j++) {
		if ((a[j][0] < a[j + 1][0])
			|| (a[j][0] == a[j + 1][0] && a[j][1] > a[j + 1][1])
			|| (a[j][0] == a[j + 1][0] && a[j][1] == a[j + 1][1] && a[j][3] < a[j + 1][3])) {
			Change(a, j, j + 1, colCount);
		}
	}
	Sort(a, rowCount, colCount, i + 1);
}

void Calc(int** a, const int rowCount, const int colCount, int& S, int& k, int i = 0, int j = 0) {
	if (i >= rowCount) {
		return;
	}
	if (j < colCount) {
		if (!(a[i][j] > 0 && a[i][j] % 2 == 0)) {
			S += a[i][j];
			k++;
			a[i][j] = 0;
		}
		Calc(a, rowCount, colCount, S, k, i, j + 1);
	}
	else {
		Calc(a, rowCount, colCount, S, k, i + 1, 0);
	}
}


int main() {
	srand(static_cast<unsigned>(time(NULL)));
	int Low = -26;
	int High = 23;
	int rowCount = 8;
	int colCount = 6;

	int** a = new int* [rowCount];
	for (int i = 0; i < rowCount; i++) {
		a[i] = new int[colCount];
	}

	Create(a, rowCount, colCount, Low, High);
	cout << endl << "Original Array:" << endl;
	Print(a, rowCount, colCount);
	Sort(a, rowCount, colCount);
	cout << endl << "Sorted Array:" << endl;
	Print(a, rowCount, colCount);

	int S = 0;
	int k = 0;
	Calc(a, rowCount, colCount, S, k);

	cout << "S = " << S << endl;
	cout << "k = " << k << endl;

	cout << endl << "Modified Array:" << endl;
	Print(a, rowCount, colCount);
	for (int i = 0; i < rowCount; i++)
		delete[] a[i];
	delete[] a;
	return 0;

	return 0;
}
