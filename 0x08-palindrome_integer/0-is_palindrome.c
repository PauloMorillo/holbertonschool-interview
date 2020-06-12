#include "palindrome.h"
#include <stdio.h>
/**
 * is_palindrome - function if it's palindrome
 * @n: integer to check if its palindrome
 * Return: 1 if n is a palindrome, and 0 otherwise
 */
int is_palindrome(unsigned long n)
{
	int unit = 0;
	unsigned long int dec = 1;
	unsigned long int dec_up = 1;
	unsigned long int revn = 0;
	unsigned long int original = n;

	while (n > dec)
	{
		dec = dec * 10;
	}
	if (dec > 1)
		dec = dec / 10;
	while (dec >= 1)
	{
		unit = n / dec;
		n = n - (unit * dec);
		revn = revn + (unit * dec_up);
		dec_up = dec_up * 10;
		dec = dec / 10;
	}
	return (original == revn);
}
