// 问题：给定一个m*n的方格，一个机器人从(0,0)开始移动，可以走上下左右，但不能进入行坐标和纵坐标数位之和大于k的格子，求总共能进入多少格子
// 思路：与第12题类似，采用回溯法，代码也比较类似，至少判断方式有区别
//

int GetDigitSum(int number) {
	int sum = 0;
	while (number > 0) {
		sum += number % 10;
		number /= 10;
	}

	return sum;
}

// 用于判断该格子是否符合条件
bool check(int threshold, int rows, int cols, int row, int col, bool* visited) {
	if (row >= 0 && row < rows && col >= 0 && col < cols
		&& GetDigitSum(row) + GetDigitSum(col) <= threshold
		&& !visited[row*cols + col]) {
		return true;
	}

	return false;
}

int movingCountCore(int threshold, int rows, int cols, int row, int col, bool* visited) {
	int count = 0;

	if (check(threshold, rows, cols, row, col, visited)) {
		visited[row*cols + col] = true;
		count = 1 + movingCountCore(threshold, rows, cols, row, col + 1, visited)
			+ movingCountCore(threshold, rows, cols, row, col - 1, visited)
			+ movingCountCore(threshold, rows, cols, row + 1, col, visited)
			+ movingCountCore(threshold, rows, cols, row - 1, col, visited);
	}
	
	return count;
}

int movingCount(int threshold, int rows, int cols) {
	if (threshold < 0 || rows < 0 || cols < 0) return 0;

	bool* visited = new bool[rows*cols];
	memset(visited, 0, rows*cols);

	int count = movingCountCore(threshold, rows, cols, 0, 0, visited);

	delete[] visited;
	return count;
}
