#ifndef _MY_STRING_LIB_
#define _MY_STRING_LIB_

#include <stdlib.h>

int m_strlen (char *str);
char *m_strcp_indx (char *str, int start, int stop);
char *m_strcp (char* start, char* stop);
int m_str_find_begin (char *str, char *target);
char *m_str_find (char *str, char *target);
int m_str_find_indx (char *str, char *target);
char *m_str_find_next (char *str, char *target, unsigned int next);
char *m_str_split (char *str, char *delim);

#endif
