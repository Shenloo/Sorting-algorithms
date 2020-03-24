template<typename E>
void upheap(E tab[], int last)
{
    int i = last;
    if (i == 1)
        ++i;
    while (i > 1)
    {
        if (tab[i] >= tab[i / 2])
            swap(tab[i], tab[i / 2]);
        i /= 2;
    }

}

template<typename E>
void downheap(E tab[], int size, int i)
{
    int left = 2 * i;
    int right = 2 * i + 1;
    int largest;

    if (left <= size && tab[left] > tab[i])
        largest = left;
    else
        largest = i;

    if (right <= size && tab[right] > tab[largest])
        largest = right;

    if (largest != i && largest <= size)
    {
        swap(tab[i], tab[largest]);
        downheap(tab, size, largest);
    }

}

template<typename E>
void buildheap(E tab[], int n)
{
    int i = 1;
    while (i <= n)
    {
        upheap(tab, i);
        ++i;
    }
}

template<typename E>
void heapsort(E tab[], int size)
{
    while (size >= 2)
    {
        swap(tab[1], tab[size]);
        size -= 1;
        downheap(tab, size, 1);
    }
}