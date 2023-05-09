/*Given an m x n matrix, return all elements of the matrix in spiral order.*/
class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix)
    {
        vector<int> nums;
        int i = 0, j = 0, c = 0;
        int m = matrix.size();
        int n = matrix[0].size();
        while(j < n-c){
            for(; j < n - c; j++)
                nums.push_back(matrix[i][j]);
            i++;
            j--;

            if(i >= m-c) break;
            for(; i < m - c; i++)
                nums.push_back(matrix[i][j]);
            j--;
            i--;
            
            if(j < 0 + c) break;
            for(; j >= 0 + c; j--)
                nums.push_back(matrix[i][j]);
            i--;
            j++;
            c++;

            if(i < 0 + c) break;
            for(; i >= 0 + c; i--)
                nums.push_back(matrix[i][j]);
            j++;
            i++;
        }
        return nums;


        
    }
};
