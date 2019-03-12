// 问题：判断二叉树是否为对称，即二叉树的镜像是不是和自身一样
// 思路：二叉树的前序遍历，按先左子树后右子树，以及先右子树后左子树，两种方式得到的结果一模一样，则为对称的
// 注意当二叉树的值都相等时，会出现问题，此时应将节点等于nullptr的情况也考虑进来

bool isSymmetricalCore(BinaryTreeNode* pRoot1, BinaryTreeNode* pRoot2){
    if(pRoot1 == nullptr && pRoot2 == nullptr) return true;
    if(pRoot1 == nullptr || pRoot2 == nullptr) return false;
    
    if(pRoot1->m_nValue != pRoot2->m_nValue) return false;
    
    return isSymmetricalCore(pRoot1->m_pLeft, pRoot2->m_pRight) &&
    isSymmetricalCore(pRoot1->m_pRight, pRoot2->m_pLeft);
}

bool isSymmetricalCore(BinaryTreeNode* pRoot){
    return isSymmetricalCore(pRoot, pRoot);
}
