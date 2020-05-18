#include <stdlib.h>
#include <stdio.h>
#include "sandpiles.h"

/**
 * print_grid - this function returns a pile with values lower than 3
 * @grid: first matrix
 * Return: do not return anything
 */
static void print_grid(int grid[3][3])
{
	int i, j;

	for (i = 0; i < 3; i++)
	{
		for (j = 0; j < 3; j++)
		{
			if (j)
				printf(" ");
			printf("%d", grid[i][j]);
		}
		printf("\n");
	}
}

/**
 * sandpiles_sum - this function returns a pile with values lower than 3
 * @grid1: first matrix
 * @grid2: Second matrix
 * Return: do not return anything
 */
void sandpiles_sum(int grid1[3][3], int grid2[3][3])
{
	int i = 0, j = 0, stable = 0, count = 0, flag = 0;

	while (count == 0)
	{
		if (flag != 0)
		{
			stable = sandpiles_stable(grid1, grid2);
			if (stable == 9)
				break;
			printf("=\n");
			print_grid(grid1);
		}
		for (i = 0; i < 3; i++)
		{
			for (j = 0; j < 3; j++)
			{
				if (flag != 0)
				{
					if (grid2[i][j] > 3)
						sandpile_spread(grid1, i, j);
				}
				else
					grid1[i][j] = grid1[i][j] + grid2[i][j];
			}
		}
		flag = 1;
	}
}

/**
 * sandpiles_stable - this function print and check stable sandpiles
 * @grid1: first matrix
 * @grid2: Second matrix
 * Return: stable data
 */
int sandpiles_stable(int grid1[3][3], int grid2[3][3])
{
	int stable = 0, i = 0, j = 0;

	for (i = 0; i < 3; i++)
	{
		for (j = 0; j < 3; j++)
		{
			grid2[i][j] = grid1[i][j];
			if (grid1[i][j] <= 3)
				stable++;
		}
	}
	return (stable);
}

/**
 * sandpile_spread - this function sparese the values
 * @grid1: first matrix
 * @i: row position
 * @j: column position
 * Return: do not return anything
 */
void sandpile_spread(int grid1[3][3], int i, int j)
{
	grid1[i][j] = grid1[i][j] - 4;
	if (j > 0)
		grid1[i][j - 1] = (grid1[i][j - 1]) + 1;
	if (i > 0)
		grid1[i - 1][j] = (grid1[i - 1][j]) + 1;
	if (i < 2)
		grid1[i + 1][j] = (grid1[i + 1][j]) + 1;
	if (j < 2)
		grid1[i][j + 1] = (grid1[i][j + 1]) + 1;
}
