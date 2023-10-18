/*
 * leetcode 27
 * remove element
 *
 * double-pointer: fast and slow pointers
 * k is the slow pointer and i the fast
 *
 */

class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
        int k = 0;
        for (int i = 0; i < nums.size(); i++) {
            if (nums[i] != val) {
                nums[k++] = nums[i];
            }
        }    
        return k;    
    }
};
