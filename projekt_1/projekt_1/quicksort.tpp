/* Funkcja zamieniajaca dwa elementy w tablicy tab */
template<typename E>
void swap(int l, int r, E tab[])
{
    E temp;
    temp = tab[l];
    tab[l] = tab[r];
    tab[r] = temp;
}

/* Funkcja sluzaca do podzialu tablicy             */
/***************************************************/
template<typename E>
int partition(int l, int r, E tab[])
{
    E pivot = tab[(l+r)/2];
    int i = l-1;
    int j = r+1;

    for(;;)
    {
        do
             ++i;
        while(tab[i] < pivot);
        do
            --j;
        while(tab[j] > pivot);
        if(i >= j)
            return j;
        swap(i,j,tab);
    }
}

/* Funkcja sortowania szybkiego                    */
/***************************************************/
template<typename E>
void quicksort(int l, int r, E tab[])
{
    int i = 0;
    if (l < r)
    {
        i = partition(l, r, tab);
        quicksort(l, i , tab);
        quicksort(i + 1, r, tab);
    }

}