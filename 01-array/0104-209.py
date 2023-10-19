"""
leetcode 209

the sliding window is [left, right]
the width of sliding window is right-left+1

n = len(nums)
because the answer won't be greater than n+1, use it as a condition in case
that no subarray is found to satisfy the target

"""

class Solution:
    def minSubArrayLen(self, target: int, nums: List[int]) -> int:
        n = len(nums)
        res = n+1
        left = sum = 0
        for right, x in enumerate(nums):
            s += x
            while s >= target:
                res = min(res, right-left+1)
                s -= nums[left]
                left += 1
        return res if res <= n else 0
