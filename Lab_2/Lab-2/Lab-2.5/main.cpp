//#include <iostream>
//#include <iomanip> 
//#include "Salesman.h"
//#include <ctime>
//
//using namespace std;
//
//void main()
//{
//	setlocale(0, "");
//
//	srand((unsigned)time(NULL));
//	for (int N = 6; N < 12; N++) {
//		clock_t  t1 = 0, t2 = 0;
//
//		int **d = new int*[N];
//		for (int i = 0; i < N; i++)
//			d[i] = new int[N];
//
//		for (int i = 0; i < N; i++)
//		{
//			for (int j = 0; j < N; j++)
//			{
//				if (j == i)
//				{
//					d[i][j] = 0;
//					continue;
//				}
//				d[i][j] = rand() % (300 - 10 + 1) + 10;
//			}
//		}
//		d[0][2] = INF;
//		d[4][5] = INF;
//		d[5][3] = INF;
//
//		int *r = new int[N]; // результат 
//
//		t1 = clock();
//		int s = salesman(
//			N,          // [in]  количество городов 
//			(int*)d,    // [in]  массив [n*n] расстояний 
//			r           // [out] массив [n] маршрут 0 x x x x  
//		);
//		t2 = clock();
//
//		cout << endl << "- ЗАДАЧА КОММИВОЯЖЕРА -" << endl;
//		cout << endl << "Количество  городов: " << N;
//		cout << endl << "Матрица расстояний : ";
//		for (int i = 0; i < N; i++)
//		{
//			cout << endl;
//			for (int j = 0; j < N; j++)
//				if (d[i][j] != INF)
//					cout << setw(3) << d[i][j] << " ";
//				else
//					cout << setw(3) << "INF" << " ";
//		}
//		cout << endl << endl << "Оптимальный маршрут: ";
//		for (int i = 0; i < N; i++)
//			cout << r[i] << "-->";
//		cout << 0;
//		cout << endl << "Длина маршрута     : " << s << endl;
//		cout << endl << "Продолжительность вычеслений (сек): " << ((double)(t2 - t1)) / ((double)CLOCKS_PER_SEC) << endl << endl;
//		delete d;
//	}
//	
//	system("pause");
//}

// 3-rd lab
#include <iostream>
#include <iomanip> 
#include "Salesman.h"
#include <ctime>
#define N 5
using namespace std;

void main()
{
	setlocale(0, "");

	srand((unsigned)time(NULL));
	clock_t  t1 = 0, t2 = 0;

	int var = 5;
	int d[N][N] = { //0   1    2    3     4        
{ INF,  2*var, 21+var,  INF,   var },    //  0
{ var,   INF,  15+var,  68-var,  84-var },    //  1
{ 2+var,  3*var,   INF,  86,   49+var },    //  2 
{ 17+var,  58-var,  4*var,   INF,   3*var },    //  3
{ 93-var,  66+var,  52,  13+var,    INF } };   //  4  
	int r[N];                     // результат 

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