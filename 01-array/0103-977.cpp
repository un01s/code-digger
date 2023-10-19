/*
 * leetcode 977
 *
 * double-pointer: left and right
 * the for-loop is not complete
 *
 */

class Solution {
public:
    vector<int> sortedSquares(vector<int>& nums) {
        int n = nums.size();
        int k = n-1;
        vector<int> res(n, 0);
        for (int i = 0, j = n-1; i <= j; ) {
            if (nums[i]*nums[i] < nums[j]*nums[j]) {
                res[k--] = nums[j]*nums[j];
                j--;
            } else {
                res[k--] = nums[i]*nums[i];
                i++;
            }
        }
        return res;
    }
};

class Solution {
public:
    vector<int> sortedSquares(vector<int>& nums) {
        int n = nums.size();
        int k = n-1;
        vector<int> res(n, 0);
        for (int i = 0, j = n-1; i <= j; ) {
            int x = nums[i]*nums[i];
            int y = nums[j]*nums[j];
            if (x < y) {
                res[k--] = y;
                j--;
            } else {
                res[k--] = x;
                i++;
            }
        }    
        return res;
    }
};
