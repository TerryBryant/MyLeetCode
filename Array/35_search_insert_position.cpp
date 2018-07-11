// 问题：
// 给定一个排好序的数组，以及一个target，返回target在数组中的位置，如果找不到，则返回应该插入的位置
// 例如输入[1,3,5,6]、5，输出2



// 思路：
// 此题既然是排好序的数组，那么很明显该使用二分查找，算法复杂度为O(log(n))


// 代码：
int searchInsert(vector<int>& nums, int target) {
    int left = 0;
    int right = nums.size() - 1;
    int mid = 0;

    while(left <= right){
        mid = (left + right) / 2;
        if(nums[mid] == target) return mid;
        else if(nums[mid] > target) right = mid - 1;
        else left = mid + 1;
    }

    return left;
}
