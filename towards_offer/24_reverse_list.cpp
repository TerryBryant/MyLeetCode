// 翻转链表，例如u -> v -> w，变成u <- v <- w
// 思路，直接把u和v进行翻转，那么w会断掉，所以第一步是保存w
// 第二步是把u作为v的下一个节点
// 第三步是把v作为（下一轮）的前一个节点
// 最后一步是吧w作为（下一轮）的当前节点
// 当碰到w = nullptr时，说明到了链表的尾部
// 感觉还是不太理解，还需要花时间看


struct ListNode{
    int m_nValue;
    ListNode* m_pNext;
};

ListNode* ReverseList(ListNode* pHead){
    ListNode* pReversedHead = nullptr;
    ListNode* pNode = pHead;
    ListNode* pPrev = nullptr;

    while(pNode != nullptr){
        ListNode* pNext = pNode->m_pNext;
        if(pNext == nullptr) pReversedHead = pNode;

        pNode->m_pNext = pPrev;
        pPrev = pNode;
        pNode = pNext;
    }

    return pReversedHead;
}
