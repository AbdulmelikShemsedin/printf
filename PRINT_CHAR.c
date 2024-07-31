/**
 * print_char - This function Prints a character
 * @types: List a of arguments
 * @buffer: Buffer array to handle print
 * @flags:  Calculates active flags
 * @width: Width
 * @precision: Precision specification
 * @size: Size specifier
 * Return: Number of chars printed
 */
int print_char(va_list types, char buffer[],
	int flags, int width, int precision, int size)
{
	char h = va_arg(types, int);

	return (handle_write_char(h, buffer, flags, width, precision, size));
}

