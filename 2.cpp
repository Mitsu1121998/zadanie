#include <iostream>
#include <cstdlib>
#include <ctime>
#include <iomanip>
using namespace std;
clock_t start, stop;
double czas;

double bubble(int a[])
{
	int i, j, temp, pass = 0;
	for (i = 0; i < 10; i++)
	{
		cout << a[i] << "\t";
	}
	cout << endl;
	for (i = 0; i < 10; i++)
	{
		for (j = i + 1; j < 10; j++)
		{
			if (a[j] < a[i])
			{
				temp = a[i];
				a[i] = a[j];
				a[j] = temp;
			}
		}
		pass++;
		return 0;
	}
}
void quick_sort(int *tab, int left, int right)
{
	if (right <= left)
		return;

	int i = left - 1, j = right + 1,
		pivot = tab[(left + right) / 2];

	while (1)
	{
		while (pivot > tab[++i])
			;

		while (pivot < tab[--j])
			;

		if (i <= j)

			swap(tab[i], tab[j]);
		else
			break;
	}

	if (j > left)
		quick_sort(tab, left, j);
	if (i < right)
		quick_sort(tab, i, right);
}

int main()
{
	srand(time(NULL));

	int *tab, n = 10;

	tab = new int[n];

	for (int i = 0; i < n; i++)
	{
		tab[i] = rand() % 101;
	}

	start = clock();
	quick_sort(tab, 0, n - 1);
	czas = (stop - start) / double(CLOCKS_PER_SEC);
	cout << "czas bubble = " << czas << endl;
	cin.ignore();
	cin.get();
	delete[] tab;
	tab = new int[rand()];
	start = clock();
	bubble(tab);
	stop = clock();
	czas = (stop - start) / double(CLOCKS_PER_SEC);
	cout << "czas bubble = " << czas << endl;
	delete[] tab;
	return 0;
}
