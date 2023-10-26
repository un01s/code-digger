/*
 * leetcode 16: 3sum closest
 * 
 * sorting the array first
 * after the first element, how to move the pointers?
 * 
 * while(left < right) {
 *     if (abs(nums[left]+nums[right]-sum) < curSum) {
 *         update curSum;
 *     }
 *     if (nums[left]+nums[right] < sum) {
 *         left++;
 *     } else {
 *         right--;
 *     }
 * }
 *
 */

class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        sort(nums.begin(), nums.end());
        int tmp = INT_MAX;
        int res;
        for (int i = 0; i < nums.size(); i++) {
            int left = i+1;
            int right = nums.size()-1;
            int sum = target-nums[i];
            while (left < right) {
                int d = abs(nums[left]+nums[right]-sum);
                if (d < tmp) {
                    tmp = d;
                    res = nums[i]+nums[left]+nums[right];
                }
                if (nums[left]+nums[right] == sum) {
                    return target;
                } else if (nums[left]+nums[right] > sum) {
                    right--;
                } else {
                    left++;
                }
            }
        }
        return res;    
    }
};

