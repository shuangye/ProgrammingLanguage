/*
 * Created by Liu Papillon, on Sep 6, 2017.
 */



#include <osa/osa.h>
#include "osa_tests.h"


int main(int argc, char *argv[])
{
    printf("Hello OSA!\n");

    #if 0
    
    OSA_info("Hello.\n");

    OSA_info("OSA_roundUp(99, 16) = %d\n", OSA_roundUp(99, 16));

    OSA_string_tests();

    OSA_datetime_tests();

    #endif

    OSA_log_tests();

    return 0;
}


