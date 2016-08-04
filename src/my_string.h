#ifndef _MY_STRING_LIB_
#define _MY_STRING_LIB_

#include <stdlib.h>

int strlen (char *str);
char *strcp_indx (char *str, int start, int stop);
char *strcp (char* start, char* stop);
int str_find_begin (char *str, char *target);
char *str_find (char *str, char *target);
int str_find_indx (char *str, char *target);
char *str_find_next (char *str, char *target, unsigned int next);
char *str_split (char *str, const char *delim);
