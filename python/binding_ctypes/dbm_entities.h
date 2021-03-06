#pragma once
#ifndef __DBM_ENTITIES_H__
#define __DBM_ENTITIES_H__

/* Created by Papillon. Wed Nov  1 14:49:45 2017. */
/* WARNING: DO NOT EDIT THIS FILE. IT IS GENERATED BY A SCRIPT AUTOMATICALLY. */

#include <osa/osa.h>  /* primary types definitions */


typedef struct DBM_House
{
    Char                uuid[36];                     /* [00] ATTR:AUTO_ON_C(UUID), NO_U(UUID); 32 characters; allocate 36 characters for terminating '\0' */
    Char                cusr[52];                     /* [01] creation user */
    Int8                state_;                       /* [02] ? 什么状态，取什么值 */
    Char                cdate[32];                    /* [03] ATTR:AUTO_ON_C(DATETIME), NO_U(DATETIME); creation date */
    Char                udate[32];                    /* [04] ATTR:AUTO_ON_C(DATETIME), AUTO_ON_U(DATETIME); update date */
    Int32               order_;                       /* [05] ? for sorting */
    Char                code[64];                     /* [06] 区域层级编码 */
    Char                cname[64];                    /* [07] Chinese name */
    Char                ename[32];                    /* [08] English name */
    Char                areacode[64];                 /* [09] 完整区域行政编码 */
    Int32               type_;                        /* [10] 类型: 省 1, 地级市 2, 县级市, 县 3, 乡,镇,街道 4, 社区, 村 5, 街,路,巷,里 6, 门牌号 7, 小区（农居点） 8, 楼幢 9, 单元 10, 房屋 11 */
    Char                remark[500];                  /* [11] 备注 */
    Char                keycode[32];                  /* [12] 区域权限因子(二级) （定长为 4位数字） */
    Char                keycode1[12];                 /* [13] 区域权限因子(一级) （定长为 4位数字） */
    Int8                ifparent;                     /* [14] ? */
    Int8                flag;                         /* [15] ATTR:AUTO_ON_C(FLAG), AUTO_ON_U(FLAG); flag 导入类型：增｜删｜改，C｜D｜U */
    Int8                sync;                         /* [16] ATTR:AUTO_ON_C(SYNC); 0 未同步; 1 已同步到公共平台 */
} DBM_House;


typedef struct DBM_ExtHouse
{
    Char                reluuid[36];                  /* [00]  */
    Char                jzlx[52];                     /* [01] 居住类型（数据字典） */
    Char                fwlx[52];                     /* [02] 房屋类型（数据字典） */
    Char                fwsyqlx[52];                  /* [03] 房屋所有权类型（数据字典） */
    Char                fwxxdz[256];                  /* [04] 房屋详细地址 */
    Char                fczh[52];                     /* [05] 房产证号 */
    Char                sspcs[128];                   /* [06] 所属派出所 */
    Char                mjxx[52];                     /* [07] 民警姓名 */
    Char                czyt[256];                    /* [08] 出租用途 */
    Char                djba[128];                    /* [09] 登记备案 */
    Char                babdate[32];                  /* [10] 备案开始时间 */
    Char                baedate[32];                  /* [11] 备案结束时间 */
    Char                xz[52];                       /* [12] 性质（数据字典） */
    Char                gldj[4];                      /* [13] 管理等级（数据字典） */
    Char                zlzt[52];                     /* [14] 租赁类型（数据字典） */
    Char                jshx[52];                     /* [15] 居所户型（数据字典） */
    Int8                flag;                         /* [16] ATTR:AUTO_ON_C(FLAG), AUTO_ON_U(FLAG); flag 导入类型：增｜删｜改，C｜D｜U */
    Int8                sync;                         /* [17] ATTR:AUTO_ON_C(SYNC); 0 未同步; 1 已同步到公共平台 */
} DBM_ExtHouse;


