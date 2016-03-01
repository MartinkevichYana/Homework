#include <iostream>
using namespace std;
void QuickSort(int* a, int N);
void QuickSort(int*, int, int);
void Swap(int *, int *);
void DisplayArray(int[], int);
void EnterArray(int a[], int N);

int const N = 10;

int main()
{
	int a[N];
	//EnterArray(a,N);
	for (int i = 0; i < N; i++)
		a[i] = rand() % 100;
	cout << endl << "My Array " << endl;
	DisplayArray(a, N);
	QuickSort(a, N);
	cout << endl << "Sorted array " << endl;
	DisplayArray(a, N);
	system("pause");
	return 0;
}



void QuickSort(int* a, int N)
{
	QuickSort(a, 0, N - 1);
}


void QuickSort(int* a, int left, int right)
{
	int i = left, j = right;
	int mid = a[(left + right) / 2];
	while (i <= j)
	{
		while (a[i] < mid)
			i++;
		while (a[j] > mid)
			j--;
		if (i <= j)
		{
			Swap(a + i, a + j);
			i++;
			j--;
		}
	}
	if (left < j)
		QuickSort(a, left, j);
	if (i < right)
		QuickSort(a, i, right);
}

void Swap(int *a, int *b)
{
	int temp = *a;
	*a = *b;
	*b = temp;
}

void DisplayArray(int a[], int N)
{
	for (int i = 0; i < N; i++)
		cout << a[i] << ' ';
}

/*void EnterArray(int a[], int N)
{
	for (int i = 0; i < N; i++)
		cin >> a[i];
}*/
