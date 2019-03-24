// 问题：将0，1，...n-1这n个数字排成一个圆圈，从数字0开始，每次从圆圈中删除第m个数字，求最后剩的那个数字
// 思路：该圆圈可以看成一个环形链表，于是问题就变成了环形链表中删节点的问题了
// 书上介绍的另一种方法，推了大半天，得到了一个递推公式，真的服了。。


int LastRemaining(unsigned int n, unsigned int m) {
	if (n < 1 || m < 1) return -1;

	unsigned int i = 0;
	std::list<int> numbers;
	for (int i = 0; i < n; ++i)
		numbers.push_back(i);

	auto current = numbers.begin();
	while (numbers.size() > 1){
		for (int i = 1; i < m; ++i) {
			current++;		// 移动到m处
			if (current == numbers.end())
				current = numbers.begin();	// 到了尾部就指向头部，这样就成了环形链表
		}

		auto next = ++current;	// 先把下一个保存下来，免得current删掉之后找不到了
		if (next == numbers.end())
			next = numbers.begin();

		--current;
		numbers.erase(current);
		current = next;
	}

	return *(current);
}

// 虽然推导了半天，但代码又简洁又高效，算法的力量！
int LastRemainning_2(unsigned int n, unsigned int m) {
	if (n < 1 || m < 1) return -1;

	int last = 0;
	for (int i = 2; i <= n; ++i)
		last = (last + m) % i;

	return last;
}
