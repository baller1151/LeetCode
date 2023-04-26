/*
A chef has collected data on the satisfaction level of his n dishes. Chef can cook any dish in 1 unit of time.

Like-time coefficient of a dish is defined as the time taken to cook that dish including previous dishes multiplied by its satisfaction level i.e. time[i] * satisfaction[i].

Return the maximum sum of like-time coefficient that the chef can obtain after dishes preparation.

Dishes can be prepared in any order and the chef can discard some dishes to get this maximum value.
*/

class Solution {
public:
    int maxSatisfaction(vector<int>& satisfaction) {
        int n = satisfaction.size(), num, mx = 0;
        vector<int> ans, size(n,0);
        sort(satisfaction.begin(), satisfaction.end());
        if(satisfaction[n-1] < 0)
            return 0;
        for(int i = 0; i < n; i++){
            num = satisfaction[i];
            for(int j = 0; j < n && size[j] != 0; j++){
                size[j]++;
                ans[j] += num*size[j];
            }
            size[i] = 1;
            ans.push_back(num);
        }
        for(auto &x : ans){
            mx = max(x, mx);
        }
        return mx;
    }
};
