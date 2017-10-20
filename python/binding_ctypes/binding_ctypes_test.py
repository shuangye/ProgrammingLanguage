#!/usr/bin/env python3
# -*- coding:utf8 -*-

import inspect
import ctypes
import os
from ctypes import *


def __func__():
    return inspect.getouterframes(inspect.currentframe())[1].function


def test_ctypes_char_array():
    char_array_16_t = c_char * 16
    my_array = char_array_16_t()    
    my_array.value = bytes('Hi 你好'.encode('utf-8'))
    # print(__func__() + ": " + str(my_array.value, 'utf-8'))
    print(__func__() + ": " + my_array.value.decode('utf-8'))    # same as the above line

    
def test_ctypes_wchar_array():
    wchar_array_16_t = c_wchar * 16
    my_array = wchar_array_16_t()
    my_array.value = 'Hi 你好'
    print(__func__() + ": " + my_array.value)
    

# C function prototype: `char * DBM_strFunc(char *pInput);`
def test_ctypes_bytes_io():
    # In Python 3.x, the "text literal" is really a unicode object. You want to use the byte-string literal like b"byte-string literal"
    lib_dbm = ctypes.cdll.LoadLibrary("./libbinding_ctypes.so")
    DBM_strFunc = lib_dbm.DBM_strFunc
    DBM_strFunc.argtypes = [ctypes.c_char_p]
    DBM_strFunc.restype = ctypes.c_char_p
    returned = DBM_strFunc(bytes("Hi 中文".encode('utf-8')))
    #print(type(returned))                 # <class 'bytes'>
    #print(returned)                       # b'string literal'
    print(__func__() + ": " + "C function returned " + returned.decode('utf-8'))       # string literal
    # print("C function returned " + str(returned, 'utf-8'))       # same as the above line
    
    
def test_ctypes_struct():
    class DBM_AccessRecord(ctypes.Structure):
        _fields_ = [
                    ('cardno'              , ctypes.c_wchar * 36),
                    ('person_uuid'         , ctypes.c_wchar * 36),
                    ('mac'                 , ctypes.c_wchar * 32),
                    ('opentype'            , ctypes.c_byte),
                    ('area_uuid'           , ctypes.c_wchar * 36),
                    ('slide_date'          , ctypes.c_wchar * 32),
                    ('cdate'               , ctypes.c_wchar * 32),
                    ('dev_uuid'            , ctypes.c_wchar * 36),
                    ('area_code'           , ctypes.c_wchar * 64),
                    ('flag'                , ctypes.c_byte),
                    ('sync'                , ctypes.c_byte)
                   ]
    record = DBM_AccessRecord()     
    record.cardno = '卡号 123'
    print(__func__() + ": DBM_AccessRecord.cardno = " + record.cardno)


    
if '__main__' == __name__:
    test_ctypes_bytes_io()
    test_ctypes_char_array()
    test_ctypes_wchar_array()
    test_ctypes_struct()
    