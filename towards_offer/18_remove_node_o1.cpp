// 问题：在O(1)时间内删除单链表的节点
// 思路：一个个按顺序找肯定是O(n)，但是可以通过next来找到待删除节点的下个节点值，复制过来，再删掉下个节点即可
// 注意如果待删除节点在末尾，那还是需要一个个找，当然算法整体还是O(1)时间

struct ListNode{
    int m_nValue;
    ListNode* m_pNext;
};

// 往空链表中插入一个节点时，新插入的节点就是链表的头指针
// 由于此时会改动头指针，因此必须把pHead改为指向指针的指针，否则出了这个函数，pHead仍然是空指针
void DeleteNode(ListNode** pListHead, ListNode* pToBeDeleted){
    // 要删除的节点不是尾节点
    if(pToBeDeleted->m_pNext != nullptr){
        ListNode* pNext = pToBeDeleted->m_pNext;
        pToBeDeleted->m_nValue = pNext->m_nValue;
        pToBeDeleted->m_pNext = pNext->m_pNext;

        delete pNext;
        pNext = nullptr;
    } else if (*pListHead == pToBeDeleted) {    // 链表只有一个节点
        delete pToBeDeleted;
        pToBeDeleted = nullptr;
        *pListHead = nullptr;
    } else {    // 要删除的是尾节点
        ListNode* pNode = *pListHead;
        while(pNode->m_pNext != pToBeDeleted) pNode = pNode->m_pNext;

        pNode->m_pNext = nullptr;
        delete pToBeDeleted;
        pToBeDeleted = nullptr;
    }
}
