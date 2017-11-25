#pragma once
#ifndef __OSA_LIST_H__
#define __OSA_LIST_H__

/*
 * Created by Papillon Liu on Nov 17, 2017.
 */



#ifdef __cplusplus
extern "C" {
#endif // __cplusplus


    typedef struct OSA_ListNode {
        struct OSA_ListNode                *pNext;
        struct OSA_ListNode                *pPrev;
    } OSA_ListNode;


    /* static initializer */
    #define OSA_LIST_HEAD_INIT(name)           { &(name), &(name) }

    static inline void OSA_listInit(OSA_ListNode *pHead)
    {
        pHead->pNext = pHead;
        pHead->pPrev = pHead;
    }


    /* insert a node between `pPrev` and `pNext` */
    static inline void OSA_listInsert(OSA_ListNode *pNode, OSA_ListNode *pPrev, OSA_ListNode *pNext)
    {
        pNext->pPrev = pNode;
        pNode->pNext = pNext;
        pNode->pPrev = pPrev;
        pPrev->pNext = pNode;
    }


    /* insert a node just after the head */
    static inline void OSA_listAdd(OSA_ListNode *pNode, OSA_ListNode *pHead)
    {
        OSA_listInsert(pNode, pHead, pHead->pNext);
    }


    /* append to tail (insert a node just before the head) */
    static inline void OSA_lislAppend(OSA_ListNode *pNode, OSA_ListNode *pHead)
    {
        OSA_listInsert(pNode, pHead->pPrev, pHead);
    }
        

    /* delete [0, n] consecutive nodes by skipping them */
    static inline void _OSA_listDel(OSA_ListNode *prev, OSA_ListNode *next)
    {
        next->pPrev = prev;
        prev->pNext = next;
    }
    

    /* delete the specified node from a list */
    static inline void OSA_listDel(OSA_ListNode *pNode)
    {
        _OSA_listDel(pNode->pPrev, pNode->pNext);
        pNode->pNext = pNode;
        pNode->pPrev = pNode;
    }


    static inline void OSAL_listReplace(OSA_ListNode *pOld, OSA_ListNode *pNew)
    {
        pNew->pNext = pOld->pNext;
        pNew->pNext->pPrev = pNew;
        pNew->pPrev = pOld->pPrev;
        pNew->pPrev->pNext = pNew;
    }


    static inline int OSA_listIsEmpty(const OSA_ListNode *pHead)
    {
        return pHead->pNext == pHead;
    }



#ifdef __cplusplus
}
#endif // __cplusplus

#endif  /* __OSA_LIST_H__ */





