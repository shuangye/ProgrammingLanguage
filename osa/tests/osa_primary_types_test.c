#include <assert.h>
#include <osa_primary_types.h>


int OSA_testPrimaryTypesSizes(void)
{
    assert(1 == sizeof(Byte));
    assert(1 == sizeof(Uint8));
    assert(1 == sizeof(Int8));
    assert(2 == sizeof(Uint16));
    assert(2 == sizeof(Int16));
    assert(4 == sizeof(Uint32));
    assert(4 == sizeof(Int32));
    assert(8 == sizeof(Uint64));
    assert(8 == sizeof(Int64));
    assert(4 == sizeof(Float32));
    assert(8 == sizeof(Float64));
}



