/**
    Problem: https://leetcode.com/problems/minimum-bit-flips-to-convert-number/description/
 */

class Solution {
public:
    int minBitFlips(int start, int goal) {
        int diff = start ^ goal;
        return __builtin_popcountll(diff);
    }
};