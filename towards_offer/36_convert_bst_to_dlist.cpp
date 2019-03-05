// 问题：将二叉搜索树转换成有序的双向链表
// 思路：二叉搜索树的中序遍历即为一个有序的数组，所以可以不新建节点，即可完成转换过程
// 想清楚了，但是代码还是不会写，也没看明白。。

struct BinaryTreeNode{
    int m_nValue;
    BinaryTreeNode* m_pLeft;
    BinaryTreeNode* m_pRight;
};


void ConvertNode(BinaryTreeNode* pNode, BinaryTreeNode** pLastNodeInList){
    if(pNode == nullptr) return;

    BinaryTreeNode* pCurrent = pNode;

    if(pCurrent->m_pLeft != nullptr) ConvertNode(pCurrent->m_pLeft, pLastNodeInList);

    pCurrent->m_pLeft = *pLastNodeInList;
    if(*pLastNodeInList != nullptr) (*pLastNodeInList)->m_pRight = pCurrent;

    *pLastNodeInList = pCurrent;
    if(pCurrent->m_pRight != nullptr) ConvertNode(pCurrent->m_pRight, pLastNodeInList);
}

BinaryTreeNode* Convert(BinaryTreeNode* pRootOfTree){
    BinaryTreeNode* pLastNodeInList = nullptr;

    ConvertNode(pRootOfTree, &pLastNodeInList); // 经过该函数处理，左子树都已经转换好了，右子树不用转换，只需要把最左节点接上即可

    // pLastNodeInList指向双向链表的尾节点，需返回头节点
    BinaryTreeNode* pHeadOfList = pLastNodeInList;
    while (pHeadOfList != nullptr && pHeadOfList->m_pLeft != nullptr)
        pHeadOfList = pHeadOfList->m_pLeft;

    return pHeadOfList;
}
