/*
 * leetcode 704
 * array, binary search
 *
 * vector is much more flexible than real array in C++
 *
 * - use size() to get the size or the length of an array
 * - use the index, nums[index], to get the value of one element 
 *   in the array of nums
 *
 */

//
// iterative
// search range is always [left, right]
// loop invariant
//
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

//
// iterative
// search range is always [left, right)
//
class Solution {
public:
    int search(vector<int>& nums, int target) {
        int left = 0;
        int right = nums.size();
        // [left, right)
        while (left < right) {
            int mid = left + (right-left)/2;
            if (nums[mid] > target) {
                right = mid; // mid is not the answer
            } else if (nums[mid] < target) {
                left = mid+1; // mid is not answer
            } else {
                return mid;
            }
        }
        return -1;
    }
};

// 
// recursive
//
class Solution {
public:
    int bSearch(vector<int>& nums, int target, int start, int end){
        // terminate
        if(end < start) return -1;
        // mid point, recursive
        int mid = (start+end)/2;
        if(nums[mid] == target){
            return mid;
        }else if(target < nums[mid]){
            return bSearch(nums, target, start, mid-1);
        }else{
            return bSearch(nums, target, mid+1, end);
        }
    }
    int search(vector<int>& nums, int target) {
        return bSearch(nums, target, 0, nums.size()-1);
    }
};

