// 经典的二分查找算法，适用于递增数组
int BinarySearch(vector<int> nums, int N){
    int left = 0, right = nums.size() - 1;
    int mid = 0;
    
    while(left <= right){
        mid = (left + right) / 2;
        if(nums[mid] < N) left = mid + 1;
        else if(nums[mid] > N) right = mid - 1;
        else return mid;
    }
    
    return -1;
}

// 拓展：一个先增后减的数组，例如1, 3, 5, 4, 2，找最大值
int BinarySearch_2(vector<int> nums){
    int left = 0, right = nums.size() - 1;
    int mid = 0;
    
    while(left <= right){
        mid = (left + right) / 2;
        if(nums[mid] < nums[mid+1]) left = mid + 1;
        else if(nums[mid] < nums[mid-1]) right = mid - 1;
        else break;
    }
    
    return mid;
}
