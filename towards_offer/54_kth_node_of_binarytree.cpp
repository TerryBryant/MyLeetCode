// 问题：找出二叉搜索树的第K大节点
// 思路：二叉搜索树的中序遍历即为排好序的结果，所以此题就是考察中序遍历的
// 

const BinaryTreeNode* KthNodeCore(BinaryTreeNode* pRoot, unsigned int &k){
    const BinaryTreeNode* target = nullptr;

    if(pRoot->m_pLeft != nullptr)
        target = KthNodeCore(pRoot->m_pLeft, k);

    if(target == nullptr){
        if(k == 1)
            target = pRoot;
        k--;
    }

    if(target == nullptr && pRoot->m_pRight != nullptr)
        target = KthNodeCore(pRoot->m_pRight, k);

    return target;
}


const BinaryTreeNode* KthNode(BinaryTreeNode* pRoot, unsigned int k){
    if(pRoot == nullptr || k == 0) return nullptr;

    return KthNodeCore(pRoot, k);
}

BinaryTreeNode* CreateBinaryTreeNode(int val){
    BinaryTreeNode* pNode = new BinaryTreeNode();
    pNode->m_nValue = val;
    pNode->m_pLeft = nullptr;
    pNode->m_pRight = nullptr;
}

void ConnectTreeNodes(BinaryTreeNode* pParent, BinaryTreeNode* pLeft, BinaryTreeNode* pRight){
    if(pParent != nullptr){
        pParent->m_pLeft = pLeft;
        pParent->m_pRight = pRight;
    }
}


int main(){
    BinaryTreeNode* pNode8 = CreateBinaryTreeNode(8);
    BinaryTreeNode* pNode6 = CreateBinaryTreeNode(6);
    BinaryTreeNode* pNode10 = CreateBinaryTreeNode(10);
    BinaryTreeNode* pNode5 = CreateBinaryTreeNode(5);
    BinaryTreeNode* pNode7 = CreateBinaryTreeNode(7);
    BinaryTreeNode* pNode9 = CreateBinaryTreeNode(9);
    BinaryTreeNode* pNode11 = CreateBinaryTreeNode(11);

    ConnectTreeNodes(pNode8, pNode6, pNode10);
    ConnectTreeNodes(pNode6, pNode5, pNode7);
    ConnectTreeNodes(pNode10, pNode9, pNode11);

    const BinaryTreeNode* node = KthNode(pNode8, 2);


    return 1;
}
