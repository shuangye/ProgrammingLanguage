/*
  gcc -o libbinding_ctypes.so -fPIC -shared binding_ctypes.c
 */

 #include <stdio.h>

typedef struct DBM_AccessRecord
{
    char                cardno[36];                   /* [00] */
    char                person_uuid[36];              /* [01] */
    char                mac[32];                      /* [02] */
    char                opentype;                     /* [03] */
    char                area_uuid[36];                /* [04] */
    char                slide_date[32];               /* [05] */
    char                cdate[32];                    /* [06] */
    char                dev_uuid[36];                 /* [07] */
    char                area_code[64];                /* [08] */
    char                flag;                         /* [09] */
    char                sync;                         /* [10] */
} DBM_AccessRecord;


DBM_AccessRecord gRecord = { .flag = 1 };

char * DBM_strFunc(char *pInput)
{
    printf("Passed in string %s\n", pInput);
    return "你好";
}
