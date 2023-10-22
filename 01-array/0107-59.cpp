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

//
// use a directional array to control each side, four sides = one loop
//
class Solution {
public:
    // four directions:
    const int dir[4][2] = { {0,1},{1,0},{0,-1},{-1,0} };
    // after four directions are used, one loop completes

    vector<vector<int>> generateMatrix(int n) {
        vector<vector<int>> res(n,vector<int>(n,0));
        for(int i = 1, x = 0, y = 0, d = 0; i <= n * n; i++){
            res[x][y] = i;
            int t_x = x + dir[d][0];
            int t_y = y + dir[d][1];
            if(t_x < 0 || t_x >= n || t_y < 0 || t_y >= n || res[t_x][t_y] != 0){
                d = (d + 1) % 4;
                t_x = x + dir[d][0],t_y = y + dir[d][1];
            }
            x = t_x, y = t_y;
        }
        return res;    
    }
};

//
// recursive
// use both top-left corner and bottom-right corner to construct the loop
//
class Solution {
public:
    /*
        (x1, y1) -------------
            |                |
            |                |
            |                |
            | ------------(x2, y2)

     */
    void loop(int x1, int y1, int x2, int y2, int start, vector<vector<int> >& res) {
        if (x2 < x1 || y2 < y1) return;
        if (x1 == x2) {
            res[x1][y1] = start;
            return;
        }
        int val = start;
        for (int i = y1; i < y2; i++) res[x1][i] = val++;
        for (int i = x1; i < x2; i++) res[i][x2] = val++;
        for (int i = y2; i > y1; i--) res[x2][i] = val++;
        for (int i = x2; i > x1; i--) res[i][y1] = val++;

        loop(x1+1, y1+1, x2-1, y2-1, val, res);
    }

    vector<vector<int>> generateMatrix(int n) {
        vector<vector<int>> res(n,vector<int>(n,0));
        loop(0, 0, n-1, n-1, 1, res);
        return res;    
    }
}; 
