#ifndef HEADER
#define HEADER
#include <stdarg.h>

/*macro definition*/
#define BUF_LENGTH 1024

















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


#endif
