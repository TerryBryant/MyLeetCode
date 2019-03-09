// 问题：给定一个整数，求它的二进制表示中，1的个数
// 思路：很容易想到的就是不断的除2，然后跟1进行与操作，除2的话一般是移位操作，碰到负数，可能进入死循环
// 思路2：定义一个unsigned int flag，与n进行与，然后右移，这样避免了函数进入死循环
// 思路3：将n减一，再与自己进行与，其操作相当于把最右边的1变成了0，这是最快的方法，很多地方都可能用到


int NumberOf1_1(int n){
    int count = 0;
    while (n > 0){
        count++;
        n = n >> 1;
    }

    return count;
}

int NumberOf1_2(int n){
    int count = 0;
    unsigned int flag = 1;
    while (flag){
        if(n & flag)
            count++;

        flag = flag << 1;
    }

    return count;
}


int NumberOf1_3(int n){
    int count = 0;

    while (n){
        count++;
        n = n & (n - 1);
    }

    return count;
}
