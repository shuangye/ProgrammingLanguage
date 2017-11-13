/*
 * Created by Liu Papillon, on Sep 6, 2017.
 */


#include <ctype.h>
#include "osa_string.h"
#include "osa_primary_types.h"


Bool OSA_strIsEmptyOrWhitespace(const Char *pStr)
{
    int i;

    if (OSA_strIsEmpty(pStr)) {
        return OSA_True;
    }

    for (i = 0; '\0' != pStr[i]; ++i) {
        if (!isspace(pStr[i])) {
            return OSA_False;
        }
    }

    return OSA_True;
}


int OSA_strTrim(const Char *src, Char *dest, Uint32 length)
{
    const Char *begin = src;
    const Char *end;
    const Char *p;
    Uint32 i;

    while(isspace(*begin)) ++begin;    /* trim leading space */

    if('\0' == *begin) {
        return 0;    /* all spaces */
    }

    end = begin + strlen(begin) - 1;
    while(end > begin && isspace(*end)) end--;

    for (i = 0, p = begin; i < length - 1 && p <= end; ++i, ++p) {
        dest[i] = *p;
    }

    dest[i] = '\0';    /* write new null terminator */    
    return 0;
}



