// 问题：寻找旋转数组的最小值，例如{3,4,5,1,2}是{1,2,3,4,5}的旋转数组
// 思路：跟二分查找一样，设置left、right和mid，当mid所指数字大于left，则left右移动；当mid所指小于right，则right左移
// 当left和right相邻时，停止循环，right所指则为所求
// 需要注意left、right和mid所指相等的情况，此时需要顺序查找

int MinInOrder(std::vector<int> nums, int left, int right){
    int result = nums[left];
    for(int i=left+1; i<=right; i++){
        if(result > nums[i]) result = nums[i];
    }

    return result;
}


in FindMinBinary(std::vector<int> nums){
    int length = nums.size();
    if(length <= 0)
        throw new std::exception("Invalid parameters");

    int left = 0, right = length - 1;
    int mid = left;   // 当搬移的是第0个元素，则可以直接返回

    while (nums[left] >= nums[right]){
        if(right - left == 1){
            mid = right;
            break;
        }

        mid = (left + right) / 2;

        if(nums[left] == nums[right] && nums[left] == nums[mid])
            return MinInOrder(nums, left, right);// left、right、mid指向的数字相等，只能顺序查找

        if(nums[mid] >= nums[left]) left = mid;
        else if(nums[mid] <= nums[right]) right = mid;
    }

    return nums[mid];
}
