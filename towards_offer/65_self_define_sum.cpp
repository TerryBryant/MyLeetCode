// 问题：不使用加减乘除，完成两个整数相加
// 思路：其实加减乘除都可以用位运算来解决，这里要实现加法运算，考虑分三步
// 第一步将两个值相异或，不考虑进位，那么其实相当于两个值进行相加了
// 第二步将两个值相与，这样相当于记下了进位，注意将这个与的结果左移
// 第三步则是将前两步的值进行相加了，也就是异或


int Add(int num1, int num2) {
	int sum, carry;
	do {
		sum = num1 ^ num2;
		carry = (num1 & num2) << 1;	// 左移是因为产生了进位
		num1 = sum;
		num2 = carry;
	} while (num2 != 0);

	return num1;
}