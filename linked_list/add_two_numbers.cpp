//Input: (2 -> 4 -> 3) + (5 -> 6 -> 4)
//Output : 7 -> 0 -> 8
//Explanation : 342 + 465 = 807

// 我自己的解法，写了半天，还是个错的，因为不能处理大整数的情况
int traverse(ListNode* li){
    std::vector<int> nums;
    while(li != nullptr){
        nums.push_back(li->val);
        li = li->next;
    }

    int ret = 0;
    for(int i=0; i<nums.size(); i++) ret += nums[i] * pow(10, i);
    return ret;
}

ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
    int ans = traverse(l1) + traverse(l2);

    int ans_len = std::to_string(ans).length();

    ListNode* ret = new ListNode(ans % 10);
    ListNode* head = ret;
    for(int i=1; i<ans_len; i++){
        ListNode* newNode = new ListNode(ans / (int)pow(10, i) % 10);
        head->next = newNode->next;
        head->next = newNode;
        head = head->next;
    }

    return ret;
}
  
  // 下面是网上大佬的方法，又简洁又清晰，厉害了
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
