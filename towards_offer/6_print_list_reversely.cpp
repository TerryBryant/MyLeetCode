#include<iostream>
#include<stack>

struct ListNode
{
	int m_nKey;
	ListNode* m_pNext;
};

// 用栈来实现从尾到头打印list
void PrintListReversingly(ListNode* pHead) {
	std::stack<ListNode*> nodes;

	ListNode* pNode = pHead;
	while (pNode != nullptr) {
		nodes.push(pNode);
		pNode = pNode->m_pNext;
	}

	while (!nodes.empty()){
		pNode = nodes.top();
		std::cout << pNode->m_nKey << "/t";
		nodes.pop();
	}
}

// 基于递归来实现从尾到头打印链表
void PrintListReversingly_Recursively(ListNode* pHead) {
	if (pHead != nullptr) {
		if (pHead->m_pNext != nullptr) PrintListReversingly_Recursively(pHead->m_pNext);
		std::cout << pHead->m_nKey;
	}
}

int main() {
}
