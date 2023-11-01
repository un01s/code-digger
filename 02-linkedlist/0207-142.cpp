/*
 * leetcode 142
 * 
 * if there is a circle
 * find out the entry node of the circle
 *
 * fast and slow pointer
 * start from the head, the fast moves two nodes a time while 
 * the slow moves one node.
 * if they meet, then there is a circle.
 * 
 * head ---x--> entry --y--> met --z--> entry
 *
 * for the slow pointer, x+y
 * for the fast pointer, x+y + n*(y+z)
 * n >= 1
 * 
 */

class Solution {
public:
    ListNode* detectCycle(ListNode* head) {
        ListNode* fast = head;
        ListNode* slow = head;
        while(fast != nullptr && fast->next != nullptr) {
            slow = slow->next;
            fast = fast->next->next;
            if (fast == slow) {
                ListNode* index1 = fast;
                ListNode* index2 = head;
                while(index1 != index2) {
                    index1 = index1->next;
                    index2 = index2->next;
                }
                return index2; // entry point
            }
        }
        return nullptr;
    }
};

