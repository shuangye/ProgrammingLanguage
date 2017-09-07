#ifndef __OSA_TYPES_H__
#define __OSA_TYPES_H__


/*
 * Created by Liu Papillon, on Sep 6, 2017.
 */


#include "osa_primary_types.h"


typedef struct Point {
    Int32     x;
    Int32     y;
} OSA_Point;


typedef struct FPoint {
    Float32    x;
    Float32    y;
} OSA_FPoint;


typedef struct Size {
    Int32    w;
    Int32    h;
} OSA_Size;


typedef struct Rect {
    OSA_Point    origin;  /* at user-defined location */
    OSA_Size     size;
} OSA_Rect;


typedef struct Circle {
    OSA_Point    center;
    Uint32       radius;
} OSA_Circle;



#endif  /* __OSA_TYPES_H__ */