typedef struct DBM_Person
{
    Char                uuid[36];                     /* [00] ATTR:AUTO_ON_C(UUID), NO_U(UUID); */
    Char                cusr[52];                     /* [01] creation user */
    Int8                state_;                       /* [02] ? 什么状态，取什么值 */
    Char                cdate[32];                    /* [03] ATTR:AUTO_ON_C(DATETIME), NO_U(DATETIME); */
    Char                udate[32];                    /* [04] ATTR:AUTO_ON_C(DATETIME), AUTO_ON_U(DATETIME); */
    Char                name[52];                     /* [05] 姓名(需要加密) */
    Int8                sex;                          /* [06] 性别（数据字典） */
    Char                nation[52];                   /* [07] 民族（数据字典） */
    Char                birthday[16];                 /* [08] 出生日期 yyyymmdd */
    Char                regaddress[100];              /* [09] 户籍地址 */
    Char                oregaddress[100];             /* [10] 原户籍地址 */
    Char                curaddress[100];              /* [11] 现居地址 */
    Char                tel[20];                      /* [12] 联系电话(需要加密) */
    Char                tel2[20];                     /* [13] 备用电话(需要加密) */
    Char                idcard[20];                   /* [14] 身份证号(需要加密) */
    Char                authorgan[100];               /* [15] 签发机关 */
    Char                avbdate[16];                  /* [16] 身份证有效期开始时间 */
    Char                avedate[16];                  /* [17] 身份证有效期结束时间 */
    Char                photopath[4000];              /* [18] 身份证照片路径(需要加密) */
    Char                houseid[52];                  /* [19] ? 房屋居住id */
    Int8                focal;                        /* [20] 是否重点人员 0|否, 1|是 */
    Char                proof[52];                    /* [21] 证件类型 [数据字典] */
    Int8                islocal;                      /* [22] 是否是本地人口 */
    Int8                cardisproving;                /* [23] 身份证是否被验证 */
    Char                ename[20];                    /* [24] 姓名简拼 */
    Int8                flow;                         /* [25] 是否是租客 */
    Int8                family;                       /* [26] 是否是家属 */
    Int8                owner;                        /* [27] 是否是房东 */
    Int8                patrol;                       /* [28] 巡访 */
    Char                finger1[4000];                /* [29] 指纹采集一 (需要加密) */
    Char                finger2[4000];                /* [30] 指纹采集二 (需要加密) */
    Char                fingertype1[20];              /* [31] 指纹采集一类型 */
    Char                fingertype2[20];              /* [32] 指纹采集二类型 */
    Int8                flag;                         /* [33] ATTR:AUTO_ON_C(FLAG), AUTO_ON_U(FLAG); flag 导入类型：增｜删｜改，C｜D｜U */
    Int8                sync;                         /* [34] ATTR:AUTO_ON_C(SYNC); 0 未同步; 1 已同步到公共平台 */
} DBM_Person;


typedef struct DBM_FlowingPerson
{
    Char                reluuid[36];                  /* [00]  */
    Char                polity[52];                   /* [01] 政治面貌 （数据字典） */
    Char                education[52];                /* [02] 文化程度 （数据字典） */
    Char                comdate[16];                  /* [03] 来本地日期 */
    Char                pestilence[200];              /* [04] 防疫情况 */
    Char                study[200];                   /* [05] 就学情况 */
    Int8                inoculability;                /* [06] 是否接种 */
    Char                staycard[20];                 /* [07] 暂住证编号 */
    Char                workaddress[64];              /* [08] 工作地址 */
    Char                marry[52];                    /* [09] 婚育情况 */
    Char                matename[20];                 /* [10] 配偶姓名(需要加密) */
    Char                mateno[20];                   /* [11] 配偶身份证(需要加密) */
    Int16               girls;                        /* [12] 生育女孩子数 */
    Int16               boys;                         /* [13] 生育女孩子数 */
    Char                pregnantno[20];               /* [14] 所持孕育证号码 */
    Char                pregnantdate[32];             /* [15] 孕检时间 */
    Char                pregnantcont[20];             /* [16] 落实避孕措施 */
    Int8                ispregnant;                   /* [17] 是否怀孕 */
    Int8                isshbx;                       /* [18] 是否参加社会保险 */
    Int8                isldht;                       /* [19] 是否签到劳动合同 */
    Char                cbdwmc[64];                   /* [20] 参保单位名称 */
    Char                cbdwlxr[20];                  /* [21] 参保单位联系人(需要加密) */
    Char                cbdwlxdh[20];                 /* [22] 参保单位联系电话 */
    Char                jyqk[200];                    /* [23] 教育情况 */
    Char                jdxx[40];                     /* [24] 就读学校 */
    Char                jzlx[52];                     /* [25] 居住类型 （数据字典） */
    Char                hjlx[52];                     /* [26] 户籍类型 （数据字典） */
    Char                jzzj[40];                     /* [27] 居住证件 */
    Char                zlzt[4];                      /* [28] 租赁状态 （数据字典） */
    Char                livereason[52];               /* [29] 暂住事由 */
    Char                hzlsh[52];                    /* [30] 户主流水号 */
    Char                remark[200];                  /* [31]  */
    Int8                flag;                         /* [32] ATTR:AUTO_ON_C(FLAG), AUTO_ON_U(FLAG); flag 导入类型：增｜删｜改，C｜D｜U */
    Int8                sync;                         /* [33] ATTR:AUTO_ON_C(SYNC); 0 未同步; 1 已同步到公共平台 */
} DBM_FlowingPerson;


