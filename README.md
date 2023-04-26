PRINTF PROJECT

This is a copy of the printf funtion C programming language, it has the complete
functionalities of the printf function C, In our project, we created different
files/fuctions to aid the perfect functioning of our_printf program.
Below are some of the list of programs created and the actual functionalities.

0. Write a function that produces output according to a format.

Prototype: int _printf(const char *format, ...);
Returns: the number of characters printed (excluding the null byte used to end output to strings)
write output to stdout, the standard output stream
format is a character string. The format string is composed of zero or more directives. See man 3 printf for more detail. You need to handle the following conversion specifiers:
c
s
%
You don’t have to reproduce the buffer handling of the C library printf function
You don’t have to handle the flag characters
You don’t have to handle field width
You don’t have to handle precision
You don’t have to handle the length modifiers


1. A function that handles the following conversion specifiers:

d
i
You don’t have to handle the flag characters
You don’t have to handle field width
You don’t have to handle precision
You don’t have to handle the length modifiers

2. A function that handles the following custom conversion specifiers:

b: the unsigned int argument is converted to binary

3. A function that handles the following conversion specifiers:

u
o
x
X
You don’t have to handle the flag characters
You don’t have to handle field width
You don’t have to handle precision
You don’t have to handle the length modifiers

4. A function that uses a local buffer of 1024 chars in order to call write as little as possible.


5. A function that handles the following custom conversion specifier:

S : prints the string.
Non printable characters (0 < ASCII value < 32 or >= 127) are printed this way: \x, followed by the ASCII code value in hexadecimal (upper case - always 2 characters)


6. A function that handles the following conversion specifier: p.

You don’t have to handle the flag characters
You don’t have to handle field width
You don’t have to handle precision
You don’t have to handle the length modifiers


7. A function that handles the following flag characters for non-custom conversion specifiers:

+
space
#

8. A functon that handles  the following length modifiers for non-custom conversion specifiers:

l
h
Conversion specifiers to handle: d, i, u, o, x, X

9. A function that handlesthe field width for non-custom conversion specifiers.

10. A program that handles the precision for non-custom conversion specifiers

11. A program that handles the 0 flag character for non-custom conversion specifiers.

12. A program that handles the - flag character for non-custom conversion specifiers.

13. A program that handles the following custom conversion specifier:

r : prints the reversed string

14. A function that handles the following custom conversion specifier:

R: prints the rot13'ed string

15. All the functions above working togerher just like the printf function in C programming.


created by 

AHMED AZEEZ
GODSPOWER MUKORO
