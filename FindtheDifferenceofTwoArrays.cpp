/*
Given two 0-indexed integer arrays nums1 and nums2, return a list answer of size 2 where:
answer[0] is a list of all distinct integers in nums1 which are not present in nums2.
answer[1] is a list of all distinct integers in nums2 which are not present in nums1.
Note that the integers in the lists may be returned in any order.
*/

class Solution {
public:
    vector<vector<int>> findDifference(vector<int>& nums1, vector<int>& nums2) {
        unordered_set<int> st1(nums1.begin(), nums1.end());
        unordered_set<int> st2(nums2.begin(), nums2.end());

        vector<int> vec1, vec2;
                
        for(auto &x : st1){
            if(st2.find(x) == st2.end())
                vec1.push_back(x);
        }
        
        for(auto &x : st2){
            if(st1.find(x) == st1.end())
                vec2.push_back(x);
        }

        return {vec1, vec2};
    }
};
