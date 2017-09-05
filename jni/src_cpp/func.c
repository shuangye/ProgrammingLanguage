#include <stdio.h>
#include "func.h"

int FUNC_test(void)
{
    printf("from %s %s\n", __FILE__, __func__);
    return 0;
}



