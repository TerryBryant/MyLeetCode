// 问题：给定一个二叉树和一个整数，打印出所有路径，该路径需满足：每条路径的和为该整数，且每条路径都是从根节点到叶节点
// 思路：从根节点到叶节点，那么就是前序遍历。对于每条路径，从根节点一直往下遍历，直到叶子节点，如果路径和不是所需要的，那么需要网上退一步
// 再遍历另一条路径，此时需要将原先的路径最后一步去掉，同时把累积的sum减掉当前值，遍历完所有路径即可得到结果
// 明显可以结合栈来操作，但栈不利于打印结果路径，考虑用vector

void FindPathCore(BinaryTreeNode* pRoot, int expectedSum, int currentSum, vector<int>& path){
    currentSum += pRoot->m_nValue;
    path.push_back(pRoot->m_nValue);
    
    // 达到了叶子节点
    bool isLeaf = pRoot->m_pLeft == nullptr && pRoot->m_pRight == nullptr;
    if(isLeaf && currentSum == expectedSum){
        cout<<"Find a path: ";
        for(auto p: path) cout<<p<<" ";
        cout<<endl;
    }
    
    // 不是叶子节点，继续向下遍历
    if(pRoot->m_pLeft != nullptr)
        FindPathCore(pRoot->m_pLeft, expectedSum, currentSum, path);
    if(pRoot->m_pRight != nullptr)
        FindPathCore(pRoot->m_pRight, expectedSum, currentSum, path);
    
    // 遍历到头了，不是所需要的路径
    currentSum -= pRoot->m_nValue;
    path.pop_back();
}


void FindPath(BinaryTreeNode* pRoot, int expectedSum){
    if(pRoot == nullptr) return;
    
    int currentSum = 0;
    vector<int> path;
    FindPathCore(pRoot, expectedSum, currentSum, path);
}
