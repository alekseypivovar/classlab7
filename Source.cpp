/* 
zadchka o cherepaske

dvumerniy massiv sluchainih chisel. 
nado prointi v protivopolozhniy ugol sobrav naibolshuyu summu chisel.
12 34 4  16 M
61 8  15 31
9  3  41 14
10 83 45 8
N

nado zapilit' vtoruyu matricu s summami cgisel po puti, skladivaya vibiraem maksimalnie chisla.
Potom soedinyaem maksimumi i poluchaem marsrut.
uot i vse.
*/

#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#define M 10
#define N 10

int main()
{

	int arr[N][M]; //ishodniy massiv
	int sum[N][M] = { 0 }; // massiv summ
	
	srand(time(NULL));

	//zaponyaem massiv
	for (int i = 0; i < M; i++)
	{
		for (int j = 0; j < N; j++)
			arr[j][i] = rand() % (100);
	}

	printf("Start table:\n");
	for (int i = 0; i < M; i++)
	{
		for (int j = 0; j < N; j++)
		{
			printf("%d\t", arr[j][i]);
			if (j == 9)
				putchar('\n');
		}
	}

	// zapolnyaem massiv summ
	sum[0][0] = arr[0][0];
	// stolbec
	for (int i = 1; i < M; i++)
		sum[0][i] = arr[0][i] + sum[0][i - 1];
	// stroka
	for (int j = 1; j < N; j++)
		sum[j][0] = arr[j][0] + sum[j-1][0];
	// nachinka
	for (int i = 1; i < M; i++)
	{
		for (int j = 1; j < N; j++)
		{
			if (sum[j - 1][i]>sum[j][i - 1])
				sum[j][i] = arr[j][i] + sum[j - 1][i];
			else sum[j][i] = arr[j][i] + sum[j][i-1];
		}
	}



	//vivod na pechat massiva summ
	printf("\nSummary table:\n");
	for (int i = 0; i < M; i++)
	{
		for (int j = 0; j < N; j++)
		{
			printf("%d\t", sum[j][i]);
			if (j == 9)
				putchar('\n');
		}
	}

	//vivod na pechar massiva s marshrutom
	printf("\nTurtle way:\n");
	int i = 0, j = 0;
	while (1)
	{
		arr[j][i] = 999;
		if (j == N && i == M)
			break;
		else if (j == N)
			i++;
		else if (i == M)
			j++;
		else if (sum[j + 1][i] > sum[j][i + 1])
			j++;
		else if (sum[j + 1][i] < sum[j][i + 1])
			i++;
	}

	for (int i = 0; i < M; i++)
	{
		for (int j = 0; j < N; j++)
		{
			printf("%d\t", arr[j][i]);
			if (j == 9)
				putchar('\n');
		}
	}




	putchar('\n');
	return 0;
}