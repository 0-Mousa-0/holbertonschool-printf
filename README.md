_printf - Custom printf Implementation
A custom implementation of the printf function in C, developed as part of the Holberton School curriculum.

Description
This project involves creating our own version of the printf function from the C standard library. The function _printf produces formatted output to the standard output stream (stdout) and returns the number of characters printed (excluding the null byte used to end output to strings).

The implementation handles variadic functions, memory management, and various data type conversions while adhering to strict coding standards and project requirements.

Authors: [Raghad Almalki / Mousa Alqarni]
Supported Conversion Specifiers
Specifier	Description	Example
%c	Prints a single character	_printf("Char: %c", 'A') → Char: A
%s	Prints a string of characters	_printf("String: %s", "hello") → String: hello
%%	Prints a literal percent sign	_printf("Percent: %%") → Percent: %
%d	Prints a signed decimal integer	_printf("Number: %d", -42) → Number: -42
%i	Prints a signed integer	_printf("Number: %i", 42) → Number: 42
Not Yet Implemented
The following features are not implemented in this version:

Flag characters (+, -, #, 0, space)
Field width specification
Precision specification
Length modifiers (h, l, L)
Buffer handling like C library printf
Other conversion specifiers (u, o, x, X, p, f, etc.)
Project Structure
holbertonschool-printf/ --main.h # Header file with function prototypes --_printf.c # Main _printf function implementation --print_functions.c # Helper functions for specifiers --man_3_printf # Manual page --README.md # Project documentation
