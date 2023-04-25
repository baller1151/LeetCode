/*
You are given an m x n binary matrix grid, where 0 represents a sea cell and 1 represents a land cell.

A move consists of walking from one land cell to another adjacent (4-directionally) land cell or walking off the boundary of the grid.

Return the number of land cells in grid for which we cannot walk off the boundary of the grid in any number of moves.
*/

class Solution {
public:
    int n, m;
    vector<pair<int,int>> dir {{0,1}, {1,0}, {0,-1}, {-1,0}};
    bool enclosed(vector<vector<int>> &grid, int i, int j, int& size)
    {
        int x,y;
        bool edge = !(i == 0 || i == n-1 || j == 0 || j == m-1);
        for(auto &[a,b] : dir){
            x = i + a;
            y = j + b;
            if(x >= 0 && y >= 0 && x < n && y < m && grid[x][y] == 1)
            { 
                grid[x][y] = 0;
                size++;
                edge &= enclosed(grid, x, y, size);
            }
        }
         return edge;
    }

    int numEnclaves(vector<vector<int>>& grid) 
    {
        int size, ans = 0;
        n = grid.size();
        m = grid[0].size();
        for(int i = 0; i < n; i++)
        {
            for(int j = 0; j < m; j++)
            {
                size = 1;
                if(grid[i][j] == 1)
                {
                    grid[i][j] = 0;
                    if(enclosed(grid, i, j, size)) ans += size;
                }
            }
        }
        return ans;
    }
};
