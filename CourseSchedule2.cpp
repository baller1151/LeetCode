class Solution {
public:
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        vector<unordered_set<int>> pre(numCourses), pos(numCourses);
        queue<int> q;
        vector<int> ans;
        vector<bool> taken(numCourses, false);
        int temp;
        for(auto &x : prerequisites){
            pre[x[0]].insert(x[1]);
            pos[x[1]].insert(x[0]);
        }
        for(int i = 0; i < pre.size(); i++){
            if(pre[i].empty())
                q.push(i);
        }
        while(!q.empty()){
            temp = q.front();
            q.pop();
            ans.push_back(temp);
            for(auto &it : pos[temp]){
                auto x = &pre[it];
                x->erase(x->find(temp));
                if(x->empty()){
                    q.push(it);
                }

            }
        }
        return ans.size() == numCourses ? ans : vector<int>();

    }
};
