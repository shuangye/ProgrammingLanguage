#include <time.h>
#include <osa/osa_datetime.h>


#ifndef OSA_OS_WINDOWS

Char * OSA_datetimeConvert(Char *pDatetime, size_t length, const Char *pSrcFormat, const Char *pDstFormat)
{
    struct tm timeInfo;
    strptime(pDatetime, pSrcFormat, &timeInfo);
    strftime(pDatetime, length, pDstFormat, &timeInfo);
    return pDatetime;
}

#endif


Char * OSA_datetimeGetCurrent(const Char *pFormat, Char *pBuffer, size_t length)
{
    time_t t = time(NULL);
    struct tm *pTimeInfo = localtime(&t);
    strftime(pBuffer, length, pFormat, pTimeInfo);
    return pBuffer;
}



