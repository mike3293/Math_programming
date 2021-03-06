#include <iostream>
#include <ctime>
#include <locale>
#include "Auxil.h"

int main()
{
	setlocale(LC_ALL, "rus");

	int CYCLE = 1000000;
	int av1 = 0;
	double av2 = 0;
	clock_t t1 = 0, t2 = 0;
	auxil::start();// старт генерации 

	for (int i = 0; i < 9; i++)
	{
		t1 = clock();	// фиксация времени
		for (int j = 0; j < CYCLE; j++)
		{
			av1 += (double)auxil::iget(-100, 100); // сумма случайных чисел 
			av2 += auxil::dget(-100, 100);         // сумма случайных чисел 
		}
		t2 = clock();      // фиксация времени                         // фиксация времени 
		av1 = av2 = 0;
		std::cout << std::endl << "количество циклов:         " << CYCLE;
		std::cout << std::endl << "продолжительность (у.е):   " << (t2 - t1);
		std::cout << std::endl << "                  (сек):   " << ((double)(t2 - t1)) / ((double)CLOCKS_PER_SEC);
		std::cout << std::endl;
		CYCLE += 1000000;
	}
	system("pause");
	return 0;
}

