// 问题1：给定一个递增的数组，求出和为s的两个数字
// 思路：利用好递增这一条件，选定两个指针，分别指向数组的头和尾，两者的和如果大于s，则头指针前进
//

bool FindNumbersWithSum(int data[], int length, int sum, int* num1, int* num2){
    if(data == nullptr || length <= 0) return false;

    bool found = false;
    int left = 0;
    int right = length - 1;

    while (left < right){
        long long curSum = data[left] + data[right];

        if(curSum == sum){
            *num1 = data[left];
            *num2 = data[right];
            found = true;
            break;
        } else if (curSum > sum)
            right--;
        else
            left++;
    }

    return found;
}


// 问题2：求出和为s的正数序列，注意这个序列是1,2,3,4...这种
// 思路：可以参考上面的思路，定义一个small和big，分别指向第一、二个数，如果small+big小于s，那么big++，如果大于s了，那么small++
// 然后继续往后面遍历，知道small大于big为止

void FindContinuousSequence(int sum){
    if(sum < 3) return;

    int small = 1;
    int big = 2;
    int middle = (1 + sum) / 2;
    int curSum = small + big;

    while (small < big) {
        if(curSum == sum)
            PrintContinuousSequence(small, big);

        while (curSum > sum && small < middle){
            curSum -= small;
            small++;

            if(curSum == sum)
                PrintContinuousSequence(small, big);
        }

        big++;
        curSum += big;
    }
}
