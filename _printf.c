#include "main.h"

/**
 * _printf - function like printf()
 * @format: to be printed
 * Return: count
 */
int _printf(const char *format, ...)
{
va_list args;
int count = 0;
const char *ptr;

va_start(args, format);

for (ptr = format; *ptr != '\0'; ptr++)
{
if (*ptr == '%')
{
ptr++;
switch (*ptr)
{
case 'c':
{
char c = va_arg(args, int);
write(1, &c, 1);
count++;
break;
}
case 's':
{
char *str = va_arg(args, char *);
while (*str)
{
write(1, str++, 1);
count++;
}
break;
}
case '%':
{
write(1, "%", 1);
count++;
break;
}
case 'd':
case 'i':
{
int num = va_arg(args, int);
char buf[32];
int len = snprintf(buf, sizeof(buf), "%d", num);
write(1, buf, len);
count += len;
break;
}
case 'p':
{
void *addr = va_arg(args, void *);
count += write(1, "0x", 2);  /* print "0x" prefix */
count += print_hex((uintptr_t)addr, 0);  /* print address */
break;
}
case 'u':
{
unsigned int num = va_arg(args, unsigned int);
count += print_unsigned(num);
break;
}
case 'o':
{
unsigned int num = va_arg(args, unsigned int);
count += print_octal(num);
break;
}
case 'x':
{
unsigned int num = va_arg(args, unsigned int);
count += print_hex(num, 0);
break;
}
case 'X':
{
unsigned int num = va_arg(args, unsigned int);
count += print_hex(num, 1);
break;
}
default:
break;
}
}
else
{
write(1, ptr, 1);
count++;
}
}

va_end(args);
return (count);
}
