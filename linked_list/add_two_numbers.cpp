	//Input: (2 -> 4 -> 3) + (5 -> 6 -> 4)
	//Output : 7 -> 0 -> 8
	//Explanation : 342 + 465 = 807
  
  // 链表题目，学习大佬们的方法。。
  ListNode *addTwoNumbers(ListNode *l1, ListNode *l2) {
    ListNode preHead(0), *p = &preHead;
    int extra = 0;
    while (l1 || l2 || extra) {
        if (l1) extra += l1->val, l1 = l1->next;
        if (l2) extra += l2->val, l2 = l2->next;
        p->next = new ListNode(extra % 10);
        extra /= 10;
        p = p->next;
    }
    return preHead.next;
}
