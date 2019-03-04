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

// 拓展：在前面的基础上，“Z字”打印二叉树，即每两行之间的打印顺序相反
// 思路：整体流程与前面一致，只是打印的时候要有一个bool量来控制顺序，另外要记录每一行的行数，以此来计算打印的值

void zigzagLevelOrder(BinaryTreeNode* root){
    if(!root) return;

    std::queue<BinaryTreeNode*> nodesQueue;
    nodesQueue.push(root);

    bool leftToRight = true;

    while (!nodesQueue.empty()){
        int size = nodesQueue.size();
        vector<int> row(size, 0);

        for(int i=0; i<size; i++){
            BinaryTreeNode* node = nodesQueue.front();
            nodesQueue.pop();

            int index = leftToRight ? i : (size - 1 - i);   // 关键在这一行

            row[index] = node->m_nValue;

            if(node->m_pLeft) nodesQueue.push(node->m_pLeft);
            if(node->m_pRight) nodesQueue.push(node->m_pRight);
        }

        // after this level
        leftToRight = ! leftToRight;
        for(auto& r : row) cout<<r<<" ";
    }
}
