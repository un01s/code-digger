/*
 * leetcode 713
 * subarray product less than k
 *
 */

class Solution {
public:
    int numSubarrayProductLessThanK(vector<int>& nums, int k) {
        if (k < 2) return 0;
        int n = nums.size();
        int l = 0, r = 0, ans = 0, p = 1;
        while (r != n) {
            p *= nums[r];
            while(p >= k) {
                p /= nums[l++];
            }
            r++;
            ans += r-l;
        }
        return ans;    
    }
};

