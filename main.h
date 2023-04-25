#ifndef MAIN_H
#define MAIN_H

#include <stdarg.h>
#include <stdio.h>
#include <unistd.h>
#include <string.h>
#include <stdlib.h>
#include <limits.h>


#define UNUSED(x) (void)(x)
#define BUFF_SIZE 1024

/* FLAGS */
#define F_MINUS 1
#define F_PLUS 2
#define F_ZERO 4
#define F_HASH 8
#define F_SPACE 16

/* SIZES */
#define S_LONG 2
#define S_SHORT 1

/**
 * struct fmt - Struct op
 *
 * @fmt: The format.
 * @fn: The function associated.
 */
struct fmt
{
	char fmt;
	int (*fn)(va_list, char[], int, int, int, int);
};

/**
 * typedef struct fmt fmt_t - Struct op
 *
 * @fmt: The format.
 * @fm_t: The function associated.
 */
typedef struct fmt fmt_t;

int _printf(const char *format, ...);
int _print_flag_handlers(const char *fmt, int *i, va_list valist,
char buf[], int f, int w, int p, int s);

/****************** FUNCTIONS ******************/

/* Funtions to print chars and strings */
int _char_flag(va_list valist, char buf[], int f, int w, int p, int s);
int _print_str_flag(va_list valist, char buf[], int f, int w, int p, int s);
int _print_percent_flag(va_list valist, char buf[], int f,
int w, int p, int s);

/* Functions to print numbers */
int _print_integer_flag(va_list valist, char buf[],
int f, int w, int p, int s);
int _binary_flag(va_list valist, char buf[], int f,
int w, int p, int s);
int _print_unsigned_flag(va_list valist, char buf[],
int f, int w, int p, int s);
int _print_octal_flag(va_list valist, char buf[],
int f, int w, int p, int s);
int _print_hex_lower(va_list valist, char buf[], int f,
int w, int p, int s);
int _print_hex_upper(va_list valist, char buf[], int f,
int w, int p, int s);

int _print_hex_num(va_list valist, char map_to[], char buf[],
int f, char f_ch, int w, int p, int s);

/* Function to print non printable characters */
int _check_no_print(va_list valist, char buf[], int f, int w, int p, int s);

/* Funcion to print memory address */
int _print_pointer_flag(va_list valist, char buf[],
int f, int w, int p, int s);

/* Funciotns to handle other specifiers */
int _retrieve_flag(const char *format, int *i);
int _check_width_flag(const char *format, int *i, va_list valist);
int _check_precision_flag(const char *format, int *i, va_list valist);
int _check_size_flag(const char *format, int *i);

/*Function to print string in reverse*/
int _print_reverse_flag(va_list valist, char buf[],
int f, int w, int p, int s);

/*Function to print a string in rot 13*/
int _print_rot(va_list valist, char buf[], int f, int w, int p, int s);

/* width handler */
int _char_print_handler(char c, char buf[], int f, int w, int p, int s);

int _print_number(int is_positive, int ind, char buf[], int f,
int w, int p, int s);

int _print_num_flag(int ind, char bff[], int f, int w, int p,
int len, char padd, char extra_c);

int _print_pointer(char buf[], int ind, int len, int w, int f,
char padd, char extra_c, int padd_start);

int _print_unsignd(int is_negative, int ind, char buf[],
int f, int w, int p, int s);

/****************** UTILS ******************/
int _check_can_print(char);
int _join_hex(char, char[], int);
int _check_is_digit(char);

long int _number_size_converter(long int num, int s);
long int _unsigned_size_converter(unsigned long int num, int s);

#endif /* MAIN_H */

