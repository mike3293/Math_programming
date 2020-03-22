#include <iostream>
#include "Combi.h"
#include <iomanip> 

using namespace std;

void main()
{
	setlocale(0, "");

	char  AA[] = { 'Q', 'W', 'E', 'R' };
	cout << endl << "\t\t\t - ÃÅÍÅÐÀÒÎÐ ÏÅÐÅÑÒÀÍÎÂÎÊ - " << endl;

	cout << endl << "\t\tÈñõîäíîå ìíîæåñòâî: ";
	cout << "{ ";
	for (int i = 0; i < sizeof(AA); i++)
		cout << AA[i] << ((i < sizeof(AA) - 1) ? ", " : " ");
	cout << "}";

	cout << endl << endl << "\t\t\tÃåíåðàöèÿ ïåðåñòàíîâîê:" << endl;
	combi::permutation p(sizeof(AA));
	__int64  n = p.getfirst();
	while (n >= 0)
	{
		cout << endl << "\t\t\t\t{ ";
		for (int i = 0; i < p.n; i++)
			cout << AA[p.ntx(i)] << ((i< p.n - 1) ? ", " : " ");
		cout << "}";
		n = p.getnext();
	};
	cout << endl << "âñåãî: " << p.count() << endl;
	system("pause");
}