#ifndef __OSA_PRIMARY_TYPES__
#define __OSA_PRIMARY_TYPES__


/*
 * Created by Liu Papillon, on Sep 6, 2017.
 */


#if __i386 | _WIN32 | __arm__
#define OSA_POINTER_SIZE        4
#elif __WIN64 | __x86_64__ | __aarch64__
#define OSA_POINTER_SIZE        8
#else
#error "Cannot detect pointer size"
#endif


typedef void*                   OSA_Handle;

#if (4 == OSA_POINTER_SIZE)

typedef unsigned char           Byte;
typedef unsigned char           Uint8;
typedef char                    Int8;
typedef unsigned short          Uint16;
typedef short                   Int16;
typedef unsigned int            Uint32;
typedef int                     Int32;
typedef unsigned long long      Uint64;
typedef long long               Int64;
typedef float                   Float32;
typedef double                  Float64;


#elif  (8 == OSA_POINTER_SIZE)

typedef unsigned char           Byte;
typedef unsigned char           Uint8;
typedef char                    Int8;
typedef unsigned short          Uint16;
typedef short                   Int16;
typedef unsigned int            Uint32;
typedef int                     Int32;
typedef unsigned long           Uint64;
typedef long                    Int64;
typedef float                   Float32;
typedef double                  Float64;


#endif

#endif  /* __OSA_PRIMARY_TYPES__ */

