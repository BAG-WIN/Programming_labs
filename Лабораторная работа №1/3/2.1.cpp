// ������� 2.1
// �������� � ������� ���������� ��������� ����� :
// �) 25 �������������� �����, ������� � ��������� �� �50 �� 50;
// �) 30 ����� �����, ������� � ��������� �� �20 �� 20;
// �) 20 ��������������� �������������� �����, �� ������������� 40;
// �) 35 ��������������� ����� �����, �� ������������� 1000;
// �) 27 ����������� �����, �� ������������� 20;
// �) ����������� n, �� ������������� 30, � n �������������� �����, ������� � ��������� �� �100 �� 100;
// �) 5 ��������������� ��������� ����.


#include <stdlib.h>
#include <stdio.h> 
#include <time.h>

double random()
{
	return (double)rand() / RAND_MAX;
}

void main()
{
	time_t t;
	srand((unsigned)time(&t));

	printf("\na) 25 float numbers from -50 to 50:\n");
	for (int i = 0; i < 25; i++)
		printf("\t%d: %f\n", i + 1, random() * 100 - 50);

	printf("\nb) 30 numbers from -20 to 20:\n");
	for (int i = 0; i < 30; i++)
		printf("\t%d: %d\n", i + 1, (int)(random() * 40) - 20);

	printf("\nc) 20 float numbers from 0 to 40:\n");
	for (int i = 0; i < 20; i++)
		printf("\t%d: %f\n", i + 1, random() * 40);

	printf("\nd) 35 numbers from 0 to 1000:\n");
	for (int i = 0; i < 35; i++)
		printf("\t%d: %d\n", i + 1, (int)(random() * 1000));

	printf("\ne) 27 numbers from 1 to 20:\n");
	for (int i = 0; i < 27; i++)
		printf("\t%d: %d\n", i + 1, (int)(random() * 20) + 1);

	printf("\nf) n from 1 to 30 and n numbers from -100 to 100:\n");
	int n = (int)(random() * 30) + 1;
	printf("\tn = %d\n", n);
	for (int i = 0; i < n; i++)
		printf("\t%d: %d\n", i + 1, (int)(random() * 200) - 100);

	printf("\ng) 5 latin latter:\n");
	char latin[26] = "ABCDEFGHIJKLMNOPQRSTUVXYZ";
	for (int i = 0; i < 5; i++)
	{
		int j = rand() % 25;
		if (latin[j] != ' ')
		{
			printf("\t%d: %c\n", i + 1, latin[j]);
			latin[j] = ' ';
		}
		else
			i--;
	}
}