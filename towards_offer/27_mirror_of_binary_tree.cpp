// 问题：求二叉树的镜像
// 思路：画出某个二叉树的镜像，发现除了根节点，其它子节点依次交换即可，通过递归即可轻松实现


void MirrorRecursively(BinaryTreeNode* pHead){
    if(pHead == nullptr) return;
    
    if(pHead->m_pLeft == nullptr && pHead->m_pRight == nullptr) return;
    
    BinaryTreeNode* pTemp = pHead->m_pLeft;
    pHead->m_pLeft = pHead->m_pRight;
    pHead->m_pRight = pTemp;
    
    if(pHead->m_pLeft) MirrorRecursively(pHead->m_pLeft);
    if(pHead->m_pRight) MirrorRecursively(pHead->m_pRight);
}
