// Задание 2
//	   Получить с помощью генератора случайных чисел
// 200 чисел в интервале от 0 до 1. Оценить по ним 
// равномерность распределения. Разбить интервал(0, 1)
// на интервалов равной длины[0..0, 1), [0, 1..0, 2), …, [0, 9..1]
// и построить горизонтальную гистограмму(столбчатую диаграмму), 
// показывающую, сколько чисел попало в каждый интервал.
// Пример гистограммы :
//		0.0..0.1 *******
//		0.1..0.2 *********
//		…
//		0.9..1.0 *******

#include <stdlib.h>
#include <stdio.h> 
#include <time.h>
#include <random>
#include <chrono>

double random()
{
	return (double)rand() / RAND_MAX;
}

void main()
{
	time_t t;
	srand((unsigned)time(&t));
	int intervals[10];
	for (int i = 0; i < 10; i++)
		intervals[i] = 0;
	printf("200 random numbers from 0 to 1:\n\n");
	for (int i = 0; i < 200; i++)
	{
		double num = random();
		if (num <= 0.1) intervals[0]++;
		if (num > 0.1 && num <= 0.2) intervals[1]++;
		if (num > 0.2 && num <= 0.3) intervals[2]++;
		if (num > 0.3 && num <= 0.4) intervals[3]++;
		if (num > 0.4 && num <= 0.5) intervals[4]++;
		if (num > 0.5 && num <= 0.6) intervals[5]++;
		if (num > 0.6 && num <= 0.7) intervals[6]++;
		if (num > 0.7 && num <= 0.8) intervals[7]++;
		if (num > 0.8 && num <= 0.9) intervals[8]++;
		if (num > 0.9 && num <= 1) intervals[9]++;
		printf("\t%f\n", num);
	}
	printf("\n\nThe diagram:\n");
	for (int i = 0; i < 10; i++)
	{
		printf("0.%d..%d.%d ", i, (i + 1) / 10, (i + 1) % 10);
		for (int j = 0; j < intervals[i]; j++)
			printf("*");
		printf("\n");
	}
}