#include <iostream>
#include <cstdlib>
#include <ctime>
#include <iomanip>
using namespace std;
clock_t start, stop;
double czas;

void printt(int tab[], int n)
{
	if (n <= 10)
	{
		for (int i = 0; i < n; i++)
		{
			cout << tab[i] << "\t";
		}
		cout << endl;
	}
}

double bubble(int a[],int n)
{
	int i, j, temp, pass = 0;
	cout << endl;
	for (i = 0; i < n; i++)
	{
		for (j = i + 1; j < n; j++)
		{
			if (a[j] < a[i])
			{
				swap(a[i], a[j]);
			}
		}
		pass++;
	}
	return 0;
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
	for (int i = 0; i < 10; i++)
	{

		int *tab, n = 10;

		tab = new int[n];

		for (int i = 0; i < n; i++)
		{
			tab[i] = rand() % 101;
		}
		cout.precision(30);
		printt(tab, n);
		start = clock();
		quick_sort(tab, 0, n - 1);
		stop = clock();
		cout << endl;
		printt(tab, n);
		czas = double(stop - start) / double(CLOCKS_PER_SEC);
		cout << "czas quick = " << czas << endl;
		delete[] tab;
		tab = new int[n];
		for (int i = 0; i < n; i++)
		{
			tab[i] = rand() % 101;
		}
		printt(tab, n);
		start = clock();
		bubble(tab, n);
		stop = clock();
		printt(tab, n);
		czas = double(stop - start) / double(CLOCKS_PER_SEC);
		cout << "czas bubble = " << czas << endl;
		delete[] tab;
	}
	return 0;
}
