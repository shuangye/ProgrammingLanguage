#ifndef __OSA_LOG_H__
#define __OSA_LOG_H__


/*
 * Created by Liu Papillon, on Sep 6, 2017.
 */



#include <stdio.h>

#ifdef __ANDROID__
#include <android/log.h>  /* Android log lib must be linked (-llog) */
#endif


#ifdef __ANDROID__

    #ifdef DEBUG
    #define OSA_debug(fmt, args...)                                                             \
        do {                                                                                    \
            __android_log_print(ANDROID_LOG_DEBUG, OSA_MODULE_NAME, "%s #%d %s() - " fmt,       \
                __FILE__, __LINE__, __func__, ##args);                                          \
        } while (0)
    #else  /* DEBUG */
    #define OSA_debug(fmt, args...)
    #endif

    #define OSA_info(fmt, args...)                                                             \
        do {                                                                                    \
            __android_log_print(ANDROID_LOG_INFO, OSA_MODULE_NAME, "%s #%d %s() - " fmt,       \
                __FILE__, __LINE__, __func__, ##args);                                          \
        } while (0)

    #define OSA_warn(fmt, args...)                                                             \
        do {                                                                                    \
            __android_log_print(ANDROID_LOG_WARN, OSA_MODULE_NAME, "%s #%d %s() - " fmt,       \
                __FILE__, __LINE__, __func__, ##args);                                          \
        } while (0)

    #define OSA_error(fmt, args...)                                                             \
        do {                                                                                    \
            __android_log_print(ANDROID_LOG_ERROR, OSA_MODULE_NAME, "%s #%d %s() - " fmt,       \
                __FILE__, __LINE__, __func__, ##args);                                          \
        } while (0)

#else  /* __ANDROID__ */  

    #ifdef DEBUG
    #define OSA_debug(fmt, args ...)                                                            \
        do {                                                                                    \
            fprintf(stdout, "[DEBUG] [%s] " "%s #%d %s() - "fmt,                                \
                OSA_MODULE_NAME, __FILE__, __LINE__, __func__, ##args);                         \
        } while (0)
    #else  /* DEBUG */
    #define OSA_debug(fmt, args...)
    #endif

    #define OSA_info(fmt, args ...)                                                             \
        do {                                                                                    \
            fprintf(stdout, "[INFO] [%s] " "%s #%d %s() - "fmt,                                 \
                OSA_MODULE_NAME, __FILE__, __LINE__, __func__, ##args);                         \
        } while (0)

    #define OSA_warn(fmt, args ...)                                                             \
        do {                                                                                    \
            fprintf(stdout, "[WARN] [%s] " "%s #%d %s() - "fmt,                                 \
                OSA_MODULE_NAME, __FILE__, __LINE__, __func__, ##args);                         \
        } while (0)

    #define OSA_error(fmt, args ...)                                                            \
        do {                                                                                    \
            fprintf(stderr, "[ERROR] [%s] " "%s #%d %s() - "fmt,                                 \
                OSA_MODULE_NAME, __FILE__, __LINE__, __func__, ##args);                         \
        } while (0)

#endif  /* __ANDROID__ */

#endif  /* __OSA_MACROS_H__ */

