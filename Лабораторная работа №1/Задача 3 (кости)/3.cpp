// Задание 3:
// Составить программу для игры в “кости”.
// Играющий называет любое число в диапазоне от 2 до 12 и ставку, 
// которую он делает в этот ход. Программа с помощью 
// генератора случайных чисел дважды выбирает числа от 1 до 6 
// (“бросает кубик”, на гранях которого цифры от 1 до 6). 
//    Если сумма выпавших очков меньше либо равна 7 и играющий назвал 
// число меньше либо равное 7, он выигрывает ставку.
// 	  Если сумма выпавших цифр больше 7 и играющий сделал ставку 
// на число больше 7, он также выигрывает ставку. 
// 	  Если игрок угадал сумму цифр, он получает в 4 раза больше очков,
// чем сделанная ставка. 
// 	  Ставка проиграна, если ни одна из описанных ситуаций не имеет места.
// В начальный момент у игрока и компьютера по 100 очков.
// Игра идет до тех пор, пока у кого-либо из играющих не останется 0 очков.

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