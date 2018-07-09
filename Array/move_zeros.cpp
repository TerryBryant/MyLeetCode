// 问题：
// 给定一个数组，将数组中的所有0元素移到末尾
// 要求in-place


// 思路：
// 肯定有O(n)的算法，至少想不到怎么写，只能参考强大的网友们。。

// 代码
void moveZeroes(vector<int>& nums) {
    int j = 0;
    int N = nums.size();
    for(int i=0; i<N; i++){
        if(nums[i] != 0)
            nums[j++] = nums[i];
    }

    for(; j<N; j++)
        nums[j] = 0;
}