typedef struct DBM_Device
{
    Char                uuid[36];                     /* [00] ATTR:AUTO_ON_C(UUID), NO_U(UUID); */
    Char                dev_number[36];               /* [01] Added by DUSUN. 设备编号 */
    Char                name[64];                     /* [02] 设备名称 */
    Char                mac[20];                      /* [03] mac地址 */
    Int8                type_;                        /* [04] 设备类型 1：控制器，2：门锁 */
    Char                gw_uuid[36];                  /* [05] 所属控制器（网关）的uuid */
    Int8                status;                       /* [06] 设备状态 1：正常，2：异常，3：其他 */
    Char                area_uuid[36];                /* [07] 所在区域的uuid */
    Char                area_layercode[52];           /* [08] 所在区域的层级编码，对应区域房屋信息中的code */
    Char                cdate[32];                    /* [09] ATTR:AUTO_ON_C(DATETIME), NO_U(DATETIME); */
    Char                udate[32];                    /* [10] ATTR:AUTO_ON_C(DATETIME), AUTO_ON_U(DATETIME); */
    Char                innerkey_[32];                /* [11] 门锁对应控制器内部key */
    Char                cuser[36];                    /* [12] ? uuid? 创建人 */
    Int8                locktype;                     /* [13] 门锁类型 */
    Int8                flag;                         /* [14] ATTR:AUTO_ON_C(FLAG), AUTO_ON_U(FLAG); flag 导入类型：增｜删｜改，C｜D｜U */
    Int8                sync;                         /* [15] ATTR:AUTO_ON_C(SYNC); 0 未同步; 1 已同步到公共平台 */
} DBM_Device;


typedef struct DBM_Card
{
    Char                uuid[36];                     /* [00] ATTR:AUTO_ON_C(UUID), NO_U(UUID); 主键（关联表中外键引用） */
    Char                crkno[32];                    /* [01] 卡号 */
    Char                idcode[20];                   /* [02] 身份信息编码( 参见杭州市规范 ) (需要加密) */
    Char                addrcode[32];                 /* [03] 住址信息编码( 参见杭州市规范 ) */
    Char                udate[32];                    /* [04] ATTR:AUTO_ON_C(DATETIME), AUTO_ON_U(DATETIME); */
    Char                cuser[36];                    /* [05] 创建者 uuid */
    Int8                state_;                       /* [06] 出入卡状态(0:初始化;1:操作中;2:正常;3:挂失;4:注销) */
    Char                stime[32];                    /* [07] 有效期开始时间 */
    Char                etime[32];                    /* [08] 有效期结束时间 */
    Char                cdate[32];                    /* [09] ATTR:AUTO_ON_C(DATETIME), NO_U(DATETIME); */
    Char                key_[8];                      /* [10] 区域权限因子(二级) （定长为 4位） */
    Char                mac[30];                      /* [11] ? WTF */
    Char                layercode[52];                /* [12] 归属区域层级编码 */
    Char                crkno4[32];                   /* [13] 卡号后4位 */
    Char                key1[8];                      /* [14] 区域权限因子(一级) （定长为 4位） */
    Int8                flag;                         /* [15] ATTR:AUTO_ON_C(FLAG), AUTO_ON_U(FLAG); flag 导入类型：增｜删｜改，C｜D｜U */
    Int8                sync;                         /* [16] ATTR:AUTO_ON_C(SYNC); 0 未同步; 1 已同步到公共平台 */
} DBM_Card;


typedef struct DBM_SAMCard
{
    Int8                type_;                        /* [00] sam卡类型 1：发卡SAM卡 2：门禁SAM卡 */
    Char                stime[16];                    /* [01] 开始时间 */
    Char                etime[16];                    /* [02] 结束时间 */
    Char                area_uuid[36];                /* [03] 区域外键 */
    Char                device_uuid[36];              /* [04] 设备外键 */
    Int8                status;                       /* [05] sam卡状态(0:正常;1:黑名单) */
    Char                cuser[36];                    /* [06] ? uuid? 创建者 */
    Char                cdate[16];                    /* [07] ATTR:AUTO_ON_C(DATE), NO_U(DATE); */
    Char                udate[16];                    /* [08] ATTR:AUTO_ON_C(DATE), AUTO_ON_U(DATE); */
    Char                serial_id[32];                /* [09] 卡序列号 */
    Int8                flag;                         /* [10] ATTR:AUTO_ON_C(FLAG), AUTO_ON_U(FLAG); flag 导入类型：增｜删｜改，C｜D｜U */
    Int8                sync;                         /* [11] ATTR:AUTO_ON_C(SYNC); 0 未同步; 1 已同步到公共平台 */
} DBM_SAMCard;


