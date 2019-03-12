// 问题：将一个数组中的奇数放在前面，偶数放在后面
// 思路：类似于快排，维持两个指针，从两端开始遍历


bool isEven(int n){
    return (n & 0x1) == 0;
}

void Reorder(int* pData, unsigned int length, bool (*func)(int)){
    if(pData == nullptr || length == 0) return;

    int* pBegin = pData;
    int* pEnd = pData + length - 1;

    while (pBegin < pEnd) {
        while (pBegin < pEnd && func(*pBegin) != 0)
            pBegin++;

        while (pBegin < pEnd && func(*pEnd) == 0)
            pEnd--;

        if(pBegin < pEnd){
            int temp = *pBegin;
            *pBegin = *pEnd;
            *pEnd = temp;
        }
    }
}

void ReorderOddEven(int* pData, unsigned int length){
    Reorder(pData, length, isEven);
}
