/**
 Problem: https://leetcode.com/problems/find-the-longest-substring-containing-vowels-in-even-counts
 */


class Solution {
public:
    int findTheLongestSubstring(string s) {
        vector<int> maskFirstSeen(32, -2); // same mask seen at position - i 
        maskFirstSeen[0] = -1; // to find length which is valid from start till i

        int maxLen = 0;
        int mask = 0;
        for(int i = 0; i < s.size(); ++i) {
            char c = s[i];
            switch (c) {
                case 'a':
                    mask ^= 1;
                    break;
                case 'e':
                    mask ^= 2;
                    break;
                case 'i':
                    mask ^= 4;
                    break;
                case 'o':
                    mask ^= 8;
                    break;
                case 'u':
                    mask ^= 16;
                    break;
            }

            int firstSeen = maskFirstSeen[mask];
            if(firstSeen == -2) {
                maskFirstSeen[mask] = i; // as this is first seen
            } else {
                maxLen = max(maxLen, i - firstSeen);
            }
        } 

        return maxLen;
    }
};