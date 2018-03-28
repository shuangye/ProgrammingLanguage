/*
 * Created by Liu Papillon, on Sep 6, 2017.
 */

#include <stdlib.h>
#include <errno.h>
#include <stdio.h>
#include <stdarg.h>
#include <string.h>
#include <osa/osa.h>


typedef enum {
    OSA_LOG_TYPE_DEBUG                    = 0,
    OSA_LOG_TYPE_INFO                     = 1,
    OSA_LOG_TYPE_WARN                     = 2,
    OSA_LOG_TYPE_ERROR                    = 3,
    OSA_LOG_TYPE_COUNT                    = 4,
} OSA_LogType;

typedef struct OSA_LogObject {
    OSA_LogOptions            options;    
    Bool                      openedStream;            /*  is stream opened by this module? */
} OSA_LogObject;



int OSA_logInit(const OSA_LogOptions *pOptions, OSA_LogHandle *pHandle)
{
    int                  ret;
    OSA_LogObject       *pObj = NULL;

    if (NULL == pOptions || NULL == pHandle) {
        OSA_error("Invalid parameter.\n");
        return OSA_STATUS_EINVAL;
    }

    if (NULL == pOptions->pStream && OSA_strIsEmptyOrWhitespace(pOptions->filePath)) {
        OSA_error("Either a stream (%p) or file path (%s) should be provided.\n", pOptions->pStream, pOptions->filePath);
        return OSA_STATUS_EINVAL;
    }

    pObj = calloc(1, sizeof(*pObj));
    if (NULL == pObj) {
        return OSA_STATUS_ENOMEM;
    }

    pObj->options = *pOptions;

    if (NULL == pObj->options.pStream) {
        pObj->options.pStream = fopen(pObj->options.filePath, "a+");
        if (NULL == pObj->options.pStream) {
            ret = errno;
            OSA_error("Opening log file %s failed: %d %s\n", pObj->options.filePath, errno, strerror(errno));
            goto _failure;
        }
        pObj->openedStream = OSA_True;
    }

    *pHandle = pObj;
    OSA_info("Inited OSA log module.\n");
    return OSA_STATUS_OK;

_failure:
    if (NULL != pObj) {
        if (pObj->openedStream) {
            fclose(pObj->options.pStream);
        }
        free(pObj);
    }
    return ret;
}


int OSA_logDeinit(OSA_LogHandle handle)
{
    OSA_LogObject       *pObj;

    pObj = (OSA_LogObject *)handle;
    if (NULL != pObj) {
        if (pObj->openedStream) {
            fclose(pObj->options.pStream);
        }
        free(pObj);
    }
    
    OSA_info("Deinited OSA log module.\n");
    return OSA_STATUS_OK;
}


static int OSA_log(OSA_LogHandle handle, Bool verbose, const OSA_LogType type,
                   const Char *pModule, const Char *pFile, const Char *pFunc, const long line, const Char *pFmt, va_list ap)
{
    OSA_LogObject   *pObj;
    Char             timestamp[32];
    const Char      *pStrTypes[] = { "DEBUG", "INFO", "WARN", "ERROR" };
        

    pObj = (OSA_LogObject *)handle;
    if (NULL == pObj) {
        return OSA_STATUS_EINVAL;
    }

    OSA_datetimeGetCurrent(OSA_DATETIME_FORMAT_ISO8601, timestamp, sizeof(timestamp));

    /* output prefix */
    fprintf(pObj->options.pStream, "[%s] [%s] [%s] ", timestamp, pStrTypes[type], pModule);
    if (verbose) {
        fprintf(pObj->options.pStream, "[%s] [%s()] [#%ld]: ", pFile, pFunc, line);
    }

    vfprintf(pObj->options.pStream, pFmt, ap);
    return OSA_STATUS_OK;
}


void OSA__logd(OSA_LogHandle handle, const Char *pModule, const Char *pFile, const Char *pFunc, const long line, const Char *fmt, ...)
{
    va_list args;
    va_start(args, fmt);
    OSA_log(handle, OSA_True, OSA_LOG_TYPE_DEBUG, pModule, pFile, pFunc, line, fmt, args);
    va_end(args);
}


void OSA__logi(OSA_LogHandle handle, const Char *pModule, const Char *pFile, const Char *pFunc, const long line, const Char *fmt, ...)
{
    va_list args;
    va_start(args, fmt);
    OSA_log(handle, OSA_False, OSA_LOG_TYPE_INFO, pModule, pFile, pFunc, line, fmt, args);
    va_end(args);
}


void OSA__logw(OSA_LogHandle handle, const Char *pModule, const Char *pFile, const Char *pFunc, const long line, const Char *fmt, ...)
{
    va_list args;
    va_start(args, fmt);
    OSA_log(handle, OSA_False, OSA_LOG_TYPE_WARN, pModule, pFile, pFunc, line, fmt, args);
    va_end(args);
}


void OSA__loge(OSA_LogHandle handle, const Char *pModule, const Char *pFile, const Char *pFunc, const long line, const Char *fmt, ...)
{
    va_list args;
    va_start(args, fmt);
    OSA_log(handle, OSA_False, OSA_LOG_TYPE_ERROR, pModule, pFile, pFunc, line, fmt, args);
    va_end(args);
}


