#include "main.h"

/**
 * print_hex - function to convert num to hex-decimal string
 * @num: number
 * @is_upper: num check
 * Return: count
 */
int print_hex(int num, int is_upper)
{
char hex_digits[] = "0123456789abcdef";
char hex_digits_upper[] = "0123456789ABCDEF";
char buf[17];
int i = 15;
int count = 0;

buf[16] = '\0';

if (num == 0)
{
buf[i--] = '0';
}
else
{
while (num != 0 && i >= 0)
{
if (is_upper)
{
buf[i--] = hex_digits_upper[num % 16];
}
else
{
buf[i--] = hex_digits[num % 16];
}
num /= 16;
}
}

count += write(1, buf + i + 1, 15 - i);
return (count);
}
