#include "search_algos.h"
#include <stdio.h>
#include <stdlib.h>

/**
 * advanced_binary - search value in an array with advanced binary search
 * @array: array with values to search
 * @size: size of arrray
 * @value: value to find
 * Return: Always EXIT_SUCCESS
 */
int advanced_binary(int *array, size_t size, int value)
{

	int low = 0, a = 0, high = (int)size - 1, mid = 0;

	if (array == NULL || size <= 0)
		return (-1);
	while (low <= high)
	{
		mid = (((high + low) / 2));
		printf("Searching in array:");
		a = low;
		while (a <= high)
		{
			printf(" %d", array[a]);
			if (a < (high))
				printf(",");
			a = a + 1;
		}
		printf("\n");
		if (array[mid] == value)
		{
			if (array[mid - 1] == value)
				high = mid;
			else
				return (mid);
		}
		else if (array[mid] < value)
			low = mid + 1;
		else
			high = mid - 1;
	}
	return (-1);
}
