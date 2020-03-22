#include <iostream>
#include "Combi.h"

using namespace std;

void main()
{
	setlocale(0, "");

	char  AA[] = { 'Q', 'W', 'E', 'R' };
	cout << endl << "\t\t - ��������� ��������� ���� ����������� - " << endl;

	cout << endl << "\t\t�������� ���������: ";
	cout << "{ ";
	for (int i = 0; i < sizeof(AA); i++)
		cout << AA[i] << ((i < sizeof(AA) - 1) ? ", " : " ");
	cout << "}";

	combi::xcombination xc(sizeof(AA), 3);
	cout << endl << endl << "\t\t\t��������� ���� ����������� " << "�� " << xc.n << " �� " << xc.m << ":" << endl;
	
	int  n = xc.getfirst();
	while (n >= 0)
	{
		cout << endl << "\t\t\t\t{ ";
		for (int i = 0; i < n; i++)
			cout << AA[xc.ntx(i)] << ((i< n - 1) ? ", " : " ");
		cout << "}";
		n = xc.getnext();
	};
	cout << endl << "�����: " << xc.count() << endl;
	system("pause");
}