template<typename E>
void swap(int l, int r, E tab[])
{
    int temp;
    temp = tab[l];
    tab[l] = tab[r];
    tab[r] = temp;
}

template<typename E>
int partition(int l, int r, E tab[])
{
    int position = l;
    int pivot_index = (l + r) / 2;
    int pivot = tab[pivot_index];
    swap(pivot_index, r, tab);
    for (int i = l; i < r; ++i)
        if (tab[i] < pivot)
        {
            swap(position, i, tab);
            ++position;
        }
    swap(position, r, tab);
    return position;
}

template<typename E>
void quicksort(int l, int r, E tab[])
{
    int i = 0;
    if (l < r)
    {
        i = partition(l, r, tab);
        quicksort(l, i - 1, tab);
        quicksort(i + 1, r, tab);
    }

}