// 问题：合并k个排序链表
// 思路：此题是合并两个排序链表的升级版，核心思想其实变化不大，主要就是处理每个链表的表头排序问题
// 可以考虑将所有链表的表头放在一个小顶堆里，每次取出堆顶，并将堆顶所在链表的下一个节点压入小顶堆，再调整堆
// 堆的实现可以直接借助stl

struct ListNode{
    int val;
    ListNode* next;
    ListNode(int v) : val(v), next(nullptr) {}
};

static bool HeapComp(ListNode* a, ListNode* b) {
    return a->val > b->val;
} 

ListNode* mergeKLists(vector<ListNode*> lists) {
    int length = lists.size();
    if(length <= 0) return nullptr;
    
    ListNode* head = new ListNode(0);
    ListNode* curNode = head;
    
    vector<ListNode*> v;
    for(int i=0; i<length; ++i){
        if(lists[i])
            v.push_back(lists[i]);
    }
    
    std::make_heap(v.begin(), v.end(), HeapComp);
    
    // 接下来开始合并，思路很清晰，关键是细节要对
    while(v.size() > 0) {
        curNode->next = v.front();
        std::pop_heap(v.begin(), v.end(), HeapComp);
        v.pop_back();
        
        curNode = curNode->next;
        if(curNode->next){
            v.push_back(curNode->next);
            std::push_heap(v.begin(), v.end(), HeapComp);
        }
    }
}
