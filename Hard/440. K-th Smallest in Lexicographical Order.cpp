/**
    Problem: https://leetcode.com/problems/lexicographical-numbers/
 */

class Solution {
private:
    long countSteps(int n, long prefix1, long prefix2) {
        long steps = 0;
        while(prefix1 <= n) {
            steps += min((long)n+1, prefix2) - prefix1;
            prefix1 *= 10;
            prefix2 *= 10;
        }

        return steps;
    }
public:
    int findKthNumber(int n, int k) {
        int num = 1;
        k--;

        while(k > 0) {
            long steps = countSteps(n, num, num+1);
            if(steps <= k) {
                num++;
                k -= steps;
            } else {
                num = num*10;
                k--;
            }
        }

        return num;
    }
};