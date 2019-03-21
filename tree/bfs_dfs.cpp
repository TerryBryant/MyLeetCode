// 树的bfs和dfs遍历
// 注意bfs遍历的时候，遵循先入先出，所以要用队列；dfs的时候，需要回溯，所以要用堆栈
// 代码还是很简单的，两者的代码格式都是一样，但一定要搞清楚遍历的流程

struct BinaryTreeNode{
    int m_nValue;
    BinaryTreeNode* m_pLeft;
    BinaryTreeNode* m_pRight;
};

void treeBFS(BinaryTreeNode* root){
    std::queue<BinaryTreeNode*> nodeQueue;
    nodeQueue.push(root);
    BinaryTreeNode* node = nullptr;
    while (!nodeQueue.empty()){
        node = nodeQueue.front();
        nodeQueue.pop();
        cout<<node->m_nValue<<" ";

        if(node->m_pLeft)
            nodeQueue.push(node->m_pLeft);
        if(node->m_pRight)
            nodeQueue.push(node->m_pRight);
    }
}

void treeDFS(BinaryTreeNode* root){
    std::stack<BinaryTreeNode*> nodeStack;
    nodeStack.push(root);
    BinaryTreeNode* node = nullptr;
    while (!nodeStack.empty()){
        node = nodeStack.top();
        nodeStack.pop();
        cout<<node->m_nValue<<" ";

        if(node->m_pLeft)
            nodeStack.push(node->m_pLeft);
        if(node->m_pRight)
            nodeStack.push(node->m_pRight);
    }
}
