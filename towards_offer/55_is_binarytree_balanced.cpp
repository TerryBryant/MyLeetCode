// 问题：求二叉树的深度，以及判断二叉树是否为平衡的
// 思路：求深度的思路就是，如果一棵树只有一个节点，那么深度是1，如果有左右子树，那么深度是1+左右子树的深度中的较大者，可以用递归来实现
// 思路：对于判断二叉树是否平衡，可以借助前面的求深度函数，比较左右子树的高度差，同样通过递归实现，但是存在大量的重复计算
// 还有一种通过后序遍历，暂时还是看不懂


int TreeDepth(BinaryTreeNode* pRoot){
    if(pRoot == nullptr) return 0;

    int nLeft = TreeDepth(pRoot->m_pLeft);
    int nRight = TreeDepth(pRoot->m_pRight);

    return 1 + nLeft > nRight ? nLeft : nRight;
}


// 方法一，存在大量重复遍历的情况
bool IsBalanced(BinaryTreeNode* pRoot){
    if(pRoot == nullptr) return true;

    int nLeft = TreeDepth(pRoot->m_pLeft);
    int nRight = TreeDepth(pRoot->m_pRight);
    int diff = nLeft - nRight;
    if(diff > 1 || diff < -1)
        return false;

    return IsBalanced(pRoot->m_pLeft) && IsBalanced(pRoot->m_pRight);
}

// 方法二，采用后序遍历，只需要遍历一遍即可
bool IsBalanced_2(BinaryTreeNode* pRoot, int* pDepth){
    if(pRoot == nullptr){
        *pDepth = 0;
        return true;
    }

    int left, right;
    if(IsBalanced_2(pRoot->m_pLeft, &left) && IsBalanced_2(pRoot->m_pRight, &right)){
        int diff = left - right;
        if(diff <= 1 && diff >= -1){
            *pDepth = 1 + (left > right ? left : right);
            return true;
        }
    }

    return false;
}

bool IsBalanced_2(BinaryTreeNode* pRoot){
    int depth = 0;
    return IsBalanced_2(pRoot, &depth);
}
