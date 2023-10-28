#include <iostream>


using namespace std;
//---------------------������� � ���������---------------------------------------





//------------------------MAIN----------------------------------------------------
int main() {
	setlocale(LC_ALL, "RU");
	srand(time(NULL));
	//-------------------------------���� �����-------------------------------------

	int n;
	int max, i_max = 0, j_max = 0;

	cout << "Enter the dimension of the matrix:  ";
	cin >> n;

	int** matrix = new int* [n];
	for (int i = 0; i < n; i++)
	{
		matrix[i] = new int[n];
	}

	for (int i = 0; i < n; i++)
	{
		cout << "\nNew row: \n";
		for (int j = 0; j < n; j++)
		{
			cin >> matrix[i][j];
		}
	}

	cout << endl;
	
	max = abs( matrix[0][0]);
	
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			cout << matrix[i][j] << "\t";
			if (abs(matrix[i][j]) > max)
			{
				max = abs(matrix[i][j]);
				i_max = i;
				j_max = j;
			}
		}
		cout << endl;
	}


	cout << max << "[" << i_max << ", " << j_max << "]" << endl;


	if (i_max < n - 1)
	{
		int* reserve = new int [n];

		for (int i = 0; i < n; i++)
		{
			reserve[i] = matrix[n - 1][i];            // ��������� ������ � ������
		}
		for (int i = 0; i < n; i++)
		{
			matrix[n - 1][i] = matrix[i_max][i];      // ������ � ���� ��������� � ��������� ������
		}

		for (int i = 0; i < n; i++)
		{
			matrix[i_max][i] = reserve[i];            // ������ ������ � ���� ��������� ������ ������ �� �������
		}

		delete[] reserve;
	}

	//----PRINT---
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			cout << matrix[i][j] << "\t";
		}
		cout << endl;
	}
	cout << endl;
	//------------

	if (j_max < n - 1)
	{
		int* reserve = new int[n];

		for (int i = 0; i < n; i++)
		{
			reserve[i] = matrix[i][n - 1];            // ��������� ������� � ������
		}
		for (int i = 0; i < n; i++)
		{
			matrix[i][n - 1] = matrix[i][j_max];      // ������ � ���� ��������� � ��������� �������
		}

		for (int i = 0; i < n; i++)
		{
			matrix[i][j_max] = reserve[i];            // ������ ������� � ���� ��������� ������ ������� �� �������
		}

		delete[] reserve;
	}


	//----PRINT---
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			cout << matrix[i][j] << "\t";
		}
		cout << endl;
	}
	cout << endl;
	//------------

		
	for (int i = 0; i < n; i++)
	{
		delete[] matrix[i];
    }
	delete[] matrix;
		system("pause");
	return 0;
}
