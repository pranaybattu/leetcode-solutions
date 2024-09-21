/**
    Problem: https://leetcode.com/problems/lexicographical-numbers/description/
 */

class Solution {
private:
    vector<int> ans;
    void findNextNum(int num, int n) {
        if(num != 0) ans.push_back(num);
        for(int i = num == 0 ? 1 : 0; i < 10; ++i) {
            int nextNum = num*10+i;
            if(nextNum > n) {
                break;
            }
            findNextNum(nextNum, n);

        }
    }
public:
    
    vector<int> lexicalOrder(int n) {
        findNextNum(0, n);
        return ans;
    }
};