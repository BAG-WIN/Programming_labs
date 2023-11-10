// ������� 3:
// ��������� ��������� ��� ���� � ������.
// �������� �������� ����� ����� � ��������� �� 2 �� 12 � ������, 
// ������� �� ������ � ���� ���. ��������� � ������� 
// ���������� ��������� ����� ������ �������� ����� �� 1 �� 6 
// (�������� �����, �� ������ �������� ����� �� 1 �� 6). 
//    ���� ����� �������� ����� ������ ���� ����� 7 � �������� ������ 
// ����� ������ ���� ������ 7, �� ���������� ������.
// 	  ���� ����� �������� ���� ������ 7 � �������� ������ ������ 
// �� ����� ������ 7, �� ����� ���������� ������. 
// 	  ���� ����� ������ ����� ����, �� �������� � 4 ���� ������ �����,
// ��� ��������� ������. 
// 	  ������ ���������, ���� �� ���� �� ��������� �������� �� ����� �����.
// � ��������� ������ � ������ � ���������� �� 100 �����.
// ���� ���� �� ��� ���, ���� � ����-���� �� �������� �� ��������� 0 �����.

#define _CRT_SECURE_NO_WARNINGS
#include <stdlib.h>
#include <stdio.h> 
#include <time.h>

void main()
{
	time_t t;
	srand((unsigned)time(&t));
	int playerScore = 100, computerScore = 100;
	int stavka, num, n1, n2;
	while (playerScore > 0 && computerScore > 0)
	{
		printf("Player: %d\nComputer: %d\n", playerScore, computerScore);
		do {
			printf("Input your number:\n");
			scanf("%d", &num);
		} while (num < 2 || num > 12);
		do {
			printf("Input cash:\n");
			scanf("%d", &stavka);
		} while (stavka > playerScore);

		n1 = rand() % 7 + 1;
		n2 = rand() % 7 + 1;

		printf("Two random number:\n%d %d\n", n1, n2);
		if (n1 + n2 == num)
		{
			printf("Player won!\n");
			playerScore += 3 * stavka;
			computerScore -= 3 * stavka;
		} 
		else if (n1 + n2 <= 7 && num <= 7)
		{
			printf("Player won!\n");
			playerScore += stavka;
			computerScore -= stavka;
		}
		else if (n1 + n2 > 7 && num > 7)
		{
			printf("Player won!\n");
			playerScore += stavka;
			computerScore -= stavka;
		}
		else
		{
			printf("Player lose!\n");
			playerScore -= stavka;
			computerScore += stavka;
		}
		printf("\n");
	}
	if (playerScore <= 0)
		printf("Game over. Computer win this party\n");
	else
		printf("Game over. Player win this party\n");
}