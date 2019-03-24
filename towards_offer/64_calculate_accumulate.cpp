// 问题：计算1+2+3+...+n，要求不能使用乘除、for、while、if等等
// 思路：当这些都不能用的时候，可以从c++语言本身的角度进行考虑
// 方法一通过构造函数是最简单的方法，每构造一次就累加
// 方法二通过虚函数也很巧妙，通过两个函数来递归和终止递归，终止递归涉及到将n转成bool值，这可以通过连续两次取反操作来进行
// 方法三是函数指针的方式，针对纯c语言环境使用
// 方法四模板类这一块还是知识盲区。。

class Temp {
public:
	Temp() { ++N; Sum += N; }
	static void Reset() { N = 0; Sum = 0; }
	static unsigned int GetSum() { return Sum; };
private:
	static unsigned int N;
	static unsigned int Sum;
};

unsigned int Temp::N = 0;
unsigned int Temp::Sum = 0;

unsigned int Sum_solution1(unsigned int n) {
	Temp::Reset();

	Temp *a = new Temp[n];

	delete[]a;
	a = nullptr;

	return Temp::GetSum();
}

//////////////////////////////////////////////////////////////////////////////
class A;
A* Array[2];
class A {
public:
	virtual unsigned int Sum(unsigned int n) { return 0; }
};

class B : public A
{
public:
	virtual unsigned int Sum(unsigned int n) {
		return Array[!!n]->Sum(n - 1) + n;
	}
};

int Sum_solution2(int n) {
	A a;
	B b;
	Array[0] = &a;
	Array[1] = &b;

	int value = Array[1]->Sum(n);

	return value;
}

//////////////////////////////////////////////////////////////////////////////
typedef unsigned int(*fun)(unsigned int);
unsigned int Sum_solution3_Terminator(unsigned int n) {
	return 0;
}

unsigned int Sum_solution3(unsigned int n) {
	static fun f[2] = { Sum_solution3_Terminator, Sum_solution3 };
	return n + f[!!n](n - 1);
}

//////////////////////////////////////////////////////////////////////////////
template<unsigned int n> struct Sum_solution4{
	enum Value {
		N = Sum_solution4<n - 1>::N + n
	};
};

template<>struct Sum_solution4<1>
{
	enum Value {
		N = 1
	};
};

int main() {
	const unsigned int number = 3;

	unsigned int aa = Sum_solution1(number);

	unsigned int bb = Sum_solution2(number);

	unsigned int cc = Sum_solution3(number);

	unsigned int dd = Sum_solution4<number>::N;

	return 1;
}
