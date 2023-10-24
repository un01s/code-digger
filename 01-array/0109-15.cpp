/*
 * leetcode 15 3sum
 * double-pointer: left and right
 *
 */

class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        // sorting first
        sort(nums.begin(), nums.end());
        vector<vector<int> > res;

        for (int i = 0; i < nums.size(); i++) {
            int sum = -nums[i];
            
            int left = i+1;
            int right = nums.size()-1;
            
            while (left<right){
                if (nums[left]+nums[right]==sum) {
                    vector<int>temp{nums[i],nums[left],nums[right]};
                    res.push_back(temp);
                    left++;
                    right--;
                    while (left<right && nums[left]==nums[left-1]) left++;
                    while (left<right && nums[right]==nums[right+1]) right--; 
                }
                else if (nums[left]+nums[right]<sum)
                    left++;
                else if (nums[left]+nums[right]>sum)
                    right--;
            }
            
            while (i+1<nums.size() && nums[i]==nums[i+1])
                i++;
        }
        return res;    
    }
};
