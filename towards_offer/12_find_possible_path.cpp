// 问题：给定一个矩阵，矩阵元素是字符，判断某个字符串是否可以通过矩阵的某条不重复路径走出来，每次只能上下左右移动一步
// 思路：这种在二维矩阵上找路径的问题，通常都可以用回溯法来解决，回溯法的思想可以通过树来理解
// 它其实就是一种暴力破解，找不到正确路径时，要能退回到上一个节点
// 代码还是很好理解的，但是现场肯定写不出来。。

bool hasPathCore(const char* matrix, int rows, int cols, int row, int col,
	const char* str, int& pathLength, bool* visited) {
	if (str[pathLength] == '\0') return true;

	bool hasPath = false;
	if (row >= 0 && row < rows && col >= 0 && col < cols &&
		matrix[row*cols + col] == str[pathLength] && !visited[row*cols + col]) {
		++pathLength;
		visited[row*cols + col] = true;

		hasPath = hasPathCore(matrix, rows, cols, row, col - 1, str, pathLength, visited)
			|| hasPathCore(matrix, rows, cols, row, col + 1, str, pathLength, visited)
			|| hasPathCore(matrix, rows, cols, row - 1, col, str, pathLength, visited)
			|| hasPathCore(matrix, rows, cols, row + 1, col, str, pathLength, visited);

		if (!hasPath) {
			--pathLength;
			visited[row*col + col] = true;
		}
	}

	return hasPath;
}

bool hasPath(char* matrix, int rows, int cols, char* str) {
	if (matrix == nullptr || rows < 1 || cols < 1 || str == nullptr) return false;

	bool* visited = new bool[rows * cols];
	memset(visited, 0, rows * cols);

	int pathLength = 0;
	for (int row = 0; row < rows; row++) {
		for (int col = 0; col < cols; col++) {
			if (hasPathCore(matrix, rows, cols, row, col, str, pathLength, visited)) {
				delete[] visited;
				return true;
			}			
		}
	}

	delete[] visited;
	return false;
}
