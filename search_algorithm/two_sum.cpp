// 问题：
// 给定一个vector<int>，和一个整数val，从vector中找出两个数，使得它们的和为val

// 思路：
// 此题用map或者(set求解，错了，set只有一个值)，可以得到O(n)的算法，注意map.find(key)，是通过key来查找的


// 代码：
vector<int> twoSum(vector<int>& nums, int target) {
    unordered_map<int, int> map;
    for(int i=0; i<nums.size(); i++){
        auto it = map.find(target - nums[i]);

        if(it != map.end())
            return {i, it->second};

        map[nums[i]] = i;
    }

    return {0, 0};
}
