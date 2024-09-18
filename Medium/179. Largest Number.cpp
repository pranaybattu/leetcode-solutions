/**
    Problem: https://leetcode.com/problems/largest-number/
 */

 class Solution {
public:
    string largestNumber(vector<int>& nums) {
        auto cmp = [](int& a, int& b) {
            string sa = to_string(a);
            string sb = to_string(b);

            return (sa+sb) > (sb+sa);
        };
        sort(nums.begin(), nums.end(), cmp);
        if(nums[0] == 0) {
            return "0";
        }

        string ans = "";
        for(int& num: nums) {
            ans += to_string(num);
        }

        return ans;
    }
};