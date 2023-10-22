"""
leetcode 59
"""

class Solution:
    def generateMatrix(self, n: int) -> List[List[int]]:
        l, r, t, b = 0, n-1, 0, n-1
        res = [[0 for _ in range(n)] for _ in range(n)]
        num, tar = 1, n*n
        while num <= tar:
            # top side: from left to right
            for i in range(l, r+1):
                res[t][i] = num
                num += 1
            t += 1
            # right side: from top to bottom
            for i in range(t, b+1):
                res[i][r] = num
                num += 1
            r -= 1
            # bottom side: from right to left
            for i in range(r, l-1, -1):
                res[b][i] = num
                num += 1
            b -= 1
            # left side: from bottom to top
            for i in range(b, t-1, -1):
                res[i][l] = num
                num += 1
            l += 1
        return res

