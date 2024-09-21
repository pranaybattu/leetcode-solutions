/**
    Problem: https://leetcode.com/problems/shortest-palindrome/description/

 */

class Solution {
public:
    string shortestPalindrome(string s) {
        int sLen = s.size();

        string t = "^";
        for(int i = 0; i < sLen; ++i) {
            t += "#" + s.substr(i, 1);
        }
        t += "#$";

        int tLen = t.size();
        vector<int> p(tLen, 0);

        int c = 0, r = 0;
        bool doesStartWithPal = false;
        int palLen = 0;
        for(int i = 1; i < tLen-1; ++i) {
            p[i] = r > i ? min(r-i, p[2*c-i]) : 0;
            while(i+p[i]+1 < tLen-1 && i-p[i]-1 > 0 && t[i+p[i]+1] == t[i-p[i]-1]) {
                p[i]++;
            }

            if(i+p[i] > r) {
                c = i;
                r = i+p[i];
            }

            if(2*c-r == 1) {
                doesStartWithPal = true;
                palLen = p[c];
            }
        }

        string appendStr(s.rbegin(), s.rend());
        string ans =  appendStr.substr(0, sLen-(palLen)) + s;

        return ans;
    }
};