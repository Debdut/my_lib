#include "my_string.h"

char *ptr = NULL;
int counter = 0;

int m_strlen (char *str)
/*Returns the length of the char string*/
{
    char* ptr = str;

    while (*ptr++ != '\0')
    {
    }

    return (ptr - str);
}

char *m_strcp_indx (char *str, int start, int stop)
/*Creates and Returns a substring of string using indices in the given string*/
{
    unsigned int diff_indx = stop - start;
    char *ptr = (char *) calloc (1, sizeof (char));
    char *ptr2, *ptr3, *cp_str;

    if (start >= stop)
    {
        return ptr;
    }

    free (ptr);

    diff_indx = stop - start;
    ptr = (char *) calloc (diff_indx, sizeof (char));
    ptr2 = ptr;

    while ((*(ptr2++) != '\0') && (ptr2 - ptr < start))
    {
    }

    ptr3 = ptr2;
    cp_str = ptr;

    while (((*ptr++ = *ptr2++) != '\0') && (ptr2-ptr3 < diff_indx))
    {
    }

    return cp_str;
}

char *m_strcp (char* start, char* stop)
/*Creates and Returns a substring of string*/
{
    char *str = (char *) calloc (1, sizeof (char));
    char *ptr;

    if (start >= stop)
    {
        return str;
    }

    free (str);

    str = (char *) malloc ((stop - start + 1) * sizeof (char));
    ptr = str;

    while (start != stop)
    {
        *ptr++ = *start++;
    }

    *ptr = '\0';
    return str;
}

int m_str_match_begin (char *str, char *target)
/*Boolean function returns 1 target is in begining of str, 0 otherwise*/
{
    while ((*str != '\0') && (*str == *target))
    {
        str++;
        target++;
    }

    return (*target == '\0');
}

char *m_str_find (char *str, char *target)
/*Returns the pointer to begining of target string in str string*/
{
    char *ptr;

    if ((target == NULL) || (*target == '\0'))
    {
        return str;
    }
    else if ((str ==  NULL) || (*str == '\0'))
    {
        return NULL;
    }

    ptr = str;

    while ((*ptr != '\0') && !m_str_find_begin (ptr, target))
    {
        ptr++;
    }

    if (*ptr == '\0')
    {
        return NULL;
    }

    return ptr;
}

int m_str_find_indx (char *str, char *target)
/*Returns the index of begining of target string in str string*/
{
    char *ptr;

    if ((target == NULL) || (*target == '\0'))
    {
        return 0;
    }
    else if ((str ==  NULL) || (*str == '\0'))
    {
        return -1;
    }

    ptr = str;

    while ((*ptr != '\0') && !m_str_find_begin (ptr, target))
    {
        ptr++;
    }

    if (*ptr == '\0')
    {
        return -1;
    }

    return (*ptr - *str);
}

char *m_str_find_next (char *str, char *target, unsigned int next)
/*Find the next'th target in str string*/
{
    if (next == 0)
    {
        return m_str_find (str, target);
    }

    ptr = m_str_find (str, target);

    return m_str_find_next(ptr+1, target, next-1);

}

char *m_str_split (char *str, char *delim)
/*Gets the next token after delimiter if str is NULL, otherwise gets first token in str*/
{
    char *start_ptr, *stop_ptr;

    if ((str == NULL) && (ptr == NULL))
    {
        return NULL;
    }

    if (str != NULL)
    {
        ptr = str;
    }

    if (m_str_find (ptr, delim) == NULL)
    {
        ptr = NULL;
        return NULL;
    }

    start_ptr = m_str_find (ptr, delim);
    start_ptr += m_strlen (delim);
    stop_ptr = m_str_find (start_ptr, delim);
    ptr = stop_ptr;
    return m_strcp(start_ptr, stop_ptr);
}
