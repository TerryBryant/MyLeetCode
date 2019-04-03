// 问题：将排序后的数组转化为二叉搜索树
// 思路：二叉搜索树的根节点是数组的中位数，根节点的左右子树是数组的中位数两边的元素组成，因此可以用递归来做
//


struct TreeNode{
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode* node(int x): val(x), left(nullptr), right(nullptr) {};
};


TreeNode* convertSortedArrayToBST_core(const vector<int>& nums, int left, int right){
    if(left >= right) return nullptr;
    
    int mid = (left + right) / 2;
    TreeNode* root = new TreeNode(nums[mid]);
    
    root->left = convertSortedArrayToBST_core(nums, left, mid);
    root->right = convertSortedArrayToBST_core(nums, mid+1, right);
    
    return root;
}


TreeNode* convertSortedArrayToBST(const vector<int>& nums){
    return convertSortedArrayToBST_core(nums, 0, nums.size());
}
