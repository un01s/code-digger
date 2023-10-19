/*
 * leetcode 209
 * minimum size subarray sum
 *
 * return the minimum length of a subarray whose sum is greater than or 
 * equal to target.
 *
 * find the subarray, but only the length of it is required to return
 *
 */

class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        int res = INT_MAX;
        int sum = 0;
        int i = 0; // start of sliding window
        int width = 0; // the length of sliding window
        for (int j = 0; j < nums.size(); j++) {
            sum += nums[j]; // get one element in by the for-loop
            while (sum >= target) {
                width = j-i+1;
                res = res < width ? res : width;
                sum -= nums[i++]; // remove the starting element in the window
            }
        }
        return res == INT_MAX ? 0 : res;    
    }
};

