/*
 * leetcode 203
 * remove element from the linked list
 *
 */

#include <iostream>

using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
public:
    ListNode* removeElements(ListNode* head, int val) {
        ListNode* dummyHead = new ListNode(0);
        dummyHead->next = head;
        
        ListNode* cur = dummyHead;
        while (cur->next != NULL) {
            if(cur->next->val == val) {
                ListNode* tmp = cur->next;
                cur->next = cur->next->next;
                delete tmp;
            } else {
                cur = cur->next;
            }
        }

        head = dummyHead->next;
        delete dummyHead;

        return head;
    }
};

// recursive
class Solution2 {
public:
    ListNode* removeElements(ListNode* head, int val) {
        // the list can be viewed as a head node plus one shorter list
        // 1. handle if the head is null
        if (head == nullptr) return head;
        // 2. handle the shorter list without the head
        ListNode* res =  removeElements(head->next, val);
        // 3. handle the head node if not null
        if (head->val == val) 
            return res;
        else {
            head->next =res;
            return head;
        }    
    }
};


int main() {

    return 0;
}
