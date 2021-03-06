#!/usr/bin/env python3
# -*- encoding: utf-8 -*-

# Created by Papillon. Sat Oct 28 11:17:34 2017. 
# WARNING: DO NOT EDIT THIS FILE. IT IS GENERATED BY A SCRIPT AUTOMATICALLY. 


import ctypes
from ctypes import *


class DBM_House(ctypes.Structure):
    _fields_ = [
        ("uuid"                    , ctypes.c_char    * 36   ),  # [00]
        ("cusr"                    , ctypes.c_char    * 52   ),  # [01]
        ("state_"                  , ctypes.c_char           ),  # [02]
        ("cdate"                   , ctypes.c_char    * 32   ),  # [03]
        ("udate"                   , ctypes.c_char    * 32   ),  # [04]
        ("order_"                  , ctypes.c_int     * 11   ),  # [05]
        ("code"                    , ctypes.c_char    * 64   ),  # [06]
        ("cname"                   , ctypes.c_char    * 64   ),  # [07]
        ("ename"                   , ctypes.c_char    * 32   ),  # [08]
        ("areacode"                , ctypes.c_char    * 64   ),  # [09]
        ("type_"                   , ctypes.c_int            ),  # [10]
        ("remark"                  , ctypes.c_char    * 500  ),  # [11]
        ("keycode"                 , ctypes.c_char    * 32   ),  # [12]
        ("keycode1"                , ctypes.c_char    * 12   ),  # [13]
        ("ifparent"                , ctypes.c_char           ),  # [14]
        ("flag"                    , ctypes.c_char           ),  # [15]
        ("sync"                    , ctypes.c_char           )   # [16]
    ]


class DBM_ExtHouse(ctypes.Structure):
    _fields_ = [
        ("reluuid"                 , ctypes.c_char    * 36   ),  # [00]
        ("jzlx"                    , ctypes.c_char    * 52   ),  # [01]
        ("fwlx"                    , ctypes.c_char    * 52   ),  # [02]
        ("fwsyqlx"                 , ctypes.c_char    * 52   ),  # [03]
        ("fwxxdz"                  , ctypes.c_char    * 256  ),  # [04]
        ("fczh"                    , ctypes.c_char    * 52   ),  # [05]
        ("sspcs"                   , ctypes.c_char    * 128  ),  # [06]
        ("mjxx"                    , ctypes.c_char    * 52   ),  # [07]
        ("czyt"                    , ctypes.c_char    * 256  ),  # [08]
        ("djba"                    , ctypes.c_char    * 128  ),  # [09]
        ("babdate"                 , ctypes.c_char    * 32   ),  # [10]
        ("baedate"                 , ctypes.c_char    * 32   ),  # [11]
        ("xz"                      , ctypes.c_char    * 52   ),  # [12]
        ("gldj"                    , ctypes.c_char    * 4    ),  # [13]
        ("zlzt"                    , ctypes.c_char    * 52   ),  # [14]
        ("jshx"                    , ctypes.c_char    * 52   ),  # [15]
        ("flag"                    , ctypes.c_char           ),  # [16]
        ("sync"                    , ctypes.c_char           )   # [17]
    ]


class DBM_Person(ctypes.Structure):
    _fields_ = [
        ("uuid"                    , ctypes.c_char    * 36   ),  # [00]
        ("cusr"                    , ctypes.c_char    * 52   ),  # [01]
        ("state_"                  , ctypes.c_char    * 1    ),  # [02]
        ("cdate"                   , ctypes.c_char    * 32   ),  # [03]
        ("udate"                   , ctypes.c_char    * 32   ),  # [04]
        ("name"                    , ctypes.c_char    * 52   ),  # [05]
        ("sex"                     , ctypes.c_char           ),  # [06]
        ("nation"                  , ctypes.c_char    * 52   ),  # [07]
        ("birthday"                , ctypes.c_char    * 16   ),  # [08]
        ("regaddress"              , ctypes.c_char    * 100  ),  # [09]
        ("oregaddress"             , ctypes.c_char    * 100  ),  # [10]
        ("curaddress"              , ctypes.c_char    * 100  ),  # [11]
        ("tel"                     , ctypes.c_char    * 20   ),  # [12]
        ("tel2"                    , ctypes.c_char    * 20   ),  # [13]
        ("idcard"                  , ctypes.c_char    * 20   ),  # [14]
        ("authorgan"               , ctypes.c_char    * 100  ),  # [15]
        ("avbdate"                 , ctypes.c_char    * 16   ),  # [16]
        ("avedate"                 , ctypes.c_char    * 16   ),  # [17]
        ("photopath"               , ctypes.c_char    * 4000 ),  # [18]
        ("houseid"                 , ctypes.c_char    * 52   ),  # [19]
        ("focal"                   , ctypes.c_char    * 1    ),  # [20]
        ("proof"                   , ctypes.c_char    * 52   ),  # [21]
        ("islocal"                 , ctypes.c_char    * 1    ),  # [22]
        ("cardisproving"           , ctypes.c_char    * 1    ),  # [23]
        ("ename"                   , ctypes.c_char    * 20   ),  # [24]
        ("flow"                    , ctypes.c_char    * 1    ),  # [25]
        ("family"                  , ctypes.c_char    * 1    ),  # [26]
        ("owner"                   , ctypes.c_char    * 1    ),  # [27]
        ("patrol"                  , ctypes.c_char    * 1    ),  # [28]
        ("finger1"                 , ctypes.c_char    * 4000 ),  # [29]
        ("finger2"                 , ctypes.c_char    * 4000 ),  # [30]
        ("fingertype1"             , ctypes.c_char    * 20   ),  # [31]
        ("fingertype2"             , ctypes.c_char    * 20   ),  # [32]
        ("flag"                    , ctypes.c_char           ),  # [33]
        ("sync"                    , ctypes.c_char           )   # [34]
    ]


