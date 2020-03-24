#pragma once
#include<iostream>

using namespace std;

template<typename E>
void merge(E tab[], E p[], int iyoung, int iold, int ilast);

template<typename E>
void mergesort(E tab[], E p[], int iyoung, int ilast);

#include"mergesort.tpp"