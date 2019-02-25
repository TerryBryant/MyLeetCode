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


int traverse(ListNode* li){
        vector<int> nums;
        while(li->next != nullptr) nums.push_back(li->val);
        
        int ret = 0;
        for(int i=0; i<nums.size(); i++) ret += pow(10, i);
        return ret;
    }
    
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode* ret;
        int ans = traverse(l1) + traverse(l1);
        
        int ans_len = std::to_string(ans).length();
        for(int i=0; i<ans_len; i++){
            ListNode* newNode = new ListNode(ans % (ans_len - 1 - i));
            ret->next = newNode;
        }
        
        return ret;
    }