class DBM_FlowingPerson(ctypes.Structure):
    _fields_ = [
        ("reluuid"                 , ctypes.c_char    * 36   ),  # [00]
        ("polity"                  , ctypes.c_char    * 52   ),  # [01]
        ("education"               , ctypes.c_char    * 52   ),  # [02]
        ("comdate"                 , ctypes.c_char    * 16   ),  # [03]
        ("pestilence"              , ctypes.c_char    * 200  ),  # [04]
        ("study"                   , ctypes.c_char    * 200  ),  # [05]
        ("inoculability"           , ctypes.c_char    * 1    ),  # [06]
        ("staycard"                , ctypes.c_char    * 20   ),  # [07]
        ("workaddress"             , ctypes.c_char    * 64   ),  # [08]
        ("marry"                   , ctypes.c_char    * 52   ),  # [09]
        ("matename"                , ctypes.c_char    * 20   ),  # [10]
        ("mateno"                  , ctypes.c_char    * 20   ),  # [11]
        ("girls"                   , ctypes.c_short          ),  # [12]
        ("boys"                    , ctypes.c_short          ),  # [13]
        ("pregnantno"              , ctypes.c_char    * 20   ),  # [14]
        ("pregnantdate"            , ctypes.c_char    * 32   ),  # [15]
        ("pregnantcont"            , ctypes.c_char    * 20   ),  # [16]
        ("ispregnant"              , ctypes.c_char    * 1    ),  # [17]
        ("isshbx"                  , ctypes.c_char    * 1    ),  # [18]
        ("isldht"                  , ctypes.c_char    * 1    ),  # [19]
        ("cbdwmc"                  , ctypes.c_char    * 64   ),  # [20]
        ("cbdwlxr"                 , ctypes.c_char    * 20   ),  # [21]
        ("cbdwlxdh"                , ctypes.c_char    * 20   ),  # [22]
        ("jyqk"                    , ctypes.c_char    * 200  ),  # [23]
        ("jdxx"                    , ctypes.c_char    * 40   ),  # [24]
        ("jzlx"                    , ctypes.c_char    * 52   ),  # [25]
        ("hjlx"                    , ctypes.c_char    * 52   ),  # [26]
        ("jzzj"                    , ctypes.c_char    * 40   ),  # [27]
        ("zlzt"                    , ctypes.c_char    * 4    ),  # [28]
        ("livereason"              , ctypes.c_char    * 52   ),  # [29]
        ("hzlsh"                   , ctypes.c_char    * 52   ),  # [30]
        ("remark"                  , ctypes.c_char    * 200  ),  # [31]
        ("flag"                    , ctypes.c_char           ),  # [32]
        ("sync"                    , ctypes.c_char           )   # [33]
    ]


class DBM_Device(ctypes.Structure):
    _fields_ = [
        ("uuid"                    , ctypes.c_char    * 36   ),  # [00]
        ("dev_number"              , ctypes.c_char    * 36   ),  # [01]
        ("name"                    , ctypes.c_char    * 64   ),  # [02]
        ("mac"                     , ctypes.c_char    * 20   ),  # [03]
        ("type_"                   , ctypes.c_char           ),  # [04]
        ("gw_uuid"                 , ctypes.c_char    * 36   ),  # [05]
        ("status"                  , ctypes.c_char           ),  # [06]
        ("area_uuid"               , ctypes.c_char    * 36   ),  # [07]
        ("area_layercode"          , ctypes.c_char    * 52   ),  # [08]
        ("cdate"                   , ctypes.c_char    * 32   ),  # [09]
        ("udate"                   , ctypes.c_char    * 32   ),  # [10]
        ("innerkey_"               , ctypes.c_char    * 32   ),  # [11]
        ("cuser"                   , ctypes.c_char    * 36   ),  # [12]
        ("locktype"                , ctypes.c_char           ),  # [13]
        ("flag"                    , ctypes.c_char           ),  # [14]
        ("sync"                    , ctypes.c_char           )   # [15]
    ]


