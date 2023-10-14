/*
 * leetcode 704
 * array, binary search
 *
 */

class Solution {
public:
    int search(vector<int>& nums, int target) {
        int n = nums.size();
        int i = 0, j = n-1;
        while(i <= j) {
            int m = i + (j-i)/2;
            if (nums[m] < target) {
                i = m+1;
            } else if (nums[m] > target) {
                j = m-1;
            } else {
                return m;
            }
        }
        return -1;
    }
};

