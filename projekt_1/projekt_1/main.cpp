#include <iostream>
#include<ctime>
#include<stdlib.h>
#include"quicksort.h"
#include"mergesort.h"
#include"introsort.h"


using namespace std;

int main()
{
	int s = 1000000;
	int* tab1 = new int[s];
	int* tab2 = new int[s];
	int* tab3 = new int[s];
	int* temp = new int[s];
	double duration, time0, time1;
	clock_t start;
	srand((unsigned)NULL);

	for (int i = 0; i < s; ++i)
		tab1[i] = rand() % s;

	for (int i = 0; i < s; ++i)
	{
		tab2[i] = tab1[i];
		tab3[i] = tab1[i];
	}

	////////////////////////////////////////////////////////////////////
	//  quicksort 
	////////////////////////////////////////////////////////////////////

	start = clock();
	time0 = (double)start;

	quicksort(0, s - 1, tab1);

	time1 = (double)clock();
	duration = (time1 - time0) / (double)CLOCKS_PER_SEC;
	cout << "quicksort = " << duration << " s" << endl;

	////////////////////////////////////////////////////////////////////
	//  mergesort
	////////////////////////////////////////////////////////////////////

	start = clock();
	time0 = (double)start;

	mergesort(tab2, temp, 0, s - 1);

	time1 = (double)clock();
	duration = (time1 - time0) / (double)CLOCKS_PER_SEC;
	cout << "mergesort = " << duration << " s" << endl;

	////////////////////////////////////////////////////////////////////
	//  introsort
	////////////////////////////////////////////////////////////////////

	start = clock();
	time0 = (double)start;

	introsort(0, s - 1, tab3);

	time1 = (double)clock();
	duration = (time1 - time0) / (double)CLOCKS_PER_SEC;
	cout << "introsort = " << duration << " s" << endl;

	delete[] tab1;
	delete[] tab2;
	delete[] tab3;
	delete[] temp;
}