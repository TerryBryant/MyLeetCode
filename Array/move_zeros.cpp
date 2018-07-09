// 问题：
// 给定一个数组，将数组中的所有0元素移到末尾，例如输入[0,1,0,3,12]，输出[1,3,12,0,0]
// 要求in-place


// 思路：
// 肯定有O(n)的算法，至少想不到怎么写，只能参考强大的网友们。。
// 用一个标志位j，遍历数组，每当遇到非零元素时，先将该元素与nums[j]互换，再让j加一，确保非零元素的连续性
// 最后一定要加上nums[j] = 0的循环，因为后面的元素可能为非零（已经被移到前面去了）
// 不得不说方法非常优雅，可我就是想不到该怎么写

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
