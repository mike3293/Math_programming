#include <iostream>
#include <iomanip> 
#include "Salesman.h"
#include <ctime>
#define N 10

using namespace std;

void main()
{
	setlocale(0, "");
	clock_t  t1 = 0, t2 = 0;

	srand((unsigned)time(NULL));

	int d[N][N];
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < N; j++)
		{
			if (j == i)
			{
				d[i][j] = 0;
				continue;
			}
			d[i][j] = rand() % (300 - 10 + 1) + 10;
		}
	}
	d[0][2] = INF;
	d[4][8] = INF;
	d[8][3] = INF;

	int r[N]; // результат 

	t1 = clock();
	int s = salesman(
		N,          // [in]  количество городов 
		(int*)d,    // [in]  массив [n*n] расстояний 
		r           // [out] массив [n] маршрут 0 x x x x  
		);
	t2 = clock();

	cout << endl << "- ЗАДАЧА КОММИВОЯЖЕРА -" << endl;
	cout << endl << "Количество  городов: " << N;
	cout << endl << "Матрица расстояний : ";
	for (int i = 0; i < N; i++)
	{
		cout << endl;
		for (int j = 0; j < N; j++)
			if (d[i][j] != INF) 
				cout << setw(3) << d[i][j] << " ";
			else 
				cout << setw(3) << "INF" << " ";
	}
	cout << endl << endl << "Оптимальный маршрут: ";
	for (int i = 0; i < N; i++) 
		cout << r[i] << "-->"; 
	cout << 0;
	cout << endl << "Длина маршрута     : " << s << endl;
	cout << endl << "Продолжительность вычеслений (сек): " << ((double)(t2 - t1)) / ((double)CLOCKS_PER_SEC) << endl << endl;
	system("pause");
}