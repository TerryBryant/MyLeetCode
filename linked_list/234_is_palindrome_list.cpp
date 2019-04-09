// 问题：判断一个单链表是否为回文串
// 思路：将链表的后半段翻转，然后和前半段进行一一比对即可
//


/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode* ReverseList(ListNode* head){
        ListNode* pre = nullptr;
        ListNode* next = nullptr;

        while (head != nullptr){
            next = head->next;
            head->next = pre;
            pre = head;
            head = next;
        }

        return pre;
    }
    
    
    bool isPalindrome(ListNode* head) {
        if(head == nullptr || head->next == nullptr)
        return true;

        ListNode* slow = head;
        ListNode* fast = head;
        while (fast->next != nullptr && fast->next->next != nullptr) {   // 注意这里两个都是fast
            slow = slow->next;
            fast = fast->next->next;
        }

        slow = slow->next;  // 注意这里是后半段翻转，所以要到next
        slow = ReverseList(slow);
        
        while (slow != nullptr){
            if(head->val != slow->val)
                return false;
            head = head->next;
            slow = slow->next;
        }

        return true;
    }
};
