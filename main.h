#ifndef MAIN_H
#define MAIN_H

#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <stdarg.h>
#include <string.h>
#include <limits.h>

/* ---------- MACROS ---------- */
#define BUF_LENGTH 1024

/* ---------- PROTOTYPE FOR BINARY ---------- */
int _binary_conversion(char *str);
char *_create_binary(char *str, va_list valist);

/* ---------- PROTOTYPE FOR BUFFER ---------- */
char *_buffer_flush(char *buffer);
char *_buff_fill(char *buffer, const char *s, int count_c, int s_length);
void _write_buffer(char *buffer, int len);

/* ---------- PROTOTYPE FOR CHAR ---------- */
char *_create_char(char *str, va_list valist);
int _convert_char(char *str);

/* ---------- PROTOTYPE FOR DECIMAL ----------*/
char *_create_decimal(char *str, va_list valist);
int _convert_di(char *str);
char *_aoti(int num);

/* ---------- PROTOTYPE FOR FORMAT HANDLER ---------- */
char *_get_format(const char *fmt);
void _format_filler(const char *fmt);

/* ---------- PROTOTYPE FOR GET_VALID_FUN && GET_CHE_STR_FUNC ---------- */
int (*get_valid_func(char c))(char *);
char *(*get_che_str_func(char c))(char *, va_list);

/* ---------- PROTOTYPE FOR UPPERCASE HEX ---------- */
char *_create_hex_upper(char *str, va_list valist);
char *_hex_upper(unsigned int n);

/*help-handlers1.c__ handles conversion, checks for digit, checks for strlen,copy*/
int convert_c(char c);
int _is_digit(char c);
int _strlen(const char *s);
char *_strncpy(char *dest, const char *src, int n);
int _isdflag(char *c);



/*help-handlers.c__ pres check, width check and returns result*/
int format_precision(char *s, char format);
int width_handler(char *s, char format);
*ptr_result(char *arr, char *s, int pres, int width, int slen, int flen, int mlen);

/*unsigned-int.c__ Unsigned int conversion and making of str*/
int convert_s(char *s);
char *num_tostr(unsigned int n);
char *make_unsigned(char *s, va_list l);

/*str-make.c__creates formatted str,checks format if its right*/
char *str_make(char *s, va_list vl);
int convert_str(char *s);

/*octadeci.c__checks for octa,converts to octa*/
int octa_check(char *s);
char *convert_2octa(unsigned int n,int b);
char *make_octal(char *s, va_list l);

/*our_printf.c__error check,a copy of printf funct*/
void error_f(const char *format);
int _printf(const char *format, ...);


/*hexa.c__checks, converts to hex, print rev numb*/

int conversion_h(char *s);
char *hex(unsigned int n);
char *make_hex(char *s, va_list l);
void reverse_array(char *a, int n);




/*structs*/
/**
 * struct valid - Checks for formatting Valiity
 * @type: Type
 * @conver_check: Funct to check for str conversion validity
 */
typedef struct valid
{
	char type;
	int (*conver_check)(char *);
} valid;

/**
 * struct che_str - Checks for validity
 * @type: Checks for type of ent
 * @make_s: Dev the str
 */
typedef struct che_str
{
	char type;
	char *(*make_s)(char *, va_list);
} che_str;


#endif /* MAIN_H */
