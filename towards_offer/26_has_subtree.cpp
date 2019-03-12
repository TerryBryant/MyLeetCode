// 问题：判断某棵树是否为另一棵树的子树
// 思路：通过根节点来进行比较，根节点相同，再比较左右节点，如果根节点不同，那么再向下遍历根节点，用递归即可

// 第二步判断，叶子是否相同
bool DoesTree1HaveTree2(BinaryTreeNode* pRoot1, BinaryTreeNode* pRoot2){
    if(pRoot2 == nullptr) return true;

    if(pRoot1 == nullptr) return false;

    if(pRoot1->m_nValue != pRoot2->m_nValue)
        return false;

    return DoesTree1HaveTree2(pRoot1->m_pLeft, pRoot2->m_pLeft) &&
    DoesTree1HaveTree2(pRoot1->m_pRight, pRoot2->m_pRight);
}


// 第一步判断，根节点是否相同
bool HasSubtree(BinaryTreeNode* pRoot1, BinaryTreeNode* pRoot2){
    bool result = false;

    if(pRoot1 != nullptr && pRoot2 != nullptr){
        if(pRoot1->m_nValue == pRoot2->m_nValue)
            result = DoesTree1HaveTree2(pRoot1, pRoot2);

        if(!result)
            result = HasSubtree(pRoot1->m_pLeft, pRoot2);

        if(!result)
            result = HasSubtree(pRoot1->m_pRight, pRoot2);
    }

    return result;
}
