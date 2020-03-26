#include <iostream>
#include<ctime>
#include<stdlib.h>
#include "quicksort.h"
#include "mergesort.h"
#include "introsort.h"

#define SIZE_1M 1000000
#define SIZE_500k 500000
#define SIZE_100k 100000
#define SIZE_50k 50000
#define SIZE_10k 10000


using namespace std;

/* Funkcja sluzaca do odwrocenia kolejnosci elementow w tablicy*/
template<typename E>
void reverse(int l, int r, E tab[])
{
	int a = l;
	int b = r;
	while (a < b)
	{
		swap(a, b, tab);
		++a;
		--b;
	}
}

int main()
{
	int size = 15;
	int* tab1, * tab2, * tab3, * pom;
	tab1 = new int[size];
	tab2 = new int[size];
	tab3 = new int[size];
	pom = new int[size];
	
	srand((unsigned)time(NULL));

	for (int i = 0; i < size; ++i)
	{
		tab1[i] = rand() % size;
		tab2[i] = rand() % size;
		tab3[i] = rand() % size;
	}

	cout << "Tablica 1 przed sortowaniem" << endl;
	for (int i = 0; i < size; ++i)
		cout << tab1[i] << " ";
	quicksort(0, size - 1, tab1);
	cout << endl << "Tablica 1 po sortowaniu szybkim" << endl;
	for (int i = 0; i < size; ++i)
		cout << tab1[i] << " ";

	cout <<endl<<endl<< "Tablica 2 przed sortowaniem" << endl;
	for (int i = 0; i < size; ++i)
		cout << tab2[i] << " ";
	mergesort(tab2, pom, 0, size - 1);
	cout << endl << "Tablica 2 po sorotowaniu przez scalanie" << endl;
	for (int i = 0; i < size; ++i)
		cout << tab2[i] << " ";

	cout <<endl<<endl<< "Tablica 3 przed sortowaniem" << endl;
	for (int i = 0; i < size; ++i)
		cout << tab3[i] << " ";
	introsort(0,size-1,tab3);
	cout << endl << "Tablica 3 po sortowaniu introspektywnym" << endl;
	for (int i = 0; i < size; ++i)
		cout << tab3[i] << " ";


	/* Kod sluzacy do zbadania algorytmow sortujacych

	int* pom = new int[SIZE_1M];
	int* qsM[100], * msM[100], * isM[100];
	int* qs500k[100], * ms500k[100], * is500k[100];
	int* qs100k[100], * ms100k[100], * is100k[100];
	int* qs50k[100], * ms50k[100], * is50k[100];
	int* qs10k[100], * ms10k[100], * is10k[100];
	double sort_type[8] = { 1, 0.25,0.5,0.75,0.95,0.99,0.997, 1 };

	double duration, time0, time1;
	clock_t start;
	srand((unsigned)time(NULL));


	/******************************************************************/
	/* 0 - elementy losowe											  */
	/* 1 - 25% posortowania                                           */
	/* 2 - 50% posortowania                                           */
	/* 3 - 75% posortowania                                           */
	/* 4 - 95% posortowania                                           */
	/* 5 - 99% posortowania                                           */
	/* 6 - 99,7% posortowania										  */
	/* 7 - odwrotnie posortowane elementy							  */
	/******************************************************************

	////////////////////////////////////////////////////////////////////
	//  tab 1M
	////////////////////////////////////////////////////////////////////
	cout<< "100* tab 1M :" << endl;

	//  quicksort 
	////////////////////////////////////////////////////////////////////
	for (int z = 0; z < 8; ++z)
	{
		duration = 0;
		for (int i = 0; i < 100; ++i)
		{
			qsM[i] = new int[SIZE_1M];
			for (int j = 0; j < SIZE_1M; ++j)
				qsM[i][j] = rand() % SIZE_1M;
			if (z > 0 && z <= 7)
				mergesort(qsM[i], pom, 0, sort_type[z] * SIZE_1M - 1);
			if (z == 7)
			{
				reverse(0, SIZE_1M - 1, qsM[i]);
			}
			start = clock();
			time0 = (double)start;
			quicksort(0, SIZE_1M - 1, qsM[i]);
			time1 = (double)clock();
			duration += (time1 - time0) / (double)CLOCKS_PER_SEC;
			delete[] qsM[i];
		}
		cout << z << " quicksort = " << duration << " s" << endl;
	}
	//  mergesort
	////////////////////////////////////////////////////////////////////

	for (int z = 0; z < 8; ++z)
	{
		duration = 0;
		for (int i = 0; i < 100; ++i)
		{
			msM[i] = new int[SIZE_1M];
			for (int j = 0; j < SIZE_1M; ++j)
				msM[i][j] = rand() % SIZE_1M;
			if (z > 0 && z <= 7)
				mergesort(msM[i], pom, 0, sort_type[z] * SIZE_1M - 1);
			if (z == 7)
			{
				reverse(0, SIZE_1M - 1, msM[i]);
			}
			start = clock();
			time0 = (double)start;
			mergesort(msM[i], pom, 0, SIZE_1M - 1);
			time1 = (double)clock();
			duration += (time1 - time0) / (double)CLOCKS_PER_SEC;
			delete[] msM[i];
		}
		cout << z << " mergesort = " << duration << " s" << endl;
	}
	//  introsort
	////////////////////////////////////////////////////////////////////

	for (int z = 0; z < 8; ++z)
	{
		duration = 0;
		for (int i = 0; i < 100; ++i)
		{
			isM[i] = new int[SIZE_1M];
			for (int j = 0; j < SIZE_1M; ++j)
				isM[i][j] = rand() % SIZE_1M;
			if (z > 0 && z <= 7)
				mergesort(isM[i], pom, 0, sort_type[z] * SIZE_1M - 1);
			if (z == 7)
			{
				reverse(0, SIZE_1M - 1, isM[i]);
			}
			start = clock();
			time0 = (double)start;
			introsort(0, SIZE_1M - 1, isM[i]);
			time1 = (double)clock();
			duration += (time1 - time0) / (double)CLOCKS_PER_SEC;
			delete[] isM[i];
		}
		cout << z << " introsort = " << duration << " s" << endl;
	}
	////////////////////////////////////////////////////////////////////
	//  tab 500k
	////////////////////////////////////////////////////////////////////
	cout << endl << "100* tab 500k :" << endl;

	//  quicksort 
	////////////////////////////////////////////////////////////////////

	for (int z = 0; z < 8; ++z)
	{
		duration = 0;
		for (int i = 0; i < 100; ++i)
		{
			qs500k[i] = new int[SIZE_500k];
			for (int j = 0; j < SIZE_500k; ++j)
				qs500k[i][j] = rand() % SIZE_500k;
			if (z > 0 && z <= 7)
				mergesort(qs500k[i], pom, 0, sort_type[z] * SIZE_500k - 1);
			if (z == 7)
			{
				reverse(0, SIZE_500k - 1, qs500k[i]);
			}
			start = clock();
			time0 = (double)start;
			quicksort(0, SIZE_500k - 1, qs500k[i]);
			time1 = (double)clock();
			duration += (time1 - time0) / (double)CLOCKS_PER_SEC;
			delete[] qs500k[i];
		}
		cout << z << " quicksort = " << duration << " s" << endl;
	}
	//  mergesort
	////////////////////////////////////////////////////////////////////

	for (int z = 0; z < 8; ++z)
	{
		duration = 0;
		for (int i = 0; i < 100; ++i)
		{
			ms500k[i] = new int[SIZE_500k];
			for (int j = 0; j < SIZE_500k; ++j)
				ms500k[i][j] = rand() % SIZE_500k;
			if (z > 0 && z <= 7)
				mergesort(ms500k[i], pom, 0, sort_type[z] * SIZE_500k - 1);
			if (z == 7)
			{
				reverse(0, SIZE_500k - 1, ms500k[i]);
			}
			start = clock();
			time0 = (double)start;
			mergesort(ms500k[i], pom, 0, SIZE_500k - 1);
			time1 = (double)clock();
			duration += (time1 - time0) / (double)CLOCKS_PER_SEC;
			delete[] ms500k[i];
		}
		cout << z << " mergesort = " << duration << " s" << endl;
	}
	//  introsort
	////////////////////////////////////////////////////////////////////

	for (int z = 0; z < 8; ++z)
	{
		duration = 0;
		for (int i = 0; i < 100; ++i)
		{
			is500k[i] = new int[SIZE_500k];
			for (int j = 0; j < SIZE_500k; ++j)
				is500k[i][j] = rand() % SIZE_500k;
			if (z > 0 && z <= 7)
				mergesort(is500k[i], pom, 0, sort_type[z] * SIZE_500k - 1);
			if (z == 7)
			{
				reverse(0, SIZE_500k - 1, is500k[i]);
			}
			start = clock();
			time0 = (double)start;
			introsort(0, SIZE_500k - 1, is500k[i]);
			time1 = (double)clock();
			duration += (time1 - time0) / (double)CLOCKS_PER_SEC;
			delete[] is500k[i];
		}
		cout << z << " introsort = " << duration << " s" << endl;
	}
	////////////////////////////////////////////////////////////////////
	//  tab 100k
	////////////////////////////////////////////////////////////////////
	cout << endl << "100* tab 100k :" << endl;

	//  quicksort 
	////////////////////////////////////////////////////////////////////

	for (int z = 0; z < 8; ++z)
	{
		duration = 0;
		for (int i = 0; i < 100; ++i)
		{
			qs100k[i] = new int[SIZE_100k];
			for (int j = 0; j < SIZE_100k; ++j)
				qs100k[i][j] = rand() % SIZE_100k;
			if (z > 0 && z <= 7)
				mergesort(qs100k[i], pom, 0, sort_type[z] * SIZE_100k - 1);
			if (z == 7)
			{
				reverse(0, SIZE_100k - 1, qs100k[i]);
			}
			start = clock();
			time0 = (double)start;
			quicksort(0, SIZE_100k - 1, qs100k[i]);
			time1 = (double)clock();
			duration += (time1 - time0) / (double)CLOCKS_PER_SEC;
			delete[] qs100k[i];
		}
		cout << z << " quicksort = " << duration << " s" << endl;
	}
	//  mergesort
	////////////////////////////////////////////////////////////////////

	for (int z = 0; z < 8; ++z)
	{
		duration = 0;
		for (int i = 0; i < 100; ++i)
		{
			ms100k[i] = new int[SIZE_100k];
			for (int j = 0; j < SIZE_100k; ++j)
				ms100k[i][j] = rand() % SIZE_100k;
			if (z > 0 && z <= 7)
				mergesort(ms100k[i], pom, 0, sort_type[z] * SIZE_100k - 1);
			if (z == 7)
			{
				reverse(0, SIZE_100k - 1, ms100k[i]);
			}
			start = clock();
			time0 = (double)start;
			mergesort(ms100k[i], pom, 0, SIZE_100k - 1);
			time1 = (double)clock();
			duration += (time1 - time0) / (double)CLOCKS_PER_SEC;
			delete[] ms100k[i];
		}
		cout << z << " mergesort = " << duration << " s" << endl;
	}
	//  introsort
	////////////////////////////////////////////////////////////////////

	for (int z = 0; z < 8; ++z)
	{
		duration = 0;
		for (int i = 0; i < 100; ++i)
		{
			is100k[i] = new int[SIZE_100k];
			for (int j = 0; j < SIZE_100k; ++j)
				is100k[i][j] = rand() % SIZE_100k;
			if (z > 0 && z <= 7)
				mergesort(is100k[i], pom, 0, sort_type[z] * SIZE_100k - 1);
			if (z == 7)
			{
				reverse(0, SIZE_100k - 1, is100k[i]);
			}
			start = clock();
			time0 = (double)start;
			introsort(0, SIZE_100k - 1, is100k[i]);
			time1 = (double)clock();
			duration += (time1 - time0) / (double)CLOCKS_PER_SEC;
			delete[] is100k[i];
		}
		cout << z << " introsort = " << duration << " s" << endl;
	}
	////////////////////////////////////////////////////////////////////
	//  tab 50k
	////////////////////////////////////////////////////////////////////
	cout << endl << "100* tab 50k :" << endl;

	//  quicksort 
	////////////////////////////////////////////////////////////////////

	for (int z = 0; z < 8; ++z)
	{
		duration = 0;
		for (int i = 0; i < 100; ++i)
		{
			qs50k[i] = new int[SIZE_50k];
			for (int j = 0; j < SIZE_50k; ++j)
				qs50k[i][j] = rand() % SIZE_50k;
			if (z > 0 && z <= 7)
				mergesort(qs50k[i], pom, 0, sort_type[z] * SIZE_50k - 1);
			if (z == 7)
			{
				reverse(0, SIZE_50k - 1, qs50k[i]);
			}
			start = clock();
			time0 = (double)start;
			quicksort(0, SIZE_50k - 1, qs50k[i]);
			time1 = (double)clock();
			duration += (time1 - time0) / (double)CLOCKS_PER_SEC;
			delete[] qs50k[i];
		}
		cout << z << " quicksort = " << duration << " s" << endl;
	}
	//  mergesort
	////////////////////////////////////////////////////////////////////

	for (int z = 0; z < 8; ++z)
	{
		duration = 0;
		for (int i = 0; i < 100; ++i)
		{
			ms50k[i] = new int[SIZE_50k];
			for (int j = 0; j < SIZE_50k; ++j)
				ms50k[i][j] = rand() % SIZE_50k;
			if (z > 0 && z <= 7)
				mergesort(ms50k[i], pom, 0, sort_type[z] * SIZE_50k - 1);
			if (z == 7)
			{
				reverse(0, SIZE_50k - 1, ms50k[i]);
			}
			start = clock();
			time0 = (double)start;
			mergesort(ms50k[i], pom, 0, SIZE_50k - 1);
			time1 = (double)clock();
			duration += (time1 - time0) / (double)CLOCKS_PER_SEC;
			delete[] ms50k[i];
		}
		cout << z << " mergesort = " << duration << " s" << endl;
	}
	//  introsort
	////////////////////////////////////////////////////////////////////

	for (int z = 0; z < 8; ++z)
	{
		duration = 0;
		for (int i = 0; i < 100; ++i)
		{
			is50k[i] = new int[SIZE_50k];
			for (int j = 0; j < SIZE_50k; ++j)
				is50k[i][j] = rand() % SIZE_50k;
			if (z > 0 && z <= 7)
				mergesort(is50k[i], pom, 0, sort_type[z] * SIZE_50k - 1);
			if (z == 7)
			{
				reverse(0, SIZE_50k - 1, is50k[i]);
			}
			start = clock();
			time0 = (double)start;
			introsort(0, SIZE_50k - 1, is50k[i]);
			time1 = (double)clock();
			duration += (time1 - time0) / (double)CLOCKS_PER_SEC;
			delete[] is50k[i];
		}
		cout << z << " introsort = " << duration << " s" << endl;
	}
	////////////////////////////////////////////////////////////////////
	//  tab 10k
	////////////////////////////////////////////////////////////////////
	cout << endl << "100* tab 10k :" << endl;

	//  quicksort 
	////////////////////////////////////////////////////////////////////


	for (int z = 0; z < 8; ++z)
	{
		duration = 0;
		for (int i = 0; i < 100; ++i)
		{
			qs10k[i] = new int[SIZE_10k];
			for (int j = 0; j < SIZE_10k; ++j)
				qs10k[i][j] = rand() % SIZE_10k;
			if (z > 0 && z <= 7)
				mergesort(qs10k[i], pom, 0, sort_type[z] * SIZE_10k - 1);
			if (z == 7)
			{
				reverse(0, SIZE_10k - 1, qs10k[i]);
			}
			start = clock();
			time0 = (double)start;
			quicksort(0, SIZE_10k - 1, qs10k[i]);
			time1 = (double)clock();
			duration += (time1 - time0) / (double)CLOCKS_PER_SEC;
			delete[] qs10k[i];
		}

		cout << z << " quicksort = " << duration << " s" << endl;
	}

	//  mergesort
	////////////////////////////////////////////////////////////////////

	for (int z = 0; z < 8; ++z)
	{
		duration = 0;
		for (int i = 0; i < 100; ++i)
		{
			ms10k[i] = new int[SIZE_10k];
			for (int j = 0; j < SIZE_10k; ++j)
				ms10k[i][j] = rand() % SIZE_10k;
			if (z > 0 && z <= 7)
				mergesort(ms10k[i], pom, 0, sort_type[z] * SIZE_10k - 1);
			if (z == 7)
			{
				reverse(0, SIZE_10k - 1, ms10k[i]);
			}
			start = clock();
			time0 = (double)start;
			mergesort(ms10k[i], pom, 0, SIZE_10k - 1);
			time1 = (double)clock();
			duration += (time1 - time0) / (double)CLOCKS_PER_SEC;
			delete[] ms10k[i];
		}

		cout << z << " mergesort = " << duration << " s" << endl;
	}
	//  introsort
	////////////////////////////////////////////////////////////////////

	for (int z = 0; z < 8; ++z)
	{
		duration = 0;
		for (int i = 0; i < 100; ++i)
		{
			is10k[i] = new int[SIZE_10k];
			for (int j = 0; j < SIZE_10k; ++j)
				is10k[i][j] = rand() % SIZE_10k;
			if (z > 0 && z <= 7)
				mergesort(is10k[i], pom, 0, sort_type[z] * SIZE_10k - 1);
			if (z == 7)
			{
				reverse(0, SIZE_10k - 1, is10k[i]);
			}
			start = clock();
			time0 = (double)start;
			introsort(0, SIZE_10k - 1, is10k[i]);
			time1 = (double)clock();
			duration += (time1 - time0) / (double)CLOCKS_PER_SEC;
			delete[] is10k[i];
		}
		cout << z << " introsort = " << duration << " s" << endl;
	} */
	
}