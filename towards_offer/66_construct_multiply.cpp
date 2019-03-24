// 问题：定义一个数组A[0,1,...n-1]，构建一个数组B[0,1,...n-1]，使得B[i] = A[0]*...A[i-1]*A[i-2]...*A[n-1]，要求不能用除法
// 思路：要是可以用除法，直接把A全部乘起来，再除以A[i]即可
// 不妨定义B[i] = C[i]* D[i]，其中C[i] = A[0]*A[1]*...A[i-1]，D[i] = A[i+1]*...A[n-1]
// 那么C[i] = C[i-1] * A[i-1], D[i] = D[i+1] * A[i+1]，可以通过递归来计算得到

void multiply(const vector<double>& array1, vector<double>& array2) {
	int length1 = array1.size();
	int length2 = array2.size();

	if (length1 == length2 && length2 > 1) {
		array2[0] = 1;
		for (int i = 1; i < length1; ++i)
			array2[i] = array2[i - 1] * array1[i - 1];

		double temp = 1;
		for (int i = length1 - 2; i >= 0; --i) {  // B[n-1] = A[0]*...*A[n-2]
			temp *= array1[i + 1];
			array2[i] *= temp;
		}

	}
}
