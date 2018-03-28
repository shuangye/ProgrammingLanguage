#pragma once
#ifndef __OSA_DEFINITIONS_H__
#define __OSA_DEFINITIONS_H__


/*
 * Created by Liu Papillon, on Nov 27, 2017.
 */


#ifdef OSA_OS_WINDOWS
#ifdef OSA_EXPORTS
#define OSA_API __declspec(dllexport)   
#else  
#define OSA_API __declspec(dllimport)   
#endif 
#else  /* OSA_OS_WINDOWS */
#define OSA_API
#endif  /* OSA_OS_WINDOWS */



#ifdef __cplusplus
extern "C" {
#endif // __cplusplus



#ifdef __cplusplus
}
#endif // __cplusplus


#endif  /* __OSA_DEFINITIONS_H__ */

