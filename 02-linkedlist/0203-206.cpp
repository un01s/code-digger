/*
 * leetcode 206
 * reverse linked list
 *
 * double-pointer
 *
 */

struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
public:
    ListNode* reverseList(ListNode* head) {
        ListNode* tmp; // cur next
        ListNode* cur = head;
        ListNode* pre = nullptr;

        while(cur != nullptr) {
            tmp = cur->next;
            cur->next = pre;
            // update
            pre = cur;
            cur = tmp;
        }
        return pre;
    }
};

// recursive
class Solution {
public:
    ListNode* reverseList(ListNode* head) {
        if (head == nullptr || head->next == nullptr) return head;

        ListNode* pre = nullptr;
        ListNode* h2 = reverseList(head->next);

        head->next->next = head;
        head->next = pre;
        return h2;
    }
};

// another recursive
class Solution {
public:
    ListNode* reverse(ListNode* pre, ListNode* cur) {
        if (cur == nullptr) return pre;
        ListNode* tmp = cur->next;
        //
        cur->next = pre;
        //pre = cur;
        //cur = tmp;
        return reverse(cur, tmp);
    }
  
    ListNode* reverseList(ListNode* head) {
        return reverse(nullptr, head);
    }
};
