// 问题：给定一个序列，判断它是否为某个二叉搜索树的后序遍历结果
// 思路：考察对BST的理解，左、根、右是逐渐递增的；此外对于后序遍历，根节点在最后
// 两者结合起来，首先找到序列的根节点，然后从序列的左边开始找，小于根节点的为左子树，大于根节点的为右子树
// 再对子树进行递归判断，即可得到最终结果


bool VerifySquenceOfBST(int sequence[], int length){
    if(sequence == nullptr || length <= 0) return false;

    int root = sequence[length - 1];

    // 左子树全部小于根节点
    int i = 0;
    for(; i<length - 1; i++){
        if(sequence[i] > root) break;
    }

    // 右子树全部大于根节点
    int j = i;
    for(;j<length - 1; j++){
        id(sequence[j] < root) return false;
    }

    // 判断左右子树是不是BST
    bool left = ture;
    if(i > 0) left = VerifySquenceOfBST(sequence, i);

    bool right = true;
    if(i < length - 1) right = VerifySquenceOfBST(sequence + i, length - i - 1);

    return left && right;
}
