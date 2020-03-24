#include"heapsort.h"
template<typename E>
void introsort(int l, int r, E tab[])
{
    int i = 0;
    if (l < r && r > 9)
    {
        i = partition(l, r, tab);
        quicksort(l, i - 1, tab);
        quicksort(i + 1, r, tab);
    }
    else
    {
        int j = l;
        int size = r - l + 1;
        int pom[10];
        for (int i = 1; i <= size; ++i)
        {
            pom[i] = tab[j];
            ++j;
        }

        buildheap(pom, size);
        heapsort(pom, size);

        j = l;
        for (int i = 1; i <= size; ++i)
        {
            tab[j] = pom[i];
            ++j;
        }
    }

}