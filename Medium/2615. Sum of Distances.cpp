/**
    Problem: https://leetcode.com/problems/sum-of-distances/description/
 */

class Solution {
public:
    vector<long long> distance(vector<int>& nums) {
        int n = nums.size();
        unordered_map<int, vector<int>> m;
        for(int i = 0; i < n; ++i) {
            m[nums[i]].push_back(i);
        }

        vector<long long> ans(n, 0);
        for(auto it: m) {
            auto v = it.second;
            long long val = 0;
            for(int i = 1; i < v.size(); ++i) {
                val += abs(v[i] - v[0]);
            }

            ans[v[0]] = val;
            for(int i = 1; i < v.size(); ++i) {
                val = val + (v[i] - v[i-1]) * ((i-1) - (v.size() - i - 1));
                int idx = v[i];
                ans[idx] = val;
            }
        }

        return ans;
    }
};