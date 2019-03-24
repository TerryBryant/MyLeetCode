// 问题：从扑克牌中任选五张，判断它是不是顺子，令A=1，J、Q、K=11，12，13，大小王可以看成任意数字
// 思路：可以把大小王当成0，此题就是判断0的个数是否大于等于五张牌的间隔，前提是要给五张牌先排好序
// 另外五张牌要是出现重复的，那么比不可能是顺子
// 其实此题思路还是很简单的，就是想法比较新颖


int compare(const void* arg1, const void* arg2) {
	return *(int*)arg1 - *(int*)arg2;
}

bool IsContinuous(int* numbers, int length) {
	if (numbers == nullptr || length < 1) return false;

	std::qsort(numbers, length, sizeof(int), compare);

	int numberOfZero = 0;
	int numberOfGap = 0;

	for (int i = 0; i < length && numbers[i] == 0; ++i)
		++numberOfZero;

	int small = numberOfZero;
	int big = small + 1;
	while (big < length) {
		if (numbers[small] == numbers[big])
			return false;  // 有对子不可能是顺子

		numberOfGap += numbers[big] - numbers[small] - 1;
		small = big;
		++big;
	}

	return (numberOfGap > numberOfZero) ? false : true;
}
