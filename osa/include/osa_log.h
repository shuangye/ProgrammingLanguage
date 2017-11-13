#ifndef __OSA_LOG_H__
#define __OSA_LOG_H__


/*
 * Created by Liu Papillon, on Sep 6, 2017.
 */


#include <stdio.h>
#ifdef OSA_OS_GNU_LINUX
#include <linux/limits.h>
#define OSA_LOG_FILE_PATH_MAX_LEN        PATH_MAX
#else
#define OSA_LOG_FILE_PATH_MAX_LEN        1024
#endif


#ifdef __cplusplus
extern "C" {
#endif // __cplusplus

#if defined(__ANDROID__)
#include <android/log.h>  /* Android log lib must be linked (-llog) */

    #ifdef DEBUG
    #define OSA_debug(fmt, args...)                                                             \
        do {                                                                                    \
            __android_log_print(ANDROID_LOG_DEBUG, OSA_MODULE_NAME, "%s #%d - " fmt,            \
                __FILE__, __LINE__, ##args);                                                    \
        } while (0)
    #else  /* DEBUG */
    #define OSA_debug(fmt, args...)
    #endif

    #define OSA_info(fmt, args...)                                                             \
        do {                                                                                   \
            __android_log_print(ANDROID_LOG_INFO, OSA_MODULE_NAME, "%s #%d - " fmt,            \
                __FILE__, __LINE__, ##args);                                                   \
        } while (0)

    #define OSA_warn(fmt, args...)                                                             \
        do {                                                                                   \
            __android_log_print(ANDROID_LOG_WARN, OSA_MODULE_NAME, "%s #%d - " fmt,            \
                __FILE__, __LINE__, ##args);                                                   \
        } while (0)

    #define OSA_error(fmt, args...)                                                             \
        do {                                                                                    \
            __android_log_print(ANDROID_LOG_ERROR, OSA_MODULE_NAME, "%s #%d - " fmt,            \
                __FILE__, __LINE__, ##args);                                                    \
        } while (0)

#elif defined(_MSC_VER)  /* Microsoft Visual C++ */

    #ifdef DEBUG
    #define OSA_debug(fmt, ...)                                                                 \
        do {                                                                                    \
            fprintf(stdout, "[DEBUG] [%s] " "%s #%d - " fmt,                                    \
                OSA_MODULE_NAME, __FILE__, __LINE__, __VA_ARGS__);                              \
        } while (0)
    #else  /* DEBUG */
    #define OSA_debug(fmt, ...)
    #endif

    #define OSA_info(fmt, ...)                                                                  \
        do {                                                                                    \
            fprintf(stdout, "[INFO] [%s] " "%s #%d - " fmt,                                     \
                OSA_MODULE_NAME, __FILE__, __LINE__, __VA_ARGS__);                              \
        } while (0)

    #define OSA_warn(fmt, ...)                                                                  \
        do {                                                                                    \
            fprintf(stdout, "[WARN] [%s] " "%s #%d - " fmt,                                     \
                OSA_MODULE_NAME, __FILE__, __LINE__, __VA_ARGS__);                              \
        } while (0)

	#define OSA_error(fmt, ...)                                                                 \
        do {                                                                                    \
            fprintf(stderr, "[ERROR] [%s] " "%s #%d - " fmt,                                    \
                OSA_MODULE_NAME, __FILE__, __LINE__, __VA_ARGS__);                              \
        } while (0)

#else  /* GCC */
	#ifdef DEBUG
    #define OSA_debug(fmt, args ...)                                                            \
        do {                                                                                    \
            fprintf(stdout, "[DEBUG] [%s] " "%s #%d - " fmt,                                    \
                OSA_MODULE_NAME, __FILE__, __LINE__, ##args);                                   \
        } while (0)
	#else
	#define OSA_debug(fmt, args...)
	#endif

	#define OSA_info(fmt, args ...)                                                             \
        do {                                                                                    \
            fprintf(stderr, "[INFO] [%s] " "%s #%d - " fmt,                                     \
                OSA_MODULE_NAME, __FILE__, __LINE__, ##args);                                   \
        } while (0)                                                                             
                                                                                                
	#define OSA_warn(fmt, args ...)                                                             \
        do {                                                                                    \
            fprintf(stderr, "[WARN] [%s] " "%s #%d - " fmt,                                     \
                OSA_MODULE_NAME, __FILE__, __LINE__, ##args);                                   \
        } while (0)

	#define OSA_error(fmt, args ...)                                                            \
        do {                                                                                    \
            fprintf(stderr, "[ERROR] [%s] " "%s #%d - " fmt,                                    \
                OSA_MODULE_NAME, __FILE__, __LINE__, ##args);                                   \
        } while (0)

#endif  /* __ANDROID__ */


typedef void*          OSA_LogHandle;

/* if both file path and stream exist, the latter is preferred */
typedef struct OSA_LogOptions {
    Char                filePath[OSA_LOG_FILE_PATH_MAX_LEN];
    FILE               *pStream;
} OSA_LogOptions;

int OSA_logInit(const OSA_LogOptions *pOptions, OSA_LogHandle *pHandle);

int OSA_logDeinit(OSA_LogHandle handle);

void OSA__logd(OSA_LogHandle handle, const Char *pModule, const Char *pFile, const Char *pFunc, const long line, const Char *fmt, ...);

void OSA__logi(OSA_LogHandle handle, const Char *pModule, const Char *pFile, const Char *pFunc, const long line, const Char *fmt, ...);

void OSA__logw(OSA_LogHandle handle, const Char *pModule, const Char *pFile, const Char *pFunc, const long line, const Char *fmt, ...);

void OSA__loge(OSA_LogHandle handle, const Char *pModule, const Char *pFile, const Char *pFunc, const long line, const Char *fmt, ...);


#if defined(_MSC_VER)  /* Microsoft Visual C++ */

#ifdef DEBUG
    #define OSA_logd(handle, fmt, ...)                                                           \
        do {                                                                                     \
            OSA__logd(handle, OSA_MODULE_NAME, __FILE__, __func__, __LINE__, fmt, __VA_ARGS__);  \
        } while (0)
#else
	#define OSA_logd(handle, fmt, ...)
#endif

#define OSA_logi(handle, fmt, ...)                                                           \
    do {                                                                                     \
        OSA__logi(handle, OSA_MODULE_NAME, __FILE__, __func__, __LINE__, fmt, __VA_ARGS__);  \
    } while (0)

#define OSA_logw(handle, fmt, ...)                                                           \
    do {                                                                                     \
        OSA__logw(handle, OSA_MODULE_NAME, __FILE__, __func__, __LINE__, fmt, __VA_ARGS__);  \
    } while (0)

#define OSA_loge(handle, fmt, ...)                                                           \
    do {                                                                                     \
        OSA__loge(handle, OSA_MODULE_NAME, __FILE__, __func__, __LINE__, fmt, __VA_ARGS__);  \
    } while (0)

#else

#ifdef DEBUG
    #define OSA_logd(handle, fmt, args ...)                                                     \
        do {                                                                                    \
            OSA__logd(handle, OSA_MODULE_NAME, __FILE__, __func__, __LINE__, fmt, ##args);      \
        } while (0)
#else
	#define OSA_logd(handle, fmt, args...)
#endif

#define OSA_logi(handle, fmt, args ...)                                                         \
    do {                                                                                        \
        OSA__logi(handle, OSA_MODULE_NAME, __FILE__, __func__, __LINE__, fmt, ##args);          \
    } while (0)

#define OSA_logw(handle, fmt, args ...)                                                         \
    do {                                                                                        \
        OSA__logw(handle, OSA_MODULE_NAME, __FILE__, __func__, __LINE__, fmt, ##args);          \
    } while (0)

#define OSA_loge(handle, fmt, args ...)                                                         \
    do {                                                                                        \
        OSA__loge(handle, OSA_MODULE_NAME, __FILE__, __func__, __LINE__, fmt, ##args);          \
    } while (0)

#endif    /* if defined(_MSC_VER) */

#ifdef __cplusplus
    }
#endif // __cplusplus

#endif  /* __OSA_MACROS_H__ */


