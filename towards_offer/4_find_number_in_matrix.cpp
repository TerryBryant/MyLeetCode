// 问题：在一个行、列都递增的二维数组，给定一个数，查找数是否在二维数组中
// 思路：从右往左，从上往下找
// 注意这个找的顺序，不能从左上角或者右下角开始找
#include<iostream>
#include<vector>

using std::vector;
using std::cout;
using std::endl;

bool findIntegerInMatrix(const vector<vector<int>>& nums, int number) {
	bool found = false;
	int rows = nums.size();
	int cols = nums[0].size();

	if (rows > 0 && cols > 0) {
		int row = 0;
		int col = cols - 1;
		while (row < rows && col >= 0) {
			if (nums[row][col] == number) {
				found = true;
				break;
			}
			else if (nums[row][col] > number) {
				col--;
			}
			else {
				row++;
			}
		}
	}

	return found;
}

int main() {
	vector<vector<int>> nums = { {1, 2, 8, 9}, {2, 4, 9, 12}, {4, 7, 10, 13}, {6, 8, 11, 15} };
	cout << findIntegerInMatrix(nums, 5) << endl;
}
