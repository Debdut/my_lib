#include "my_string.h"

char *ptr = NULL;
int counter = 0;

int strlen (char *str)
/*Returns the length of the char string*/
{
    char* ptr = str;

    while (*ptr++ != '\0')
    {
    }

    return (ptr - str);
}

char *strcp_indx (char *str, int start, int stop)
/*Creates and Returns a substring of string using indices in the given string*/
{
    char *str = (char *) calloc (1, sizeof (char));

    if (start >= stop)
    {
        return str;
    }

    free (str);

    unsigned int diff_indx = stop - start;
    char *str = (char *) calloc (diff_indx, sizeof (char));
    char *ptr = str;

    while ((*(ptr++) != '\0') && (ptr - str < start))
    {
    }

    char *ptr2 = ptr;
    char *cp_str = str;

    while (((*str++ = *ptr++) != '\0') && (ptr-ptr2 < diff_indx))
    {
    }

    return cp_str;
}

char *strcp (char* start, char* stop)
/*Creates and Returns a substring of string*/
{
    char *str = (char *) calloc (1, sizeof (char));

    if (start >= stop)
    {
        return str;
    }

    free (str);

    str = (char *) malloc ((stop - start + 1) * sizeof (char));
    char *ptr = str;

    while (start != stop)
    {
        *ptr++ = *start++;
    }

    *ptr = '\0';
    return str;
}

int str_match_begin (char *str, char *target)
/*Boolean function returns 1 target is in begining of str, 0 otherwise*/
{
    while ((*str != '\0') && (*str == *target))
    {
        str++;
        target++;
    }

    return (*target == '\0');
}

char *str_find (char *str, char *target)
/*Returns the pointer to begining of target string in str string*/
{
    if ((target == NULL) || (*target == '\0'))
    {
        return str;
    }
    else if ((str ==  NULL) || (*str == '\0'))
    {
        return NULL;
    }

    char *ptr = str;

    while ((*ptr != '\0') && !str_find_begin (ptr, target))
    {
        ptr++;
    }

    if (*ptr == '\0')
    {
        return -1;
    }

    return *ptr;
}

int str_find_indx (char *str, char *target)
/*Returns the index of begining of target string in str string*/
{
    if ((target == NULL) || (*target == '\0'))
    {
        return 0;
    }
    else if ((str ==  NULL) || (*str == '\0'))
    {
        return -1;
    }

    char *ptr = str;

    while ((*ptr != '\0') && !str_find_begin (ptr, target))
    {
        ptr++;
    }

    if (*ptr == '\0')
    {
        return -1;
    }

    return (*ptr - *str);
}

char *str_find_next (char *str, char *target, unsigned int next)
/*Find the next'th target in str string*/
{
    if (next == 0)
    {
        return str_find (str, target);
    }

    ptr = str_find (str, target);

    return str_find_next(ptr+1, target, next-1);

}

char *str_split (char *str, const char *delim)
/*Gets the next token after delimiter if str is NULL, otherwise gets first token in str*/
{
    if ((str == NULL) && (ptr == NULL))
    {
        return NULL;
    }

    if (str != NULL)
    {
        ptr = str;
    }

    if (str_find (ptr, delim) == NULL)
    {
        ptr = NULL;
        return NULL;
    }

    char *start_ptr = str_find (ptr, delim);
    start_ptr += len (delim);
    char *stop_ptr = str_find (start_ptr, delim);
    ptr = stop_ptr;
    return strcp(start_ptr, stop_ptr);
}
