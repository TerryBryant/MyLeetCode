// 问题：求数组的最大子列和
// 思路：这个问题碰到很多次了，定义一个curSum和maxSum，当curSum小于0时开始舍弃，当curSum大于maxSum，替换掉maxSum的值
//

int FindGreatestSumOfSubArray(int* pData, int nLength){
    if(pData == nullptr || nLength <= 0){
        cout<<"Invalid Input"<<endl;
        return -1;
    }

    int nCurSum = 0;
    int nGreatestSum = pData[0];
    for (int i = 0; i < nLength; i++) {
        if(nCurSum <= 0)
            nCurSum = pData[i];
        else
            nCurSum += pData[i];

        if(nCurSum > nGreatestSum)
            nGreatestSum = nCurSum;
    }

    return nGreatestSum;
}
