// 问题1：找出数组中只出现一次的两个数字，其它数字都出现了两次
// 思路：任何一个数字，异或自己都为0，所有如果该数组里面只有一个数字出现一次，那么把整个数组异或一遍就可以找到它了
// 现在要找的是两个数字，那么如果能把数组分为两组，每组包含一个只重复一次的数字，按前面的方法也就能得到结果了
// 现在关键在于如何划分两组，考虑整个数组异或一遍，最终肯定能得到一个非零值，因为有两个不一样的数字，
// 借助这个非零值，针对它的二进制形式，从右往左找到第一个为1的位，根据这个位即可将原始数组分为两组，一组含有1，一组不含1
// 因为两个相同的数，二进制形式完全一致，所以会被分到同一组


// 判断二进制的num，从右数第index位置是否为1
bool IsBit1(int num, unsigned int index){
    num = num >> index;
    return (num & 1);
}


// 找到最右边为1的位置
unsigned int FindFirstBits1(int num){
    int index = 0;
    while (((num & 1) == 0) && (index < 8 * sizeof(int))) {
        num = num >> 1;
        ++index;
    }

    return index;
}


void FindNumsAppearOnce(int data[], int length, int* nums1, int* nums2){
    if(data == nullptr || length < 2) return;

    int resultExclusiveOR = 0;
    for(int i=0; i<length; ++i)
        resultExclusiveOR ^= data[i];

    unsigned int indexOf1 = FindFirstBits1(resultExclusiveOR);

    *nums1 = *nums2 = 0;
    for (int j = 0; j < length; ++j) {
        if(IsBit1(data[j], indexOf1))
            *nums1 ^= data[j];
        else
            *nums2 ^= data[j];
    }
}

// 问题2：找到数组中唯一出现一次的数字，数组中其它的数字都出现了三次
// 思路：此时不能再用异或了，因为三次异或就变成自己了，此时可以考虑位运算，出现三次，那么将相应的位进行累加，肯定可以被3整除
// 利用这一思路，将整个数组进行累加，得到一个长度为32的数组，再分别对3进行求余，即可得到结果

int FindNumberAppearingOnce3(int numbers[], int length){
    if(numbers == nullptr || length <= 0)
        throw std::exception();

    int bitSum[32] = {0};  // 整型一共32位
    for (int i = 0; i < length; ++i) {
        int bitMask = 1;
        for (int j = 31; j >= 0; --j) {     // 高位到低位
            int bit = numbers[i] & bitMask;
            if(bit != 0)
                bitSum[j] += 1;
            
            bitMask = bitMask << 1;
        }
    }

    int result = 0;
    for (int i = 0; i < 32; ++i) {
        result = result << 1;
        result += bitSum[i] % 3;
    }

    return result;
}
