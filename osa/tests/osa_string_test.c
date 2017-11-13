#include <osa.h>


int OSA_strTrim_tests(void)
{
    const Char *pSrc;
    Char dest[64];
    
    pSrc = " Hello ";
    OSA_strTrim(pSrc, dest, sizeof(dest));
    OSA_info("`%s` trimmed to `%s`\n", pSrc, dest);

    pSrc = "  Hello";
    OSA_strTrim(pSrc, dest, sizeof(dest));
    OSA_info("`%s` trimmed to `%s`\n", pSrc, dest);

    pSrc = "Hello  ";
    OSA_strTrim(pSrc, dest, sizeof(dest));
    OSA_info("`%s` trimmed to `%s`\n", pSrc, dest);

    pSrc = "  He llo  ";
    OSA_strTrim(pSrc, dest, sizeof(dest));
    OSA_info("`%s` trimmed to `%s`\n", pSrc, dest);

    Char limitedBuffer[4];
    pSrc = "  Hell o  ";
    OSA_strTrim(pSrc, dest, sizeof(limitedBuffer));
    OSA_info("`%s` trimmed to `%s` with buffer of size %lu\n", pSrc, dest, sizeof(limitedBuffer));

    return OSA_STATUS_OK;
}


int OSA_string_tests(void)
{
    OSA_strTrim_tests();
    return OSA_STATUS_OK;
}




