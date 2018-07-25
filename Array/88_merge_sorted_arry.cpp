// 问题：合并两个排好序的数组（升序），例如输入
// nums1 = [1,2,3,0,0,0], m = 3
// nums2 = [2,5,6], n = 3
// 那么应该输出nums1 = [1,2,2,3,5,6]，且这里假设nums1足够长


// 思路：这题能想到就是逐个比较两个数组里面的元素，谁小选谁，一路移动指针，但就是不会写！！！代码功底还是太薄弱
// 这里直接参考了网友的方法，不得不说很巧妙，而且一看就懂了


// 代码：
void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
    int i = m - 1;
    int j = n - 1;
    int tar = m + n - 1;

    while(j >= 0){
        nums1[tar--] = i>=0 && nums1[i]>nums2[j] ? nums1[i--]: nums2[j--];
    }
}
