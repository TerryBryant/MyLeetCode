// 问题：旋转数组，例如输入为[1, 2, 3, 4, 5]，旋转位数k为非负，这里取2，则输出为[4, 5, 1, 2, 3]
// 要求给出尽可能多的解决方法，尝试看有没有in-place算法


// 思路1：这题首先想到的就是新建一个数组，然后根据旋转之后的对应关系，把值放到数组中，最后把数组的值赋给原数组，算法复杂度为O(n)

// 代码1：
void rotate(vector<int>& nums, int k) {
    int N = nums.size();
    k %= N;

    vector<int> tmp(N, 0);        
    for(int i=0; i<N; i++){
        if((i + k) < N)
            tmp[i + k] = nums[i];
        else
            tmp[i + k - N] = nums[i];
    }

    nums.assign(tmp.begin(), tmp.end());
}

// 思路2：肯定有in-place的算法，但是实在想不到了，于是参考了网友的算法。具体就是三次reverse
// 第一次，整个vector进行reverse
// 第二次，从begin到begin+k进行reverse
// 第三次，从begin+k到end进行reverse
// 然后。。就好了，这也太神奇了

// 代码2：
void rotate(vector<int>& nums, int k) {
    int N = nums.size();
    k %= N;
  
    reverse(nums.begin(), nums.end());
    reverse(nums.begin(), nums.begin() + k);
    reverse(nums.begin() + k, nums.end());
}
