// 在一个整数组中，找一个子数组，使得它的和最大
// [-1, 2, 3,-4,7] => [2,3,-4,7]


// 解决思路：之前在网上看到一个算法，就是在一个整数组中找到最大和子列，即在所有的子列中，求出最大和，而且该算法的复杂度只有O(n)
// 这里刚好可以参考，因为找到最大和之后，再遍历一次数组，就能找到这个子数组了，故整体的复杂度还是O(n)

#include<iostream>
using namespace std;

void fun( int input[], int N, int &begin, int &end )
{
	int maxSum = 0, thisSum = 0;
	for (int i = 0; i<N; i++)
	{
		thisSum += input[i];
		if (thisSum>maxSum)
		{
			maxSum = thisSum;
			end = i;
		}
		else if(thisSum<0)
		{
			thisSum = 0;
		}
	}


	int sum = 0;
	for (int i = end; i >= 0; i--)
	{
		sum += input[i];
		if ( sum == maxSum )
		{
			begin = i;
			break;
		}
	}
}

int main() 
{
	int N2 = 5;
	int input[] = {-1, -2, 8, -5, 6, 7, -10, -5, 12, 15};
	int begin = 0, end = 0;

	int N = sizeof(input) / sizeof(input[0]);

	fun(input, N, begin, end);

}
