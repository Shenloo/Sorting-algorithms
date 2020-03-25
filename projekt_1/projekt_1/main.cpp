#include <iostream>
#include<ctime>
#include<stdlib.h>
#include"quicksort.h"
#include"mergesort.h"
#include"introsort.h"

#define SIZE_1M 1000000
#define SIZE_500k 500000
#define SIZE_100k 100000
#define SIZE_50k 50000
#define SIZE_10k 10000

using namespace std;

int main()
{
	int* pom = new int[SIZE_1M];
	int* qsM[100], * msM[100], * isM[100];
	int* qs500k[100], * ms500k[100], * is500k[100];
	int* qs100k[100], * ms100k[100], * is100k[100];
	int* qs50k[100], * ms50k[100], * is50k[100];
	int* qs10k[100], * ms10k[100], * is10k[100];
	

	double duration, time0, time1;
	clock_t start;
	srand((unsigned)time(NULL));

	/******************************************************************/
	/* elementy losowe                                                */
	/******************************************************************/

	cout << "Losowe elementy" << endl;

	////////////////////////////////////////////////////////////////////
	//  tab 1M
	////////////////////////////////////////////////////////////////////
	cout << "100* tab 1M :" << endl;

	//  quicksort 
	////////////////////////////////////////////////////////////////////

	
	duration = 0;
	for (int i = 0; i < 100; ++i)
	{
		qsM[i] = new int[SIZE_1M];
		for (int j = 0; j < SIZE_1M; ++j)
			qsM[i][j] = rand() % SIZE_1M;
		start = clock();
		time0 = (double)start;
		quicksort(0, SIZE_1M - 1, qsM[i]);
		time1 = (double)clock();
		duration += (time1 - time0) / (double)CLOCKS_PER_SEC;
		delete[] qsM[i];
	}
		
	cout << "quicksort = " << duration << " s" << endl;
		

	//  mergesort
	////////////////////////////////////////////////////////////////////

	duration = 0;

	for (int i = 0; i < 100; ++i)
	{
		msM[i] = new int[SIZE_1M];
		for (int j = 0; j < SIZE_1M; ++j)
			msM[i][j] = rand() % SIZE_1M;
		start = clock();
		time0 = (double)start;
		mergesort(msM[i], pom, 0, SIZE_1M - 1);
		time1 = (double)clock();
		duration += (time1 - time0) / (double)CLOCKS_PER_SEC;
		delete[] msM[i];
	}

	cout << "mergesort = " << duration << " s" << endl;

	//  introsort
	////////////////////////////////////////////////////////////////////

	duration = 0;

	for (int i = 0; i < 100; ++i)
	{
		isM[i] = new int[SIZE_1M];
		for (int j = 0; j < SIZE_1M; ++j)
			isM[i][j] = rand() % SIZE_1M;
		start = clock();
		time0 = (double)start;
		introsort(0, SIZE_1M - 1, isM[i]);
		time1 = (double)clock();
		duration += (time1 - time0) / (double)CLOCKS_PER_SEC;
		delete[] isM[i];
	}

	cout << "introsort = " << duration << " s" << endl;	

	////////////////////////////////////////////////////////////////////
	//  tab 500k
	////////////////////////////////////////////////////////////////////
	cout << "100* tab 500k :" << endl;

	//  quicksort 
	////////////////////////////////////////////////////////////////////

	duration = 0;

	for (int i = 0; i < 100; ++i)
	{
		qs500k[i] = new int[SIZE_500k];
		for (int j = 0; j < SIZE_500k; ++j)
			qs500k[i][j] = rand() % SIZE_500k;
		start = clock();
		time0 = (double)start;
		quicksort(0, SIZE_500k - 1, qs500k[i]);
		time1 = (double)clock();
		duration += (time1 - time0) / (double)CLOCKS_PER_SEC;
		delete[] qs500k[i];
	}

	cout << "quicksort = " << duration << " s" << endl;

	//  mergesort
	////////////////////////////////////////////////////////////////////

	duration = 0;

	for (int i = 0; i < 100; ++i)
	{
		ms500k[i] = new int[SIZE_500k];
		for (int j = 0; j < SIZE_500k; ++j)
			ms500k[i][j] = rand() % SIZE_500k;
		start = clock();
		time0 = (double)start;
		mergesort(ms500k[i], pom, 0, SIZE_500k - 1);
		time1 = (double)clock();
		duration += (time1 - time0) / (double)CLOCKS_PER_SEC;
		delete[] ms500k[i];
	}

	cout << "mergesort = " << duration << " s" << endl;	

	//  introsort
	////////////////////////////////////////////////////////////////////

	duration = 0;

	for (int i = 0; i < 100; ++i)
	{
		is500k[i] = new int[SIZE_500k];
		for (int j = 0; j < SIZE_500k; ++j)
			is500k[i][j] = rand() % SIZE_500k;
		start = clock();
		time0 = (double)start;
		introsort(0, SIZE_500k - 1, is500k[i]);
		time1 = (double)clock();
		duration += (time1 - time0) / (double)CLOCKS_PER_SEC;
		delete[] is500k[i];
	}
	
	cout << "introsort = " << duration << " s" << endl;
		
	////////////////////////////////////////////////////////////////////
	//  tab 100k
	////////////////////////////////////////////////////////////////////
	cout << "100* tab 100k :" << endl;

	//  quicksort 
	////////////////////////////////////////////////////////////////////

	duration = 0;

	for (int i = 0; i < 100; ++i)
	{
		qs100k[i] = new int[SIZE_100k];
		for (int j = 0; j < SIZE_100k; ++j)
			qs100k[i][j] = rand() % SIZE_100k;
		start = clock();
		time0 = (double)start;
		quicksort(0, SIZE_100k - 1, qs100k[i]);
		time1 = (double)clock();
		duration += (time1 - time0) / (double)CLOCKS_PER_SEC;
		delete[] qs100k[i];
	}

	cout << "quicksort = " << duration << " s" << endl;		

	//  mergesort
	////////////////////////////////////////////////////////////////////

	duration = 0;

	for (int i = 0; i < 100; ++i)
	{
		ms100k[i] = new int[SIZE_100k];
		for (int j = 0; j < SIZE_100k; ++j)
			ms100k[i][j] = rand() % SIZE_100k;
		start = clock();
		time0 = (double)start;
		mergesort(ms100k[i], pom, 0, SIZE_100k - 1);
		time1 = (double)clock();
		duration += (time1 - time0) / (double)CLOCKS_PER_SEC;
		delete[] ms100k[i];
	}
	
	cout << "mergesort = " << duration << " s" << endl;

	//  introsort
	////////////////////////////////////////////////////////////////////

	duration = 0;

	for (int i = 0; i < 100; ++i)
	{
		is100k[i] = new int[SIZE_100k];
		for (int j = 0; j < SIZE_100k; ++j)
			is100k[i][j] = rand() % SIZE_100k;
		start = clock();
		time0 = (double)start;
		introsort(0, SIZE_100k - 1, is100k[i]);
		time1 = (double)clock();
		duration += (time1 - time0) / (double)CLOCKS_PER_SEC;
		delete[] is100k[i];
	}
		
	cout << "introsort = " << duration << " s" << endl;		

	////////////////////////////////////////////////////////////////////
	//  tab 50k
	////////////////////////////////////////////////////////////////////
	cout << "100* tab 50k :" << endl;

	//  quicksort 
	////////////////////////////////////////////////////////////////////

	duration = 0;

	for (int i = 0; i < 100; ++i)
	{
		qs50k[i] = new int[SIZE_50k];
		for (int j = 0; j < SIZE_50k; ++j)
			qs50k[i][j] = rand() % SIZE_50k;
		start = clock();
		time0 = (double)start;
		quicksort(0, SIZE_50k - 1, qs50k[i]);
		time1 = (double)clock();
		duration += (time1 - time0) / (double)CLOCKS_PER_SEC;
		delete[] qs50k[i];
	}

	cout << "quicksort = " << duration << " s" << endl;

	//  mergesort
	////////////////////////////////////////////////////////////////////

	duration = 0;

	for (int i = 0; i < 100; ++i)
	{
		ms50k[i] = new int[SIZE_50k];
		for (int j = 0; j < SIZE_50k; ++j)
			ms50k[i][j] = rand() % SIZE_50k;
		start = clock();
		time0 = (double)start;
		mergesort(ms50k[i], pom, 0, SIZE_50k - 1);
		time1 = (double)clock();
		duration += (time1 - time0) / (double)CLOCKS_PER_SEC;
		delete[] ms50k[i];
	}

	cout << "mergesort = " << duration << " s" << endl;

	//  introsort
	////////////////////////////////////////////////////////////////////

	duration = 0;

	for (int i = 0; i < 100; ++i)
	{
		is50k[i] = new int[SIZE_50k];
		for (int j = 0; j < SIZE_50k; ++j)
			is50k[i][j] = rand() % SIZE_50k;
		start = clock();
		time0 = (double)start;
		introsort(0, SIZE_50k - 1, is50k[i]);
		time1 = (double)clock();
		duration += (time1 - time0) / (double)CLOCKS_PER_SEC;
		delete[] is50k[i];
	}

	cout << "introsort = " << duration << " s" << endl;	

	////////////////////////////////////////////////////////////////////
	//  tab 10k
	////////////////////////////////////////////////////////////////////
	cout << "100* tab 10k :" << endl;

	//  quicksort 
	////////////////////////////////////////////////////////////////////

	duration = 0;

	for (int i = 0; i < 100; ++i)
	{
		qs10k[i] = new int[SIZE_10k];
		for (int j = 0; j < SIZE_10k; ++j)
			qs10k[i][j] = rand() % SIZE_10k;
		start = clock();
		time0 = (double)start;
		quicksort(0, SIZE_10k - 1, qs10k[i]);
		time1 = (double)clock();
		duration += (time1 - time0) / (double)CLOCKS_PER_SEC;
		delete[] qs10k[i];
	}
	
	cout << "quicksort = " << duration << " s" << endl;
		

	//  mergesort
	////////////////////////////////////////////////////////////////////

	duration = 0;

	for (int i = 0; i < 100; ++i)
	{
		ms10k[i] = new int[SIZE_10k];
		for (int j = 0; j < SIZE_10k; ++j)
			ms10k[i][j] = rand() % SIZE_10k;
		start = clock();
		time0 = (double)start;
		mergesort(ms10k[i], pom, 0, SIZE_10k - 1);
		time1 = (double)clock();
		duration += (time1 - time0) / (double)CLOCKS_PER_SEC;
		delete[] ms10k[i];
	}

	cout << "mergesort = " << duration << " s" << endl;	

	//  introsort
	////////////////////////////////////////////////////////////////////

	duration = 0;

	for (int i = 0; i < 100; ++i)
	{
		is10k[i] = new int[SIZE_10k];
		for (int j = 0; j < SIZE_10k; ++j)
			is10k[i][j] = rand() % SIZE_10k;
		start = clock();
		time0 = (double)start;
		introsort(0, SIZE_10k - 1, is10k[i]);
		time1 = (double)clock();
		duration += (time1 - time0) / (double)CLOCKS_PER_SEC;
		delete[] is10k[i];
	}
		
	cout << "introsort = " << duration << " s" << endl;		

}