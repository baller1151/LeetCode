/*
There are a total of numCourses courses you have to take, labeled from 0 to numCourses - 
1. You are given an array prerequisites where prerequisites[i] = [ai, bi] indicates that you must take course bi first if you want to take course ai.

For example, the pair [0, 1], indicates that to take course 0 you have to first take course 1.
Return the ordering of courses you should take to finish all courses. If there are many valid answers, return any of them. 
If it is impossible to finish all courses, return an empty array.
*/
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
