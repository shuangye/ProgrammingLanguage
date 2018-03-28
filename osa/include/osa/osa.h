#ifndef __OSA_H__
#define __OSA_H__


/*
 * Created by Liu Papillon, on Sep 6, 2017.
 */



#ifndef OSA_MODULE_NAME
#error "The `OSA_MODULE_NAME` macro must be defined."
#endif


#include "osa_platforms.h"
#include "osa_primary_types.h"
#include "osa_types.h"
#include "osa_status.h"
#include "osa_definitions.h"
#include "osa_macro.h"
#include "osa_log.h"
#include "osa_string.h"
#include "osa_list.h"
#include "osa_datetime.h"
#include "osa_fs.h"
#include "osa_misc.h"


int OSA_init(void);

int OSA_deinit(void);


#endif  /* __OSA_H__ */

