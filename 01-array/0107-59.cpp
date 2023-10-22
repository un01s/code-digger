/*
 * leetcode 59
 * 
 * loop invariant:
 *
 * range [left, right), always close and open
 * top row:    from left to right
 * right col:  from top to bottom
 * bottom row: from right to left
 * left col:   from bottom to top
 *
 * then at the end, it is a special case, either one grid or more left
 *
 */

class Solution {
public:
    vector<vector<int>> generateMatrix(int n) {
        vector<vector<int>> res(n, vector<int>(n, 0)); 
        // this is the result, 2D vector

        int startx = 0, starty = 0; // start position for each loop
        int loop = n / 2; // how many loops?
        // if n = 3, loop = 1, the center grid has to be handle separately
        int mid = n / 2; // the center grid
        // if n = 3, the center is (1, 1)
        // if n = 5, the center is (2, 2)
        int count = 1; // the value to the matrix
        int offset = 1; // have to control the length of each side in a loop
        // after each loop, the edge shrinks one
        int i,j;
        while (loop --) {
            i = startx;
            j = starty;

            // 4 for-loop, each one side, after that it completes one loop
            // top side: [left, right)
            for (j = starty; j < n - offset; j++) {
                res[startx][j] = count++;
            }
            // right side: [top, bottom)
            for (i = startx; i < n - offset; i++) {
                res[i][j] = count++;
            }
            // bottom side: [right, left)
            for (; j > starty; j--) {
                res[i][j] = count++;
            }
            // left side: [bottom, top)
            for (; i > startx; i--) {
                res[i][j] = count++;
            }

            // to prepare for the next loop:
            // the start position has to add 1
            startx++;
            starty++;
            // the offset has to move 1
            offset += 1;
        }

        // if n is an odd number, have to deal with the center grid
        if (n % 2) {
            res[mid][mid] = count;
        }
        return res;
    }
};
