#pragma once
#include<iostream>

using namespace std;

template<typename E>
void swap(int l, int r, E tab[]);

template<typename E>
int partition(int l, int r, E tab[]);

template<typename E>
void quicksort(int l, int r, E tab[]);

#include"quicksort.tpp"