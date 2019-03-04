// 问题：经典的斐波那契数列
// 思路：用递归的方法，可能使程序的堆栈爆掉，使用循环的方法更合理


long long Fibonacci_recursively(unsigned int n){
    if(n <= 0) return 0;
    if(n == 1) return 1;

    return Fibonacci(n - 1) + Fibonacci( n - 2);
}

long long Fibonacci(unsigned int n){
    if(n <= 0) return 0;
    if(n == 1) return 1;
    
    long long f1 = 0;
    long long f2 = 1;
    long long res = 0;
    for(int i=2; i<n; i++){
        res  = f1 + f2;
        f1 = f2;
        f2 = res;
    }

    return res;
}
