// 问题：获取二叉树中序遍历的下一个节点
// 思路：深入理解中序遍历，它的下一个节点要么是父节点，要么是右节点
// 当右节点不为空时，一直找到右子树的最左子节点即可
// 当父节点不为空时（此时右节点为空），如果父节点是上一层节点的左子节点，那么上一层的根节点即为所求
// 当父节点不为空时（此时右节点为空），如果父节点是右子节点，那么一直往上遍历，直到找到父节点为左子节点的情况，否则就返回根节点

struct BinaryTreeNode{
    int m_nValue;
    BinaryTreeNode* m_pLeft;
    BinaryTreeNode* m_pRight;
    BinaryTreeNode* m_pParent;
};

BinaryTreeNode* GetNext(BinaryTreeNode* pNode){
    if(pNode == nullptr) return nullptr;

    BinaryTreeNode* pNext = nullptr;

    // 右子树不为空，则找到右子树的最左子树
    if(pNode->m_pRight != nullptr){
        BinaryTreeNode* pRight = pNode->m_pRight;
        while (pRight->m_pLeft != nullptr)
            pRight = pRight->m_pLeft;

        pNext = pRight;
    }
    else if(pNode->m_pParent != nullptr){   // 右子树为空，通过父节点来找下一个节点
        BinaryTreeNode* pCurrent = pNode;
        BinaryTreeNode* pParent = pNode->m_pParent;
        while(pParent != nullptr && pCurrent == pParent->m_pRight){
            pCurrent = pParent;
            pParent = pParent->m_pParent;
        }

        pNext = pParent;
    }

    return pNext;
}
