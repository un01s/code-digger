"""
leetcode 977
python

check it how the lambda function is used.

but this is brute-force solution.
it squares each element, then sort it.

"""

class Solution:
    def sortedSquares(self, nums: List[int]) -> List[int]:
        return sorted(list(map(lambda x: x*x, nums)))

class Solution:
    def sortedSquares(self, nums: List[int]) -> List[int]:
        for i in range(len(nums)):
            nums[i] = nums[i]**2
        return sorted(nums)

# double-pointer
class Solution:
    def sortedSquares(self, nums: List[int]) -> List[int]:
        # double-pointer: left and right
        l, r = 0, len(nums)-1
        res = []
        while l <= r:
            x = nums[l]*nums[l]
            y = nums[r]*nums[r]
            if x >= y:
                res.append(x)
                l += 1
            else:
                res.append(y)
                r -= 1
        return reversed(res)

