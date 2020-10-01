#include <stdlib.h>
#include <stdio.h>
/**
 * main - check the code for Holberton School students.
 * @argc: input the number or arguments in commandline
 * @argv: input the array of arguments in commandline
 * Return: Always 0.
 */

int main(int argc, char *argv[])
{
if (argc == 3)
{
printf("%ld\n", (atoi(argv[1]) * atoi(argv[2])));
}
else
{
printf("Error\n");
exit(98);
}
return (0);
}
