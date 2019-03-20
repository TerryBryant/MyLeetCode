// 问题：找到第1500个丑数，丑数指只包含2、3和5的因子，1是第一个丑数
// 思路：最直观的就是逐个判断了，但是运算量太大了。其实可以只考虑丑数，例如求出前面几个丑数1, 2, 3, 4, 5...然后根据这些数计算下一个丑数
// 为了保存这些数，需要申请数组，所谓以空间换取时间



// 方法1，逐个判断
bool isUgly(int number){
    while (number % 2 == 0)
        number /= 2;

    while (number % 3 == 0)
        number /= 3;

    while (number % 5 == 0)
        number /= 5;

    return (number == 1) ? true: false;
}

int GetUglyNumber(int index){
    if(index <= 0) return 0;

    int number = 0;
    int uglyfound = 0;
    while (uglyfound < index){
        number++;
        if(isUgly(number))
            uglyfound++;
    }

    return number;
}


// 方法2，只考虑丑数
int Min(int num1, int num2, int num3){
    int min = num1 < num2 ? num1 : num2;
    min = min < num3 ? min : num3;

    return min;
}

int GetUglyNumber_2(int index){
    if(index <= 0) return 0;

    int* pUglyNumbers = new int[index];
    pUglyNumbers[0] = 1;
    int nextUglyIndex = 1;

    int* pMultiply2 = pUglyNumbers;
    int* pMultiply3 = pUglyNumbers;
    int* pMultiply5 = pUglyNumbers;

    while (nextUglyIndex < index){
        int min = Min(*pMultiply2 * 2, *pMultiply3 * 3, *pMultiply5 * 5);
        pUglyNumbers[nextUglyIndex] = min;

        while (*pMultiply2 * 2 <= pUglyNumbers[nextUglyIndex])
            pMultiply2++;
        while (*pMultiply3 * 3 <= pUglyNumbers[nextUglyIndex])
            pMultiply3++;
        while (*pMultiply5 * 5 <= pUglyNumbers[nextUglyIndex])
            pMultiply5++;

        nextUglyIndex++;
    }

    int ugly = pUglyNumbers[index - 1];
    delete[] pUglyNumbers;
    return ugly;
}
