#ifndef __OSA_TYPES_H__
#define __OSA_TYPES_H__


/*
 * Created by Liu Papillon, on Sep 6, 2017.
 */


#include "osa_primary_types.h"


typedef struct OSA_Point {
    Int32     x;
    Int32     y;
} OSA_Point;


typedef struct OSA_FPoint {
    Float32    x;
    Float32    y;
} OSA_FPoint;


typedef struct OSA_Size {
    Int32    w;
    Int32    h;
} OSA_Size;


typedef struct OSA_Rect {
    OSA_Point    origin;  /* at user-defined location */
    OSA_Size     size;
} OSA_Rect;


typedef struct OSA_Circle {
    OSA_Point    center;
    Uint32       radius;
} OSA_Circle;


#define OSA_sizeIsEqual(a, b)     (((a).w == (b).w) && ((a).h == (b).h))


#endif  /* __OSA_TYPES_H__ */