typedef struct DBM_CardPermission
{
    Char                crk_uuid[36];                 /* [00] 出入卡外键 */
    Char                dev_uuid[36];                 /* [01] 设备外键 */
    Int8                state_;                       /* [02] 状态 1：有效， 2：无效 */
    Char                stime[16];                    /* [03] 权限开始时间 */
    Char                etime[16];                    /* [04] 权限截止时间 */
    Char                cuser[36];                    /* [05] ? uuid? in which talbe? */
    Char                cdate[16];                    /* [06] ATTR:AUTO_ON_C(DATE), NO_U(DATE); */
    Char                udate[16];                    /* [07] ATTR:AUTO_ON_C(DATE), AUTO_ON_U(DATE); */
    Char                area_uuid[36];                /* [08] 设备区域外键 */
    Int8                flag;                         /* [09] ATTR:AUTO_ON_C(FLAG), AUTO_ON_U(FLAG); flag 导入类型：增｜删｜改，C｜D｜U */
    Int8                sync;                         /* [10] ATTR:AUTO_ON_C(SYNC); 0 未同步; 1 已同步到公共平台 */
} DBM_CardPermission;


typedef struct DBM_CardOwning
{
    Char                person_uuid[36];              /* [00] 人员外键 */
    Char                crk_uuid[36];                 /* [01] 出入卡外键 */
    Char                cuser[36];                    /* [02] ? uuid? 创建者 */
    Char                cdate[16];                    /* [03] ATTR:AUTO_ON_C(DATE), NO_U(DATE); */
    Char                udate[16];                    /* [04] ATTR:AUTO_ON_C(DATE), AUTO_ON_U(DATE); */
    Char                idcard[36];                   /* [05] ? uuid? 证件号码(需要加密) */
    Int8                flag;                         /* [06] ATTR:AUTO_ON_C(FLAG), AUTO_ON_U(FLAG); flag 导入类型：增｜删｜改，C｜D｜U */
    Int8                sync;                         /* [07] ATTR:AUTO_ON_C(SYNC); 0 未同步; 1 已同步到公共平台 */
} DBM_CardOwning;


typedef struct DBM_UserHouse
{
    Char                userid[36];                   /* [00] ? 外键引用吗 */
    Char                houseid[36];                  /* [01] ? 外键引用吗 */
    Char                date_[16];                    /* [02] 关联起始日期 */
    Char                udate[32];                    /* [03] ATTR:AUTO_ON_C(DATETIME), AUTO_ON_U(DATETIME); 记录创建日期 */
    Int8                reltype;                      /* [04] 关联类型 1：租客, 2：房东, 3：家属, 4：巡访,  5：其他 */
    Char                parm1[52];                    /* [05] 持卡类型：1：主卡， 2：附属卡 */
    Char                parm2[52];                    /* [06]  */
    Char                edate[16];                    /* [07] 关联结束日期 */
    Char                state_[16];                   /* [08] Added as per protocol requirement */
    Char                idcard[52];                   /* [09] 证件号码(需要加密) */
    Char                arcode[64];                   /* [10] 房屋区域层级编码 */
    Char                crk_uuid[36];                 /* [11] crk外键 */
    Char                crk_crkno[52];                /* [12] 出入卡卡号 */
    Int8                flag;                         /* [13] ATTR:AUTO_ON_C(FLAG), AUTO_ON_U(FLAG); flag 导入类型：增｜删｜改，C｜D｜U */
    Int8                sync;                         /* [14] ATTR:AUTO_ON_C(SYNC); 0 未同步; 1 已同步到公共平台 */
} DBM_UserHouse;


