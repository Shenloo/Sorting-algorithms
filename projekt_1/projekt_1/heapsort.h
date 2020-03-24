#pragma once
#include<iostream>
#include"quicksort.h"

using namespace std;

template<typename E>
void upheap(E tab[], int last);

template<typename E>
void downheap(E tab[], int size, int i);

template<typename E>
void buildheap(E tab[], int n);

template<typename E>
void heapsort(E tab[], int size);

#include"heapsort.tpp"