// Given an integer numRows, return the first numRows of Pascal's triangle.

class Solution {
public:
    vector<vector<int>> generate(int numRows) {
        if(numRows == 1){
            return {{1}};
        }
        vector<vector<int>> dp{{1},{1,1}};
        vector<int> temp;
        for(int i = 2; i < numRows; i++){
            temp.push_back(1);
            for(int j = 1; j < i; j++){
                temp.push_back(dp[i-1][j-1] + dp[i-1][j]);
            }
            temp.push_back(1);
            dp.push_back(temp);
            temp.clear();
        }
        return dp;

    }
};
