// 问题：输出链表的倒数第k个节点，要求只能遍历一次
// 思路：一个指针肯定无法完成，因为这是个单链表，此时可以考虑用两个指针，前面的比后面的多k-1步，前面的到头，后面的刚好就是倒数第k个节点
// 但是要注意考虑边界条件：1、链表为空；2、k = 0；3、k的值大于链表长度，此时可以在前指针首次遍历时进行控制


struct ListNode{
    int m_nValue;
    ListNode* m_pNext;
};

ListNode* FindKthToTail(ListNode* pListHead, unsigned int k){
    if(pListHead == nullptr || k == 0)
        return nullptr;

    ListNode* pAhead = pListHead;
    ListNode* pBehind = nullptr;

    for(unsigned int i=0; i<k-1; i++){
        if(pAhead->m_pNext != nullptr)
            pAhead = pAhead->m_pNext;
        else
            return nullptr;
    }

    pBehind = pListHead;
    while (pAhead->m_pNext != nullptr){
        pAhead = pAhead->m_pNext;
        pBehind = pBehind->m_pNext;
    }

    return pBehind;
}
