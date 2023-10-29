/*
 * leetcode 24
 * swap nodes in pairs
 * 
 */

class Solution {
public:
    ListNode* swapPairs(ListNode* head) {
        ListNode* dummyHead = new ListNode(0);
        dummyHead->next = head;
        ListNode* cur = dummyHead;
        while(cur->next != nullptr && cur->next->next != nullptr) {
            ListNode* tmp = cur->next; // 1
            ListNode* tmp2 = cur->next->next->next; // 3

            cur->next = cur->next->next; // 2
            cur->next->next = tmp; // reverse pair 1
            cur->next->next->next = tmp2; // connect to 3 (the start of next pair)
            // prepare for the next move
            cur = cur->next->next;
        }
        return dummyHead->next;        
    }
};

