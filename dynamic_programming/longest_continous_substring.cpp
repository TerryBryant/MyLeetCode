// 问题：求两个序列的最大公共子列/子串，注意子列是可以不连续的，字串必须连续
// 思路：这是典型的动态规划题目，找到状态转移方程即可，具体直接看代码即可
// 需要注意的是，子列和子串的状态转移方程略有不同，当x[i] != y[j]的时候lcs[i][j]的结果不一样


// 子列
int longestContinousSubList(const std::string& str1, const std::string& str2) {
	int rows = str1.length();
	int cols = str2.length();
	std::vector<std::vector<int>> lcs(rows+1, std::vector<int>(cols+1, 0));

	for (int i = 1; i <= rows; i++) {
		for (int j = 1; j <= cols; j++) {
/*			if (i == 0 || j == 0) {
				lcs[i][j] = 0;
				continue;
			}*/	

			if (str1[i-1] == str2[j-1]){
				lcs[i][j] = lcs[i - 1][j - 1] + 1;
			}
			else {
				lcs[i][j] = lcs[i - 1][j] > lcs[i][j - 1] ? lcs[i - 1][j] : lcs[i][j - 1];
			}
		}
	}

	return lcs[rows][cols];
}

// 子串
int longestContinousSubstring(const std::string& str1, const std::string& str2){
	int result = 0;
	int rows = str1.length();
	int cols = str2.length();
	std::vector<std::vector<int>> lcs(rows + 1, std::vector<int>(cols + 1, 0));

	for (int i = 1; i <= rows; i++) {
		for (int j = 1; j <= cols; j++) {
			//if (i == 0 || j == 0) {
			//	lcs[i][j] = 0;
			//	continue;
			//}

			if (str1[i - 1] == str2[j - 1]) {
				lcs[i][j] = lcs[i - 1][j - 1] + 1;
			}
			else {
				lcs[i][j] = 0;
			}

			if (result < lcs[i][j])
				result = lcs[i][j];
		}
	}

	return result;
}
