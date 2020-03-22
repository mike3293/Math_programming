#include <iostream>
#define N 4

using namespace std;

void main()
{
	setlocale(0, "");

	char  M[N] = { 'D', 'I', 'M', 'A' };
	cout << endl << "\t\t - ÃÅÍÅÐÀÒÎÐ ÌÍÎÆÅÑÒÂÀ ÂÑÅÕ ÏÎÄÌÍÎÆÅÑÒÂ - " << endl;

	cout << endl << "\t\tÈñõîäíîå ìíîæåñòâî: ";
	cout << "{ ";
	for (int i = 0; i < N; i++)
		cout << M[i] << " ";
	cout << "}";

	int n = pow(2, N);

	cout << endl << endl << "\t\t\tÃåíåðàöèÿ âñåõ ïîäìíîæåñòâ: ";
	for (int i = 0; i < n; i++)
	{
		cout << endl << "\t\t\t\t{ ";
		for (int j = 0; j < N; j++)
			if (i & (1 << j))
				cout << M[j] << " ";
		cout << "}";
	}
	cout << endl << "Áóëåàí ìíîæåñòâà: " << n << endl;
	system("pause");
}
