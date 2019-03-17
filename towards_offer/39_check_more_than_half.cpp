// 问题：数组中某个数字出现的次数超过数组长度的一半，找出该数字
// 思路：定义两个值，一个是数组中的一个数字，另一个是次数，当遍历到下一个数字的时候，如果和上一个数字相同，则次数加一，否则减一
// 某个数字能出现的次数比其它数字出现的总和还多，那么要找的数字肯定是最后一次把次数变为1的那个
// 另外注意边界情况


bool CheckInvalidArray(int* numbers, int length){
    if(numbers == nullptr || length <= 0) return false;
    return true;
}

bool CheckMoreThanHalf(int* numbers, int length, int number){
    int times = 0;
    for (int i = 0; i < length; i++) {
        if(numbers[i] == number)
            times++;
    }

    if(times * 2 < length) return false;

    return true;
}

int MoreThanHalfNum(int* numbers, int length){
    if(! CheckInvalidArray(numbers, length))
        return 0;

    int result = numbers[0];
    int times = 1;

    for(int i=0; i<length; i++){
        if(times == 0){
            result = numbers[i];
            times = 1;  // 多次出现的数字，最后肯定能把其它数字的times清零
        } else if(numbers[i] == result)
            times++;
        else
            times--;
    }

    if(! CheckMoreThanHalf(numbers, length, result))
        result = 0;

    return result;
}
