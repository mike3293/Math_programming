#include <iostream>
#include <iomanip> 
#include "Combi.h"
#define N sizeof(AA)
#define M 3

using namespace std;

void main()
{
	setlocale(LC_ALL, "rus");
	char  AA[] = { 'Q', 'W', 'E', 'R' };
	cout << endl << "\t\t\t - ÃÅÍÅÐÀÒÎÐ ÐÀÇÌÅÙÅÍÈÉ - " << endl;
	cout << endl << "\t\tÈñõîäíîå ìíîæåñòâî: ";
	cout << "{ ";
	for (int i = 0; i < N; i++)
		cout << AA[i] << ((i< N - 1) ? ", " : " ");
	cout << "}";

	cout << endl << endl << "\t\tÃåíåðàöèÿ ðàçìåùåíèé  èç  " << N << " ïî " << M << endl;
	combi::accomodation s(N, M);
	int  n = s.getfirst();
	while (n >= 0)
	{
		cout << endl << "\t\t\t\t{ ";
		for (int i = 0; i < 3; i++)
			cout << AA[s.ntx(i)] << ((i< n - 1) ? ", " : " ");
		cout << "}";
		n = s.getnext();
	};
	cout << endl << "âñåãî: " << s.count() << endl;
	system("pause");
}