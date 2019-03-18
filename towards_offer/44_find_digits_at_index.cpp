// 问题：将数字以0123456789101112...的格式存入字符串，求任意第n位对应的数字
// 思路：以第1001位为例，前面10位是0～9，接下来是10～99，共2*90=180位，接下来是100～999共3*900=2700位
// 1001-10-180=881，位于100～999中
// 而881=270*3+1，故最终的结果是从100起的270个数，即370的第1位（从0起算），即7


// 第一个两位数是10，第一个三位数是100
int beginNumber(int digits){
    if(digits == 1) return 0;

    return (int)pow(10, digits - 1);
}

// digits位的数字共有多少个，例如3位数的数字100~999共有900个
int countOfInteger(int digits){
    if(digits == 1) return 10;

    int count = (int)pow(10, digits - 1);
    return 9 * count;
}


int digitAtIndex(int index, int digits){
    int number = beginNumber(digits) + index / digits;
    int indexFromRight = digits - index % digits;
    for (int i = 1; i < indexFromRight; ++i) {
        number /= 10;
    }

    return number % 10;
}

int digitAtIndex(int index){
    if(index < 0) return -1;
    
    int digits = 1;
    while(ture){
        int numbers = countIntegers(digits);
        if(index < numbers * digits)
            return digitAtIndex(index, digits);
        
        index -= numbers * digits;
        digits++;
    }
}
