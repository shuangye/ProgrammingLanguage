#ifndef __OSA_STRING_H__
#define __OSA_STRING_H__


/*
 * Created by Liu Papillon, on Oct 12, 2017.
 */

#include <string.h>



#define OSA_clear(x)                                (memset(&(x), 0, sizeof(x)))
#define OSA_strncpy(dst, src)                       (strncpy(dst, src, sizeof(dst)))


#endif  /* __OSA_STRING_H__ */