typedef struct DBM_AccessRecord
{
    Char                cardno[36];                   /* [00] ? uuid ? 卡号 */
    Char                person_uuid[36];              /* [01] 持卡人uuid */
    Char                mac[32];                      /* [02] 门锁 mac */
    Int8                opentype;                     /* [03] C｜刷卡开门，F｜指纹开门，P｜密码开门，A｜其他开门 */
    Char                area_uuid[36];                /* [04] 门锁所安装区域 uuid */
    Char                slide_date[32];               /* [05] 刷卡时间 */
    Char                cdate[32];                    /* [06] ATTR:AUTO_ON_C(DATETIME), NO_U(DATETIME); */
    Char                dev_uuid[36];                 /* [07] 设备uuid */
    Char                dev_number[36];               /* [08] 设备编号 */
    Char                area_code[64];                /* [09] 区域 层级编码 */
    Char                dev_date[32];                 /* [10] Added as per protocol requirement */
    Int8                flag;                         /* [11] ATTR:AUTO_ON_C(FLAG), AUTO_ON_U(FLAG); flag 导入类型：增｜删｜改，C｜D｜U */
    Int8                sync;                         /* [12] ATTR:AUTO_ON_C(SYNC); 0 未同步; 1 已同步到公共平台 */
} DBM_AccessRecord;


typedef struct DBM_DeviceAlarm
{
    Char                uuid[36];                     /* [00] ATTR:AUTO_ON_C(UUID), NO_U(UUID); 主键（关联表中外键引用） */
    Char                occur_date[32];               /* [01] 告警产生时间 */
    Char                cdate[32];                    /* [02] ATTR:AUTO_ON_C(DATETIME), NO_U(DATETIME); 插入本条记录的时间 */
    Int8                type_;                        /* [03] 告警类型: 强拆 1, 机械钥匙开门 11, 强行闯入 2, 非法刷卡 14 */
    Int8                status;                       /* [04] 告警状态（已处理、未处理） */
    Char                udate[32];                    /* [05] ATTR:AUTO_ON_C(DATETIME), AUTO_ON_U(DATETIME); 告警处理时间 */
    Char                mac[20];                      /* [06] 告警设备的mac */
    Char                area_uuid[36];                /* [07] 告警设备所在区域的uuid */
    Char                account_uuid[36];             /* [08] 告警处理人的uuid */
    Char                device_uuid[36];              /* [09] 告警设备 uuid */
    Char                remark[256];                  /* [10] 处理意见、备注 */
    Char                cardno[36];                   /* [11] ? uuid? 告警非法刷卡卡号 */
    Int8                flag;                         /* [12] ATTR:AUTO_ON_C(FLAG), AUTO_ON_U(FLAG); flag 导入类型：增｜删｜改，C｜D｜U */
    Int8                sync;                         /* [13] ATTR:AUTO_ON_C(SYNC); 0 未同步; 1 已同步到公共平台 */
} DBM_DeviceAlarm;


typedef struct DBM_DeviceStatus
{
    Char                dev_uuid[36];                 /* [00] 设备外键 */
    Int8                status;                       /* [01] 状态 0:脱机 1:联机 */
    Char                hwversion[32];                /* [02] 硬件版本号 */
    Char                sfversion[32];                /* [03] 软件版本号 */
    Char                imsi[32];                     /* [04] 控制器 imsi */
    Char                msisdn[32];                   /* [05] 控制器 msisdn */
    Float32             battery;                      /* [06] 电池百分比 */
    Float32             temperature;                  /* [07] 温度 */
    Float32             signal_;                      /* [08] 信号 */
    Char                udate[32];                    /* [09] ATTR:AUTO_ON_C(DATETIME), AUTO_ON_U(DATETIME); 更新时间 */
    Int32               cardpopedomcapacity;          /* [10] ? 单位? 卡容量 */
    Int32               cardpopedomcount;             /* [11] 门锁白名单数量 */
    Int32               fingercapacity;               /* [12] 指纹容量 */
    Int32               fingercount;                  /* [13] 指纹数 */
    Int8                opened;                       /* [14] 门开关状态 0: 门闭合 1: 门打开 */
    Char                cdate[32];                    /* [15] ATTR:AUTO_ON_C(DATETIME), NO_U(DATETIME); 创建时间 */
    Char                cuser[36];                    /* [16] ? uuid? 创建者 */
    Int8                workmode;                     /* [17] ? 取值 工作状态 */
    Int8                powermode;                    /* [18] ? 取值 电池状态 */
    Int8                flag;                         /* [19] ATTR:AUTO_ON_C(FLAG), AUTO_ON_U(FLAG); flag 导入类型：增｜删｜改，C｜D｜U */
    Int8                sync;                         /* [20] ATTR:AUTO_ON_C(SYNC); 0 未同步; 1 已同步到公共平台 */
} DBM_DeviceStatus;


#endif  /* __DBM_ENTITIES_H__ */

