/*
 * Created by Liu Papillon, on Sep 6, 2017.
 */



#include <osa.h>


int main(int argc, char *argv[])
{
    printf("Hello world!\n");

    OSA_info("Hello.\n");

    OSA_info("OSA_roundUp(99, 16) = %d\n", OSA_roundUp(99, 16));

    return 0;
}


