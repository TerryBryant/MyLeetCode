// 问题：复制复杂链表，该链表除了有m_pNext，还有m_pSilbing，指向任意节点
// 思路：第一步，复制原始节点N，创建新节点N1，把N1接在N后面
// 第二步，参考N的兄弟节点S，给N1也创建兄弟节点S1
// 第三步，整个链表的奇数节点为原始节点，偶数节点即为所求的复制节点，要把两者分开，这一步实在是没看明白，只能说作者太强大

struct ComplexListNode{
    int m_nValue;
    ComplexListNode* m_pNext;
    ComplexListNode* m_pSibling;
};

// 第一步
void CloneNodes(ComplexListNode* pHead){
    ComplexListNode* pNode = pHead;
    while (pNode != nullptr){
        ComplexListNode* pCloned = new ComplexListNode();
        pCloned->m_nValue = pNode->m_nValue;
        pCloned->m_pNext = pNode->m_pNext;
        pCloned->m_pSibling = nullptr;

        pNode->m_pNext = pCloned;

        pNode = pNode->m_pNext;
    }
}

// 第二步
void ConnectSiblingNodes(ComplexListNode* pHead){
    ComplexListNode* pNode = pHead;
    while (pNode != nullptr){
        ComplexListNode* pCloned = pNode->m_pNext;
        if(pNode->m_pSibling != nullptr)
            pCloned->m_pSibling = pNode->m_pSibling->m_pNext;

        pNode = pCloned->m_pNext;
    }
}

// 第三步
ComplexListNode* ReconnectNodes(ComplexListNode* pHead){
    ComplexListNode* pNode = pHead;
    ComplexListNode* pClonedHead = nullptr;
    ComplexListNode* pClonedNode = nullptr;

    if(pNode != nullptr){
        pClonedHead = pClonedNode = pNode->m_pNext;
        pNode->m_pNext = pClonedNode->m_pNext;
        pNode = pNode->m_pNext;
    }

    while (pNode != nullptr){
        pClonedNode->m_pNext = pNode->m_pNext;
        pClonedNode = pClonedNode->m_pNext;
        pNode->m_pNext = pClonedNode->m_pNext;
        pNode = pNode->m_pNext;
    }

    return pClonedHead;
}

ComplexListNode* Clone(ComplexListNode* pHead){
    CloneNodes(pHead);
    ConnectSiblingNodes(pHead);
    ReconnectNodes(pHead);
}
