// 问题：如果一个链表包含环，那么找到环的入口
// 思路：分几个步骤，第一步确定是否有环，第二步找到环的入口
// 针对第一步，可以定义两个指针：快指针每次走两步，慢指针每次走一步。如果存在环，那么在node->next=nullptr之前，快指针就会追上慢指针
// 而且是在慢指针走完一环之前（原因：极端情况下，快慢指针同时从环入口出发，快指针走两圈，即可追上走了一圈的慢指针）

// 针对第二步，如果能知道环的长度，那么可以定义两个指针，让一个指针先走长度这么多的步数，再让另一个指针开始走，两个指针相遇的地方即为环的入口
// 要求环的长度，可以参考第一步里面的返回值，因为返回值在环里面，所以从返回值对应的节点开始，绕一圈就是环的长度了


// 如果有环，那么快指针肯定能追上慢指针，而且是在慢指针还没走完一环的时候就相遇
ListNode* MeetingNode(ListNode* pHead){
    if(pHead == nullptr) return nullptr;

    ListNode* pSlow = pHead->m_pNext;
    if(pSlow == nullptr) return nullptr;

    ListNode* pFast = pSlow->m_pNext;
    while (pFast != nullptr && pSlow != nullptr) {
        if(pFast == pSlow) return pFast;

        pSlow = pSlow->m_pNext;

        pFast = pFast->m_pNext;
        if(pFast != nullptr) pFast = pFast->m_pNext;  // 这里千万要小心
    }

    return nullptr;
}


ListNode* EntryNodeOfLoop(ListNode* pHead){
    ListNode* meetingNode = MeetingNode(pHead);
    if(meetingNode == nullptr) return nullptr;

    // 得到环中节点的数目，即绕环一周
    int nodesInLoop = 1;
    ListNode* pNode1 = meetingNode;
    while (pNode1->m_pNext != meetingNode){
        pNode1 = pNode1->m_pNext;
        nodesInLoop++;
    }

    // 先移动pNode1，次数为nodesInLoop次
    pNode1 = pHead;
    for (int i = 0; i < nodesInLoop; i++) {
        pNode1 = pNode1->m_pNext;
    }

    // 再移动pNode1和pNode2
    ListNode* pNode2 = pHead;
    while (pNode1 != pNode2){
        pNode1 = pNode1->m_pNext;
        pNode2 = pNode2->m_pNext;
    }

    return pNode1;
}