class DBM_Card(ctypes.Structure):
    _fields_ = [
        ("uuid"                    , ctypes.c_char    * 36   ),  # [00]
        ("crkno"                   , ctypes.c_char    * 32   ),  # [01]
        ("idcode"                  , ctypes.c_char    * 20   ),  # [02]
        ("addrcode"                , ctypes.c_char    * 32   ),  # [03]
        ("udate"                   , ctypes.c_char    * 32   ),  # [04]
        ("cuser"                   , ctypes.c_char    * 36   ),  # [05]
        ("state_"                  , ctypes.c_char           ),  # [06]
        ("stime"                   , ctypes.c_char    * 32   ),  # [07]
        ("etime"                   , ctypes.c_char    * 32   ),  # [08]
        ("cdate"                   , ctypes.c_char    * 32   ),  # [09]
        ("key_"                    , ctypes.c_char    * 8    ),  # [10]
        ("mac"                     , ctypes.c_char    * 30   ),  # [11]
        ("layercode"               , ctypes.c_char    * 52   ),  # [12]
        ("crkno4"                  , ctypes.c_char    * 32   ),  # [13]
        ("key1"                    , ctypes.c_char    * 8    ),  # [14]
        ("flag"                    , ctypes.c_char           ),  # [15]
        ("sync"                    , ctypes.c_char           )   # [16]
    ]


class DBM_SAMCard(ctypes.Structure):
    _fields_ = [
        ("type_"                   , ctypes.c_char           ),  # [00]
        ("stime"                   , ctypes.c_char    * 16   ),  # [01]
        ("etime"                   , ctypes.c_char    * 16   ),  # [02]
        ("area_uuid"               , ctypes.c_char    * 36   ),  # [03]
        ("device_uuid"             , ctypes.c_char    * 36   ),  # [04]
        ("status"                  , ctypes.c_char           ),  # [05]
        ("cuser"                   , ctypes.c_char    * 36   ),  # [06]
        ("cdate"                   , ctypes.c_char    * 16   ),  # [07]
        ("udate"                   , ctypes.c_char    * 16   ),  # [08]
        ("serial_id"               , ctypes.c_char    * 32   ),  # [09]
        ("flag"                    , ctypes.c_char           ),  # [10]
        ("sync"                    , ctypes.c_char           )   # [11]
    ]


class DBM_CardPermission(ctypes.Structure):
    _fields_ = [
        ("crk_uuid"                , ctypes.c_char    * 36   ),  # [00]
        ("dev_uuid"                , ctypes.c_char    * 36   ),  # [01]
        ("state_"                  , ctypes.c_char           ),  # [02]
        ("stime"                   , ctypes.c_char    * 16   ),  # [03]
        ("etime"                   , ctypes.c_char    * 16   ),  # [04]
        ("cuser"                   , ctypes.c_char    * 36   ),  # [05]
        ("cdate"                   , ctypes.c_char    * 16   ),  # [06]
        ("udate"                   , ctypes.c_char    * 16   ),  # [07]
        ("area_uuid"               , ctypes.c_char    * 36   ),  # [08]
        ("flag"                    , ctypes.c_char           ),  # [09]
        ("sync"                    , ctypes.c_char           )   # [10]
    ]


class DBM_CardOwning(ctypes.Structure):
    _fields_ = [
        ("person_uuid"             , ctypes.c_char    * 36   ),  # [00]
        ("crk_uuid"                , ctypes.c_char    * 36   ),  # [01]
        ("cuser"                   , ctypes.c_char    * 36   ),  # [02]
        ("cdate"                   , ctypes.c_char    * 16   ),  # [03]
        ("udate"                   , ctypes.c_char    * 16   ),  # [04]
        ("idcard"                  , ctypes.c_char    * 36   ),  # [05]
        ("flag"                    , ctypes.c_char           ),  # [06]
        ("sync"                    , ctypes.c_char           )   # [07]
    ]


