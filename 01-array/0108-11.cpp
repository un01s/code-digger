/*
 * leetcode 11 containet with most water
 * 
 * double-pointer: left and right
 *
 */

class Solution {
public:
    int maxArea(vector<int>& height) {
        int n = height.size();
        int left = 0, right = n-1;
        int temp = 0;
        int result = 0;
        
        while (left<right) {
            int temp = (right-left)*min(height[left], height[right]);
            if (temp>result) result=temp;
            
            if (height[left]>=height[right])
                right--;
            else
                left++;
        }
        
        return result;    
    }
};

// this looks better
class Solution {
public:
    int maxArea(vector<int>& height) {
        int i = 0, j = height.size() - 1, res = 0;
        while(i < j) {
            if (height[i] < height[j]) {
                res = max(res, (j-i)*height[i++]);
            } else {
                res = max(res, (j-i)*height[j--]);
            } 
        }
        return res;
    }
};
