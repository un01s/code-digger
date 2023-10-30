/* 
 * leetcode 19
 * 
 */

class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode* dummyHead = new ListNode(0);
        dummyHead->next = head;
        ListNode* slow = dummyHead;
        ListNode* fast = dummyHead;
        // move the fast pointer n steps first
        while(n-- && fast != nullptr) {
            fast = fast->next;
        }
        fast = fast->next;
        // slow has to be pointed just before the node to be deleted
        while (fast != nullptr) {
            fast = fast->next;
            slow = slow->next;
        } 
        slow->next = slow->next->next;
        //
        return dummyHead->next;
    }
};
