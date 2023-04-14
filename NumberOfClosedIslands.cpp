class Solution {
public:
    vector<pair<int,int>> dir{{0,1},{0,-1},{1,0},{-1,0}};
    int n, m;

    //returns true if island is closed
    bool isClosed(vector<vector<int>>& grid, int i, int j){
        int x, y;

        //check if grid[i][j] is an edge
        bool closed = !(i == 0 || i == n-1 || j == 0 || j == m-1); 
 
        //find all 0's connected 4-directionally
        for(auto &[a, b] : dir){
            int x = i + a;
            int y = j + b;
            
            if(x >= 0 && y >= 0 && x < n && y < m && grid[x][y] == 0){
                grid[x][y] = 1;
                closed = isClosed(grid, x, y) && closed;  
            }
        }

        return closed;
    }
    int closedIsland(vector<vector<int>>& grid) {
        n = grid.size(), m = grid[0].size();
        int ans = 0;
        //find all islands
        for(int i = 0; i < n; i++){
            for(int j = 0; j < m; j++){
                if(grid[i][j] == 0){
                    grid[i][j] = 1;
                    
                    //add to ans if island is closed
                    if(isClosed(grid, i, j)) ans++;
                }
            }
        }
        return ans;
    }
};
