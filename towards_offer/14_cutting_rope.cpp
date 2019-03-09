// 问题：长度为n的绳子，剪成m段（n>1, m>1），求每段绳子长度相乘，最大能到多少
// 思路：此题考察的是动态规划算法以及贪婪算法
// 动态规划：找到递推公式，定义f(n)为长度为n的绳子能得到的最大乘积，那么f(n)=max(f(i)*f(n-i)), i=1...n-1
// 贪婪算法：其实就是每一步找到最优解，当n>=5时，应该尽可能剪成长度为3的绳子，当剩下长度为4时，改成2*2的绳子


int maxProductAfterCutting_dp(int length){
    if(length < 2) return 0;
    if(length == 2) return 1;
    if(length == 3) return 2;

    int* products = new int[length + 1];
    products[0] = 0;
    products[1] = 1;
    products[2] = 2;
    products[3] = 3;    //这里要特别理解，在绳子长度为4时，只能有1*3和2*2两种剪法

    int max = 0;
    for(int i=4; i<=length; i++){
        max = 0;
        for(int j=1; j<=i / 2; j++){
            int product = products[j] * products[i - j];
            if(max < product) max = product;

            products[i] = max;
        }
    }

    max = products[length];

    delete[] products;
    return max;
}


int maxProductAfterCutting_greedy(int length){
    if(length < 2) return 0;
    if(length == 2) return 1;
    if(length == 3) return 2;

    // 当length>=5时，尽可能剪到长度为3的段
    int timesOf3 = length / 3;

    // 如果剪到最后的长度为4，那么不能再剪到3了，改成2*2
    if(length - timesOf3 * 3 == 1) timesOf3 -= 1;

    int timesOf2 = (length - timesOf3 * 3) / 2;

    return (int)(pow(3, timesOf3) * pow(2, timesOf2));
}
