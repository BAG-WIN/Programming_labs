// ������� 1:
// ��������� ��������� ����� ����������� � ����������. 
// ��� ���������� ���������� �� ������� ����� ����������. 

#include <stdlib.h>
#include <stdio.h> 
#include <time.h>

void main()
{
	time_t t;
	srand((unsigned)time(&t));
	printf("Random number with type of 'int':\n");
	int num = rand();
	printf("%d\nThis number at 'long int' type:\n", num);
	long int new_type = num;
	printf("%ld\n", num);
}