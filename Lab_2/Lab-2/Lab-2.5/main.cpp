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

	int d[N][N] = {
				  {   0,  10, INF,  25, 200,  30,  41,  55, 204, 100 },  
				  {  30,   0,  55,  20, 100,  65,  20, 300, 210, 290 },  
				  { 110,  20,   0, INF,  30,  67,  89, 113, 222,  35 },  
				  {  65,  20, 300,   0, INF,  56,  65,  76, 245, 199 },  
				  {   0,  10, 224,  25,   0,  30,  41,  55, 204, 100 },  
				  {  30,   0,  55,  20, 100,   0,  20, 300, 210, 290 },  
				  { 110,  20,   0, 111,  30,  67,   0, 113, 222,  35 },  
				  {  65, 220, 300,   0, 267,  56,  65,   0, 245, 199 },  
				  {   0,  10, 156,  25, 200, 210,  41, 205,   0, 100 },  
				  {  80,  50, 150,  10,   0, 114, 254,  33,  55,   0 } };
	int r[N]; // результат 

	t1 = clock();
	int s = salesman(
		N,          // [in]  количество городов 
		(int*)d,    // [in]  массив [n*n] расстояний 
		r           // [out] массив [n] маршрут 0 x x x x  
		);
	t2 = clock();

	cout << endl << "\t\t\t - ЗАДАЧА КОММИВОЯЖЕРА - " << endl;
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