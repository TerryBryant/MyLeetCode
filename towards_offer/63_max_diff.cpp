// 问题：把股票价格按照时间顺序存储在数组中，求如何获得最大利润，例如{9, 11, 5, 7, 12, 16, 14}，最大利润是16-5=11
// 思路：要是能把这个问题转化成diff问题，那么此题就不用暴力破解了。其实就是遍历数组，记下已经遍历过的数组中的最小值，然后用数组的下一个值来减
//

int MaxDiff(const int* numbers, unsigned int length) {
	if (numbers == nullptr || length < 2) return 0;

	int min = numbers[0];
	int maxDiff = numbers[1] - min;

	for (int i = 2; i < length; i++) {
		if (numbers[i - 1] < min)
			min = numbers[i - 1];

		int currentDiff = numbers[i] - min;
		if (currentDiff > maxDiff)
			maxDiff = currentDiff;
	}

	return maxDiff;
}
