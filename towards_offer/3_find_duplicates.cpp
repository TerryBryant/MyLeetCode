// 问题：一个长度为n的数组，数字都在0~n-1范围内，找出其中重复的数字
// 思路：很easy，申请一个长度为n的数组，全部置为0，再遍历原始数组，根据下标来++
// 代码：
vector<int> findDuplicates(vector<int> nums){
    vector<int> res;
    vector<int> tmp(nums.size(), 0);
    for(size_t i=0; i<nums.size(); i++){
        tmp[nums[i]]++;
    }
    
    for(size_t i=0; i<nums.size(); i++){
        if(tmp[i] > 1) res.emplace_back(i);
    }
    
    return res;
}



// 思路2：以上方法虽然时间复杂度是O(n)，但是需要额外申请内存，书上给出了更强大的in-place算法。
// 从头到尾遍历数组，当扫描到下标为i的数字时（值为m），先拿该数字和i比较，如果相同则继续，如果不同，则拿它和第m个数字对比
// 如果相同则找到了重复数字，如果不同则把它们交换，并重复交换的过程，直至
// 代码：
vector<int> findDuplicates(vector<int> nums){
    vector<int> res;
    for(size_t i=0; i<nums.size(); i++){
        if(nums[i] != i){
            if(nums[i] == nums[nums[i]]){
                res.emplace_back(nums[i]);    
            }
            else{
                // 不相等，则进行交换
                int temp = nums[i];
                nums[i] = nums[nums[i]];
                nums[nums[i]] = temp;
            }
        }
    }
    
    return res;
}
