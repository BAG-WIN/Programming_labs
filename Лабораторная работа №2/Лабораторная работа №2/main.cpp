#include <stdlib.h>
#include <stdio.h>
#include <time.h>
#include <iostream>
#include <algorithm>
#include <chrono>

using namespace std;

const int N = 50;

void output(short int a[], int sum, int ser)
{
	for (int i = 0; i < N; i++)
		printf("%hu ", a[i]);
	printf("\nКонтрольная сумма: %d\nКоличество серий: %d\n\n", sum, ser);
}

int partition(short int a[], int start, int end)
{
	short int pivot = a[end];

	int pIndex = start;

	for (int i = start; i < end; i++)
	{
		if (a[i] <= pivot)
		{
			swap(a[i], a[pIndex]);
			pIndex++;
		}
	}

	swap(a[pIndex], a[end]);

	return pIndex;
}

void quicksort(short int a[], int start, int end)
{
	if (start >= end) {
		return;
	}

	int pivot = partition(a, start, end);

	quicksort(a, start, pivot - 1);
	quicksort(a, pivot + 1, end);
}

void bucketsort(short int a[])
{
	short int buckets[6][N];
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < 6; j++) buckets[j][i] = 0;
		if (a[i] >= 10060 && a[i] <= 13500) buckets[0][i] = a[i];
		if (a[i] >= 13501 && a[i] <= 16941) buckets[1][i] = a[i];
		if (a[i] >= 16942 && a[i] <= 20382) buckets[2][i] = a[i];
		if (a[i] >= 20383 && a[i] <= 23823) buckets[3][i] = a[i];
		if (a[i] >= 23824 && a[i] <= 27264) buckets[4][i] = a[i];
		if (a[i] >= 27265 && a[i] <= 30706) buckets[5][i] = a[i];
	}
	for (int i = 0; i < 6; i++)
		quicksort(buckets[i], 0, N - 1);
	int k = 0;
	for (int i = 0; i < 6; i++)
	{
		for (int j = 0; j < N; j++)
		{
			if (buckets[i][j] != 0)
			{
				a[k] = buckets[i][j];
				k++;
			}
		}
	}
}

int main()
{
	printf("N = %d\n\n", N);
	setlocale(LC_ALL, "Russian");
	time_t t;
	srand((unsigned)time(&t));
	short int array1[N], array2[N], array1Copy[N], array2Copy[N];
	int sum1 = 0, sum2 = 0, ser1 = 1, ser2 = 1;
	for (int i = 0; i < N; i++)
	{
		int t = rand() % (30706 - 10060) + 10060;
		array1[i] = (short int)t;
		if (array1[i] < array1[i - 1]) ser1++;
		sum1 += array1[i];
		array1Copy[i] = (short int)t;

		t = rand() % (30706 - 10060) + 10060;
		array2[i] = (short int)t;
		if (array2[i] < array2[i - 1]) ser2++;
		sum2 += array2[i];
		array2Copy[i] = (short int)t;
	}
	printf("Массивы до сортировки:\n\n");
	output(array1, sum1, ser1);
	output(array2, sum2, ser2);

	sum1 = 0; sum2 = 0; ser1 = 1; ser2 = 1;
	unsigned int start_time = clock();

	quicksort(array1, 0, N - 1);

	unsigned int end_time = clock();
	unsigned int search_time = end_time - start_time;
	//cout << "Время быстрой сортировки: " << search_time / 1000.0 << " мс\n";
	//search_time / 1000.0
	quicksort(array2, 0, N - 1);
	for (int i = 0; i < N; i++)
	{
		if (array1[i] < array1[i - 1]) ser1++;
		sum1 += array1[i];

		if (array2[i] < array2[i - 1]) ser2++;
		sum2 += array2[i];
	}
	printf("Массивы после быстрой сортировки:\n\n");
	output(array1, sum1, ser1);
	output(array2, sum2, ser2);
	
	sum1 = 0; sum2 = 0; ser1 = 1; ser2 = 1;
	start_time = clock();

	bucketsort(array1Copy);

	end_time = clock();
	search_time = end_time - start_time;
	//cout << "Время блочной сортировки: " << search_time/1000.0 << " мс\n";
	bucketsort(array2Copy);
	for (int i = 0; i < N; i++)
	{
		if (array1[i] < array1[i - 1]) ser1++;
		sum1 += array1[i];

		if (array2[i] < array2[i - 1]) ser2++;
		sum2 += array2[i];
	}
	printf("Массивы после блочной сортировки:\n\n");
	output(array1, sum1, ser1);
	output(array2, sum2, ser2);
}