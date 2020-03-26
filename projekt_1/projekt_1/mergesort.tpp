/* Funkcja laczaca dwa zbiory w jeden wraz z ich uporzadkowaniem         */
/* Wykorzystuje indeks pierwszego elementeu w pierwszym i drugim zbiorze */
/*************************************************************************/
template<typename E>
void merge(E tab[], E p[], int iyoung, int iold, int ilast)
{
	int i1 = iyoung;
	int i = i1;
	int i2 = iold;


	for (i = iyoung; i <= ilast; ++i)
	{
		if (i1 == iold || (i2 <= ilast && (tab[i1] > tab[i2])))
		{
			p[i] = tab[i2];
			++i2;
		}
		else
		{
			p[i] = tab[i1];
			++i1;
		}
	}
	for (i = iyoung; i <= ilast; ++i)
	{
		tab[i] = p[i];
	}
}

/* Funkcja sortowania przez scalanie               */
/***************************************************/
template<typename E>
void mergesort(E tab[], E p[], int iyoung, int ilast)
{
	int iold = (iyoung + ilast + 1) / 2;

	if (iold - iyoung > 1)
		mergesort(tab, p, iyoung, iold - 1);
	if (ilast - iold > 0)
		mergesort(tab, p, iold, ilast);
	merge(tab, p, iyoung, iold, ilast);
}