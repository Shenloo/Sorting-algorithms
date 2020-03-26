#include"heapsort.h"

/* Funkcja sortowania introspektywnego            */
/***************************************************/
template<typename E>
void introsort(int l, int r, E tab[])
{
    int i = 0;
    int x = r - l + 1;
    if (l < r && x > 9)
    {
        i = partition(l, r, tab);
        introsort(l, i , tab);
        introsort(i + 1, r, tab);
    }
    else
    {
        int a = l;
        int b = r;
        int i = 1;
        int size = b - a + 1;
        E pom[10];
        pom[0] = 0;
        while (a <= b)
        {
            pom[i] = tab[a];
            ++a;
            ++i;
        }
        heapsort(pom, size);
        i = 1;
        a = l;
        while (a <= b)
        {
            tab[a] = pom[i];
            ++a;
            ++i;
        }
    }

}
