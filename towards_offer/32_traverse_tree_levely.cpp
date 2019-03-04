// 问题：从上到下遍历二叉树
// 思路：此题主要利用队列的先入先出特性，从左至右遍历tree的时候，左边的节点先入队列，先打印出来


void PrintFromTopToBottom(BinaryTreeNode* pTreeRoot){
    if(!pTreeRoot) return;

    std::deque<BinaryTreeNode*> dequeTreeNode;

    dequeTreeNode.push_back(pTreeRoot);
    while (dequeTreeNode.size()){
        BinaryTreeNode* pNode = dequeTreeNode.front();
        dequeTreeNode.pop_front();

        cout<<pNode->m_nValue<<" ";

        if(pNode->m_pLeft) dequeTreeNode.push_back(pNode->m_pLeft);
        if(pNode->m_pRight) dequeTreeNode.push_back(pNode->m_pRight);
    }
}
