#pragma once
#ifndef __DBM_H__
#define __DBM_H__

#include <osa/osa.h>
#include "dbm_definitions.h"
// #include "dbm_utils.h"
#include "dbm_entities.h"
// #include "dbm_houses.h"
// #include "dbm_persons.h"

#ifdef __cplusplus
extern "C" {
#endif // __cplusplus

    typedef enum DBM_EntityType {
        DBM_ENTITY_TYPE_NONE                      = 0,
        DBM_ENTITY_TYPE_HOUSE                     = 1,
        DBM_ENTITY_TYPE_EXT_HOUSE                 = 2,
        DBM_ENTITY_TYPE_PERSON                    = 3,
        DBM_ENTITY_TYPE_FLOWING_PERSON            = 4,
        DBM_ENTITY_TYPE_DEVICE                    = 5,
        DBM_ENTITY_TYPE_CARD                      = 6,
        DBM_ENTITY_TYPE_SAMCARD                   = 7,
        DBM_ENTITY_TYPE_CARD_PERMISSION           = 8, 
        DBM_ENTITY_TYPE_CARD_OWNING               = 9,
        DBM_ENTITY_TYPE_USER_HOUSE                = 10,
        DBM_ENTITY_TYPE_ACCESS_RECORD             = 11,
        DBM_ENTITY_TYPE_DEVICE_ALARM              = 12,
        DBM_ENTITY_TYPE_DEVICE_STATUS             = 13,
        DBM_ENTITY_TYPE_COUNT                     = 14,
        DBM_ENTITY_TYPE_FIRST                     = DBM_ENTITY_TYPE_HOUSE, 
        DBM_ENTITY_TYPE_LAST                      = DBM_ENTITY_TYPE_DEVICE_STATUS, 
    } DBM_EntityType;
      

    typedef int (*DBM_EntityFilter)(const DBM_EntityType entityType, const void *pEntity);
    typedef struct DBM_GetOptions {
        DBM_EntityType                 entityType;        
        DBM_EntityFilter               filter;               /* returns 0: do not use this entity; returns non-0: use this entity. Can be used to implement complex filters */
        Char                          *pConditions;          /* the conditions after SQL `WHERE` keyword */
        /*  
           Example:  Get at most 10 persons that are not synced:
           int ret;
           Uint32 maxCount = 10;           
           DBM_GetOptions options;           
           OSA_clear(&options);
           
           options.entityType = DBM_ENTITY_TYPE_PERSON;
           options.filter = NULL;
           options.pConditions = "sync == 1"
           void *pBuffer = malloc(sizeof(person) * maxCount);
           ret = DBM_getEntity(handle, pBuffer, maxCount, &options);
         */
    } DBM_GetOptions;
        

    
    int DBM_init(const Char *pDbPath, DBM_Handle *pHandle);

    int DBM_deinit(DBM_Handle handle);

    /* not implemented yet */
    // int DBM_getEntity(DBM_Handle handle, void *pBuffer, const Uint32 maxCount, const DBM_GetOptions *pOptions);

    int DBM_getUnsyncedEntity(DBM_Handle handle, const DBM_EntityType entityType, void *pEntity, void *pAssociation);

    int DBM_insertEntity(DBM_Handle handle, const DBM_EntityType entityType, const void *pEntity, const void *pAssociation);
    
    int DBM_printEntity(const DBM_EntityType entityType, const void *pEntity);

#ifdef __cplusplus
}
#endif // __cplusplus



#endif  /* __DBM_H__ */
