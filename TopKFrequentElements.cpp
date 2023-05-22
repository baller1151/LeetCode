/*Given an integer array nums and an integer k, return the k most frequent elements. You may return the answer in any order.*/

class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int,int> mp;
        for(auto &x : nums)
            mp[x]++;
    
        priority_queue<pair<int,int>> q;
        for(auto &x : mp)
            q.push({x.second, x.first});

        vector<int> ans;
        while(k--){
            ans.push_back(q.top().second);
            q.pop();
        }

        return ans;
    }
};
