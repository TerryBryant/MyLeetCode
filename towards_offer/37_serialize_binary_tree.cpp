// 问题：序列化和反序列化二叉树
// 思路：前序遍历即可进行序列化，但需要将空节点用特殊字符进行填充，才能在反序列化的时候进行恢复


void Serialize(BinaryTreeNode* pRoot, std::ostream& stream){
    if(pRoot == nullptr){
        stream << "$";
        return;
    }

    stream << pRoot->m_nValue << ',';
    Serialize(pRoot->m_pLeft, stream);
    Serialize(pRoot->m_pRight, stream);
}

bool ReadStream(std::istream& stream, int* number){
    std::string s;
    stream >> s;

    if(atoi(s.c_str()) == 10)   //数字则返回true
        return true;

    return false;
}

void Deserialize(BinaryTreeNode** pRoot, std::istream& stream){
    int number;
    if(ReadStream(stream, &number)){
        *pRoot = new BinaryTreeNode();
        (*pRoot)->m_nValue = number;
        (*pRoot)->m_pLeft = nullptr;
        (*pRoot)->m_pRight = nullptr;

        Deserialize(&((*pRoot)->m_pLeft), stream);
        Deserialize(&((*pRoot)->m_pRight), stream);
    }
}
