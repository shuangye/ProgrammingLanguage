#include <stdio.h>
#include <osa.h>


int OSA_log_tests()
{
    int ret;
    OSA_LogOptions options;
    OSA_LogHandle handle;

    OSA_clear(&options);
    #if 0
    snprintf(options.filePath, sizeof(options.filePath), "osa.log");
    #else
    options.pStream = stdout;
    #endif
    ret = OSA_logInit(&options, &handle);
    if (OSA_isFailed(ret)) {
        return ret;
    }
    
    OSA_logd(handle, "This is a debug line by %s.\n", "Papillon");
    OSA_logi(handle, "This is an info line by %s.\n", "Papillon");
    OSA_logw(handle, "This is a warning line by %s.\n", "Papillon");
    OSA_loge(handle, "This is an error line by %s.\n", "Papillon");

    OSA_logDeinit(handle);
    return OSA_STATUS_OK;
}