class DBM_UserHouse(ctypes.Structure):
    _fields_ = [
        ("userid"                  , ctypes.c_char    * 36   ),  # [00]
        ("houseid"                 , ctypes.c_char    * 36   ),  # [01]
        ("date_"                   , ctypes.c_char    * 16   ),  # [02]
        ("udate"                   , ctypes.c_char    * 32   ),  # [03]
        ("reltype"                 , ctypes.c_char    * 1    ),  # [04]
        ("parm1"                   , ctypes.c_char    * 52   ),  # [05]
        ("parm2"                   , ctypes.c_char    * 52   ),  # [06]
        ("edate"                   , ctypes.c_char    * 16   ),  # [07]
        ("state_"                  , ctypes.c_char    * 16   ),  # [08]
        ("idcard"                  , ctypes.c_char    * 52   ),  # [09]
        ("arcode"                  , ctypes.c_char    * 64   ),  # [10]
        ("crk_uuid"                , ctypes.c_char    * 36   ),  # [11]
        ("crk_crkno"               , ctypes.c_char    * 52   ),  # [12]
        ("flag"                    , ctypes.c_char           ),  # [13]
        ("sync"                    , ctypes.c_char           )   # [14]
    ]


class DBM_AccessRecord(ctypes.Structure):
    _fields_ = [
        ("cardno"                  , ctypes.c_char    * 36   ),  # [00]
        ("person_uuid"             , ctypes.c_char    * 36   ),  # [01]
        ("mac"                     , ctypes.c_char    * 32   ),  # [02]
        ("opentype"                , ctypes.c_char           ),  # [03]
        ("area_uuid"               , ctypes.c_char    * 36   ),  # [04]
        ("slide_date"              , ctypes.c_char    * 32   ),  # [05]
        ("cdate"                   , ctypes.c_char    * 32   ),  # [06]
        ("dev_uuid"                , ctypes.c_char    * 36   ),  # [07]
        ("dev_number"              , ctypes.c_char    * 36   ),  # [08]
        ("area_code"               , ctypes.c_char    * 64   ),  # [09]
        ("dev_date"                , ctypes.c_char    * 32   ),  # [10]
        ("flag"                    , ctypes.c_char           ),  # [11]
        ("sync"                    , ctypes.c_char           )   # [12]
    ]


class DBM_DeviceAlarm(ctypes.Structure):
    _fields_ = [
        ("uuid"                    , ctypes.c_char    * 36   ),  # [00]
        ("occur_date"              , ctypes.c_char    * 32   ),  # [01]
        ("cdate"                   , ctypes.c_char    * 32   ),  # [02]
        ("type_"                   , ctypes.c_char           ),  # [03]
        ("status"                  , ctypes.c_char           ),  # [04]
        ("udate"                   , ctypes.c_char    * 32   ),  # [05]
        ("mac"                     , ctypes.c_char    * 20   ),  # [06]
        ("area_uuid"               , ctypes.c_char    * 36   ),  # [07]
        ("account_uuid"            , ctypes.c_char    * 36   ),  # [08]
        ("device_uuid"             , ctypes.c_char    * 36   ),  # [09]
        ("remark"                  , ctypes.c_char    * 256  ),  # [10]
        ("cardno"                  , ctypes.c_char    * 36   ),  # [11]
        ("flag"                    , ctypes.c_char           ),  # [12]
        ("sync"                    , ctypes.c_char           )   # [13]
    ]


class DBM_DeviceStatuse(ctypes.Structure):
    _fields_ = [
        ("dev_uuid"                , ctypes.c_char    * 36   ),  # [00]
        ("status"                  , ctypes.c_char           ),  # [01]
        ("hwversion"               , ctypes.c_char    * 32   ),  # [02]
        ("sfversion"               , ctypes.c_char    * 32   ),  # [03]
        ("imsi"                    , ctypes.c_char    * 32   ),  # [04]
        ("msisdn"                  , ctypes.c_char    * 32   ),  # [05]
        ("battery"                 , ctypes.c_float          ),  # [06]
        ("temperature"             , ctypes.c_float          ),  # [07]
        ("signal_"                 , ctypes.c_float          ),  # [08]
        ("udate"                   , ctypes.c_char    * 32   ),  # [09]
        ("cardpopedomcapacity"     , ctypes.c_int            ),  # [10]
        ("cardpopedomcount"        , ctypes.c_int            ),  # [11]
        ("fingercapacity"          , ctypes.c_int            ),  # [12]
        ("fingercount"             , ctypes.c_int            ),  # [13]
        ("opened"                  , ctypes.c_char           ),  # [14]
        ("cdate"                   , ctypes.c_char    * 32   ),  # [15]
        ("cuser"                   , ctypes.c_char    * 36   ),  # [16]
        ("workmode"                , ctypes.c_char           ),  # [17]
        ("powermode"               , ctypes.c_char           ),  # [18]
        ("flag"                    , ctypes.c_char           ),  # [19]
        ("sync"                    , ctypes.c_char           )   # [20]
    ]


