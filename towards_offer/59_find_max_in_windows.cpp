// 问题1：给定一个数组，以及滑动窗口尺寸，找到每个窗口的最大值
// 思路：通过一个队列来实现，队列里面记录着最大值的index，如果index不在当前窗口，则pop出来
// 

vector<int> maxInWindows(const vector<int>& nums, unsigned int size){
    vector<int> maxInWindows;
    if(nums.size() >= size && size > 0){
        std::deque<int> index;

        for (unsigned int i = 0; i < size; ++i) {
            while (!index.empty() && nums[i] >= nums[index.back()])
                index.pop_back();

            index.push_back(i);
        }

        for(unsigned int i=size; i<nums.size(); ++i){
            maxInWindows.push_back(nums[index.front()]);

            while (!index.empty() && nums[i] >= nums[index.back()])
                index.pop_back();

            if(!index.empty() && index.front() <= (int)(i-size))    // 确保index.front()在当前窗口内
                index.pop_front();

            index.push_back(i);
        }

        maxInWindows.push_back(nums[index.front()]);
    }


    return maxInWindows;
}
