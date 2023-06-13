/* Given a 0-indexed n x n integer matrix grid, return the number of pairs (ri, cj) such that row ri and column cj are equal.

A row and column pair is considered equal if they contain the same elements in the same order (i.e., an equal array). */
class Solution {
public:
    int equalPairs(vector<vector<int>>& grid) {
        map<vector<int>, int> mp;
        int ans, row = grid.size(), col = row;

        for(int i  = 0; i < row; i++)
            mp[grid[i]]++;

        vector<int> temp;
        for(int i = 0; i < col; i++){
            for(int j = 0; j < row; j++){
                temp.push_back(grid[j][i]);
            }
            ans += mp[temp];
            temp.clear();
        }
        return ans;

    }
};
