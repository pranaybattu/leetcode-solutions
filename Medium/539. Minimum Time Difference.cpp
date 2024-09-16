/**
    Problem: https://leetcode.com/problems/minimum-time-difference/
 */

 class Solution {
private:
    int stringToMinutes(string time) {
        int hourToMinute = stoi(time.substr(0, 2)) * 60;
        int minute = stoi(time.substr(3, 2));
        return hourToMinute + minute;
    }
public:
    int findMinDifference(vector<string>& timePoints) {
        sort(timePoints.begin(), timePoints.end());

        int n = timePoints.size();
        int ans = abs(1440 + stringToMinutes(timePoints[0]) - stringToMinutes(timePoints[n-1]));
        for(int i = 1; i < n; ++i) {
            int t1 = stringToMinutes(timePoints[i-1]);
            int t2 = stringToMinutes(timePoints[i]);

            ans = min(ans, abs(t2-t1));
        }

        return ans;
    }
};