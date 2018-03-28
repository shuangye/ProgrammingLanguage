#pragma once
#ifndef __OSA_FS_H__
#define __OSA_FS_H__

#include <limits.h>


#ifdef OSA_OS_WINDOWS
#define OSA_PATH_MAX                               4096
#else
#define OSA_PATH_MAX                               PATH_MAX
#endif // OSA_OS_WINDOWS



#ifdef __cplusplus
extern "C" {
#endif // __cplusplus
    

#ifdef __cplusplus
}
#endif // __cplusplus

#endif  /* __OSA_FS_H__ */

