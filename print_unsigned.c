#include "main.h"

/**
 * print_unsigned - convert num to dec str
 * @num: number
 * Return: count
 */
int print_unsigned(unsigned int num)
{
char buf[11];
int i = 9;
int count = 0;

buf[10] = '\0';

if (num == 0)
{
buf[i--] = '0';
}
else
{
while (num != 0 && i >= 0)
{
buf[i--] = '0' + (num % 10);
num /= 10;
}
}

count += write(1, buf + i + 1, 9 - i);
return (count);
}
