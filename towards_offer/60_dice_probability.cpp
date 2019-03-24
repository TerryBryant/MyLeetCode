// 问题：将n个骰子扔在地上，求每个总点数出现的概率
// 思路：1个骰子扔地上，每一面出现的概率都等于1/6，但是扔两个骰子的时候，总点数范围就成了2~12，要求它们相应的概率
// 可以这么理解，第1个骰子扔出去，1~6出现的次数都是1；第2个扔出去，总点数等于2的次数是1（两次都是1），总点数等于3的次数是2（1，2和2，1）
// 其实就是下一次总和为n的次数，等于上一次总和为n-1，n-2...n-6的次数之和，例如下一次总和为7，那么就是（6，1；5，2；。。。）
// 所以可以定义两个数组来保存这两个状态

int g_maxValue = 6;

void PrintProbability(int number) {
	if (number < 1) return;

	int* pProbabilities[2];
	pProbabilities[0] = new int[g_maxValue * number + 1];
	pProbabilities[1] = new int[g_maxValue * number + 1];

	for (int i = 0; i < g_maxValue * number + 1; ++i) {
		pProbabilities[0][i] = 0;
		pProbabilities[1][i] = 0;
	}

	int flag = 0;
	for (int i = 1; i <= g_maxValue; ++i)
		pProbabilities[flag][i] = 1;		// 第一轮

	for (int k = 2; k <= number; ++k) {
		for (int i = 0; i < k; ++i)
			pProbabilities[1 - flag][i] = 0;

		for (int i = k; i < g_maxValue*k; ++i) {
			pProbabilities[1 - flag][i] = 0;
			for (int j = 1; j <= i&&j <= g_maxValue; ++j)
				pProbabilities[1 - flag][i] += pProbabilities[flag][i - j];	// j=1~6，即n-1，n-2等等
		}

		flag = 1 - flag;
	}

	double total = pow(g_maxValue, number);
	for (int i = number; i <= g_maxValue*number; ++i) {
		double ratio = (double)pProbabilities[flag][i] / total;
		cout << i << ": " << ratio << endl;
	}

	delete[] pProbabilities[0];
	delete[] pProbabilities[1];
}
