// 问题：合并两个递增的链表
// 思路：主要是对比两个节点的大小，考虑用递归的方法
// 此题思路较简单，但要具备现场写出鲁棒代码的能力


ListNode* MergeTwoIncreasingLists(ListNode* pHead1, ListNode* pHead2){
    if(pHead1 == nullptr) return pHead2;
    if(pHead2 == nullptr) return pHead1;

    ListNode* pMergedHead = nullptr;
    if(pHead1->m_nValue < pHead2->m_nValue){
        pMergedHead = pHead1;
        pMergedHead->m_pNext = MergeTwoIncreasingLists(pHead1->m_pNext, pHead2);
    }
    else{
        pMergedHead = pHead2;
        pMergedHead->m_pNext = MergeTwoIncreasingLists(pHead1, pHead2->m_pNext);
    }

    return pMergedHead;
}
