// 问题：求一个数的n次方
// 思路：这题很简单，但是需要注意输入的数为0，以及n为负数时的情况
// 最高效的方法是将n变成两个n/2，然后递归求解，见double Power_2(double base, int exponent)


bool g_InvalidInput = false;


double PowerWithUnsignedExponent(double base, unsigned int exponent){
    double result = 1.0;
    for(int i=1; i<=exponent; i++) result *= base;

    return result;
}

double Power(double base, int exponent){
    g_InvalidInput = false;

    if(fabs(base) < 1e-6 && exponent < 0){
        g_InvalidInput = true;
        return 0.0;
    }

    unsigned int absExponent = (unsigned int) exponent;
    if(exponent < 0) absExponent = (unsigned int) (-exponent);

    double result = PowerWithUnsignedExponent(base, absExponent);
    if(exponent < 0) result = 1.0 / result;


    return result;
}


double Power_2(double base, int exponent){
    if(exponent == 0) return 1;
    if(exponent == 1) return base;

    double result = Power_2(base, exponent >> 1);
    result *= result;
    if(exponent & 0x1 == 1) result *= base;  // exponent是奇数

    return result;
}
