/*
 * intersection of two linked lists
 * 
 */

class Solution {
public:
    ListNode* getIntersectionNode(ListNode* headA, ListNode* headB) {
        ListNode* curA = headA;
        ListNode* curB = headB;
        // find the length of each linked list
        int lenA = 0, lenB = 0;
        while (curA != nullptr) {
            lenA++;
            curA = curA->next;
        }
        while (curB != nullptr) {
            lenB++;
            curB = curB->next;
        }
        // reset
        curA = headA;
        curB = headB;
        // point curA to the longer linked list
        if (lenB > lenA) {
            swap(lenA, lenB);
            swap(curA, curB);
        }
        // find the difference
        int gap = lenA - lenB;
        // put curA and curB at the same starting line
        // both tails are aligned
        while (gap--) {
            curA = curA->next;
        }
        // traverse both A and B until they meet
        while (curA != nullptr) {
            if (curA == curB) {
                return curA;
            }
            curA = curA->next;
            curB = curB->next;
        }
        return nullptr;
    }
};
