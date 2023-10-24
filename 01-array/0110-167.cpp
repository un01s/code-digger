/*
 * leetcode 167 
 * two sum II - input array is sorted
 *
 * double-pointer: left and right
 *
 */

class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        int i = 0; 
        int j = numbers.size()-1;
        while (i < j) {
            int s = numbers[i]+numbers[j];
            if (s < target) {
                i++;
            } else if (s > target) {
                j--;
            } else {
                return vector<int>{i+1, j+1};
            }
        }    
        return vector<int>{-1, -1};
    }
};

