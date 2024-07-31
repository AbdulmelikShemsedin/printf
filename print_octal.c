#include "main.h"

/**
 * print_octal - function to convert a num to octal str
 * @num: number
 * Return: count
 */
int print_octal(unsigned int num)
{
char buf[12];
int i = 10;
int count = 0;

buf[11] = '\0';

if (num == 0)
{
buf[i--] = '0';
}
else
{
while (num != 0 && i >= 0)
{
buf[i--] = '0' + (num % 8);
num /= 8;
}
}

count += write(1, buf + i + 1, 10 - i);
return (count);
}
