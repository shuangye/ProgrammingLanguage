#include <osa.h>




int OSA_datetime_tests()
{
    Char buffer[32];
    OSA_info("Today is %s\n", OSA_datetimeGetCurrent(OSA_DATE_FORMAT_COMPACT, buffer, sizeof(buffer)));
    OSA_info("Current time is %s\n", OSA_datetimeGetCurrent(OSA_DATETIME_FORMAT_ISO8601, buffer, sizeof(buffer)));
    OSA_info("Convert to compact format is %s\n", OSA_datetimeConvert(buffer, sizeof(buffer), 
        OSA_DATETIME_FORMAT_ISO8601, OSA_DATETIME_FORMAT_COMPACT));
    return OSA_STATUS_OK;
}


