#include <time.h>
#include "osa_datetime.h"


Char * OSA_datetimeConvert(Char *pDatetime, size_t length, const Char *pSrcFormat, const Char *pDstFormat)
{
    struct tm timeInfo;
    strptime(pDatetime, pSrcFormat, &timeInfo);
    strftime(pDatetime, length, pDstFormat, &timeInfo);
    return pDatetime;
}


Char * OSA_datetimeGetCurrent(const Char *pFormat, Char *pBuffer, size_t length)
{
    time_t t = time(NULL);
    struct tm *pTimeInfo = localtime(&t);
    strftime(pBuffer, length, pFormat, pTimeInfo);
    return pBuffer;
}



