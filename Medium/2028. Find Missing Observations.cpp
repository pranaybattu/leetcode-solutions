/**
Problem: https://leetcode.com/problems/find-missing-observations/
*/

class Solution {

public:
    vector<int> missingRolls(vector<int>& rolls, int mean, int n) {
        int m = rolls.size();
        int t = n+m;

        int rollsSum = accumulate(rolls.begin(), rolls.end(), 0);
        int missingSum = mean * t - rollsSum;
        if(missingSum > 6*n || missingSum < n) {
            return {};
        }
        vector<int> ans(n, missingSum/n);
        int rem = missingSum%n;
        for(int i = 0; i < rem; ++i) ans[i]++;

        return ans;
    }
};