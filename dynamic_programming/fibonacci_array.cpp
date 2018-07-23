#include <iostream>
#include <vector>
using namespace std;

// 第一种，最原始的递归写法，时间复杂度为O(2^n)
int fibonacci(int N){
    if((N == 1) || (N == 2)) return 1;
    return fibonacci(N - 1) + fibonacci(N - 2);
}

// 第二种，采用动态规划的递归写法，时间复杂度为O(n)
int dynamic_program(int N, vector<int>& memo){
    if(memo[N] != 0) return memo[N];

    int result = 0;
    if((N == 1) || (N == 2))
        result = 1;
    else
        result = dynamic_program(N-1, memo) + dynamic_program(N-2, memo);

    memo[N] = result;

    return result;
}

// 第三种，采用一种叫做bottom up的动态规划算法，时间复杂度也为O(n)，但避免了递归
int fib_bottom_up(int N){
    if((N == 1) || (N == 2)) return 1;

    vector<int> bottom_up(N + 1, 0);
    bottom_up[0] = 1;
    bottom_up[1] = 1;

    for(int i=2; i<N+1; i++)
        bottom_up[i] = bottom_up[i-1] + bottom_up[i-2];

    return bottom_up[N];
}

int main() {
    clock_t begin_time = clock();
    for(int i=1; i< 40; i++)
        cout<<fibonacci(i)<<" ";
    cout << endl;
    cout << "Recursion takes: " << float(clock() - begin_time) / CLOCKS_PER_SEC << "s" << endl;

    cout << "-------------------------------------" << endl;
    begin_time = clock();
    vector<int> v(40, 0);
    for(int i=1; i< 40; i++)
        cout<<dynamic_program(i, v)<<" ";
    cout << endl;
    cout << "Dynamic programming takes: " << float(clock() - begin_time) / CLOCKS_PER_SEC << "s" << endl;

    cout << "-------------------------------------" << endl;
    begin_time = clock();
    for(int i=1; i< 40; i++)
        cout<<fib_bottom_up(i)<<" ";
    cout << endl;
    cout << "Dynamic programming(bottom up) takes: " << float(clock() - begin_time) / CLOCKS_PER_SEC << "s" << endl;

    return 0;
}

// 输出结果如下
//1 1 2 3 5 8 13 21 34 55 89 144 233 377 610 987 1597 2584 4181 6765 10946 17711 28657 46368 75025 121393 196418 317811 514229 832040 1346269 2178309 3524578 5702887 9227465 14930352 24157817 39088169 63245986 
//Recursion takes: 0.598452s
//-------------------------------------
//1 1 2 3 5 8 13 21 34 55 89 144 233 377 610 987 1597 2584 4181 6765 10946 17711 28657 46368 75025 121393 196418 317811 514229 832040 1346269 2178309 3524578 5702887 9227465 14930352 24157817 39088169 63245986 
//Dynamic programming takes: 5e-06s
//-------------------------------------
//1 1 3 5 8 13 21 34 55 89 144 233 377 610 987 1597 2584 4181 6765 10946 17711 28657 46368 75025 121393 196418 317811 514229 832040 1346269 2178309 3524578 5702887 9227465 14930352 24157817 39088169 63245986 102334155 
//Dynamic programming(bottom up) takes: 2e-05s
// 算法的力量啊。。。
