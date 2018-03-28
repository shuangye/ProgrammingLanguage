#pragma once
#ifndef __OSA_MISC_H__
#define __OSA_MISC_H__


#if defined(OSA_OS_WINDOWS)
#include <Windows.h>
#define OSA_msleep(ms)                                Sleep((ms))
#elif defined(OSA_OS_ANDROID) || defined(OSA_OS_GNU_LINUX)
#include <unistd.h>
#include <sys/syscall.h>
#define OSA_msleep(ms)                                usleep((ms) * 1000)
#define OSA_getpid()                                  getpid()
#define OSA_gettid()                                  (syscall(__NR_gettid))
#else
#error "OSA_msleep(ms) is not implemented on your platform."
#endif


#ifdef __cplusplus
extern "C" {
#endif // __cplusplus



#ifdef __cplusplus
}
#endif // __cplusplus

#endif  /* __OSA_MISC_H__ */

