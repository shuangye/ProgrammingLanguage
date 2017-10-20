#!/usr/bin/env python3
# -*- encoding: utf-8 -*-

import ctypes
import os
import dbm_entities
import dbm_utilities
from ctypes import *
from enum import IntEnum


"About enum in Python http://www.chriskrycho.com/2015/ctypes-structures-and-dll-exports.html"
class CtypesEnum(IntEnum):
    """A ctypes-compatible IntEnum superclass."""
    @classmethod
    def from_param(cls, obj):
        return int(obj)

class DBM_EntityType(CtypesEnum):
    DBM_ENTITY_TYPE_NONE                      = 0
    DBM_ENTITY_TYPE_HOUSE                     = 1
    DBM_ENTITY_TYPE_EXT_HOUSE                 = 2
    DBM_ENTITY_TYPE_PERSON                    = 3
    DBM_ENTITY_TYPE_FLOWING_PERSON            = 4
    DBM_ENTITY_TYPE_DEVICE                    = 5
    DBM_ENTITY_TYPE_CARD                      = 6
    DBM_ENTITY_TYPE_SAMCARD                   = 7
    DBM_ENTITY_TYPE_CARD_PERMISSION           = 8
    DBM_ENTITY_TYPE_CARD_OWNING               = 9
    DBM_ENTITY_TYPE_USER_HOUSE                = 10
    DBM_ENTITY_TYPE_ACCESS_RECORD             = 11
    DBM_ENTITY_TYPE_DEVICE_ALARM              = 12
    DBM_ENTITY_TYPE_DEVICE_STATUS             = 13
    DBM_ENTITY_TYPE_COUNT                     = 14
    DBM_ENTITY_TYPE_FIRST                     = DBM_ENTITY_TYPE_HOUSE 
    DBM_ENTITY_TYPE_LAST                      = DBM_ENTITY_TYPE_DEVICE_STATUS

    # Option 1: set the _as_parameter value at construction.
    # def __init__(self, value):
    #     self._as_parameter = int(value)

    # Option 2: define the class method `from_param`.
    # @classmethod
    # def from_param(cls, obj):
    #     return int(obj)
    # since this class inherits CtypesEnum, the `from_param` method can be omitted.


gLibdbmPath = r"../build/libdbmanager.so"
gLibdbm = None
gLibdbmHandle = ctypes.c_void_p()
# global libdbm_path, libdbm, libdbm_handle


def DBM_init(pDbPath):
    global gLibdbmPath, gLibdbm, gLibdbmHandle

    if (None == pDbPath):
        return -1

    gLibdbm = ctypes.cdll.LoadLibrary(gLibdbmPath)
    c_DBM_init = gLibdbm.DBM_init
    c_DBM_init.argtypes = [ctypes.c_char_p, ctypes.POINTER(ctypes.c_void_p)]
    c_DBM_init.restype = ctypes.c_int
    handle = ctypes.c_void_p()
    ret = c_DBM_init(dbm_utilities.DBM_utlToString(pDbPath), handle) 
    # print("c_DBM_init returned {ret}, handle = {handle}".format(ret = ret, handle = handle))    
    return ret, handle


def DBM_deinit(handle):
    c_DBM_deinit = gLibdbm.DBM_deinit
    c_DBM_deinit.argtypes = [ctypes.c_void_p]
    c_DBM_deinit.restype = ctypes.c_int
    return c_DBM_deinit(handle)
    

def DBM_getUnsyncedEntity(handle, entityType):
    c_DBM_getUnsyncedEntity = gLibdbm.DBM_getUnsyncedEntity
    c_DBM_getUnsyncedEntity.argtypes = [ctypes.c_void_p, DBM_EntityType, ctypes.c_void_p, ctypes.c_void_p]
    c_DBM_getUnsyncedEntity.restype = ctypes.c_int
    entity = dbm_entities.DBM_AccessRecord()
    ret = c_DBM_getUnsyncedEntity(handle, entityType, ctypes.addressof(entity), None)
    return ret, entity


def DBM_insertEntity(handle, entityType, entity):
    c_DBM_insertEntity = gLibdbm.DBM_insertEntity
    c_DBM_insertEntity.argtypes = [ctypes.c_void_p, DBM_EntityType, ctypes.c_void_p, ctypes.c_void_p]
    c_DBM_insertEntity.restype = ctypes.c_int
    ret = c_DBM_insertEntity(handle, entityType, ctypes.addressof(entity), None)
    return ret


def DBM_printEntity(entityType, entity):
    c_DBM_printEntity = gLibdbm.DBM_printEntity
    c_DBM_printEntity.argtypes = [DBM_EntityType, ctypes.c_void_p]
    c_DBM_printEntity.restype = None
    c_DBM_printEntity(entityType, ctypes.addressof(entity))


def DBM_test():
    global gLibdbmPath, gLibdbm, gLibdbmHandle

    entityType = DBM_EntityType.DBM_ENTITY_TYPE_ACCESS_RECORD

    ret, gLibdbmHandle = DBM_init("/home/papillon/dev/houses.db")
    # print("G_libdbm_handle = " + str(gLibdbmHandle))

    entity = dbm_entities.DBM_AccessRecord()
    entity.cardno = dbm_utilities.DBM_utlToString("Card no. 123")
    entity.person_uuid = dbm_utilities.DBM_utlToString('Person 人员 uuid 1234567890')
    entity.mac = dbm_utilities.DBM_utlToString("mac 1234")
    entity.opentype = 1
    entity.area_uuid = dbm_utilities.DBM_utlToString("area 区域 uuid 1234567890")
    entity.slide_date = dbm_utilities.DBM_utlToString("20171019175200")
    entity.cdate = dbm_utilities.DBM_utlToString("20171019175200")
    entity.dev_uuid = dbm_utilities.DBM_utlToString("dev uuid 1234567890")
    entity.area_code = dbm_utilities.DBM_utlToString("area code")
    entity.flag = 1
    ret = DBM_insertEntity(gLibdbmHandle, entityType, entity)

    ret, entity = DBM_getUnsyncedEntity(gLibdbmHandle, entityType)
    print("DBM_getUnsyncedEntity: ret = {ret}".format(ret = ret))

    DBM_printEntity(entityType, entity)

    ret = DBM_deinit(gLibdbmHandle)
    print("DBM_deinit: ret = {ret}".format(ret = ret))




if "__main__" == __name__:
    DBM_test()
