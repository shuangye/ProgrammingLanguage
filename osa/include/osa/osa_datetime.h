#pragma once
#ifndef __OSA_DATETIME_H__
#define __OSA_DATETIME_H__

#include "osa_primary_types.h"
#include "osa_definitions.h"
#include "osa_platforms.h"

#define OSA_DATE_FORMAT_COMPACT          "%Y%m%d"
#define OSA_DATE_FORMAT_ISO8601          "%Y-%m-%d"
#define OSA_DATETIME_FORMAT_COMPACT      "%Y%m%d%H%M%S"
#define OSA_DATETIME_FORMAT_ISO8601      "%Y-%m-%d %H:%M:%S"


#ifdef __cplusplus
extern "C" {
#endif // __cplusplus


#ifndef OSA_OS_WINDOWS

Char * OSA_datetimeConvert(Char *pDatetime, size_t length, const Char *pSrcFormat, const Char *pDstFormat);

#endif

OSA_API Char * OSA_datetimeGetCurrent(const Char *pFormat, Char *pBuffer, size_t length);


#ifdef __cplusplus
}
#endif // __cplusplus

#endif  /* __OSA_DATETIME_H__ */

