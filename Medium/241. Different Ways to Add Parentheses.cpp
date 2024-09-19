/**
    Problem: https://leetcode.com/problems/uncommon-words-from-two-sentences/
 */

class Solution {
private:
    unordered_map<string, vector<int>> m;
public:
    vector<int> diffWaysToCompute(string expression) {
        if(m.find(expression) != m.end()) {
            return m[expression];
        }

        vector<int> ans;

        for(int i = 0; i < expression.length(); ++i) {
            char ch = expression[i];

            if(ch == '*' || ch == '+' || ch == '-') {
                vector<int> left = diffWaysToCompute(expression.substr(0, i));
                vector<int> right = diffWaysToCompute(expression.substr(i + 1));
            
                for (int& l: left) {
                    for (int& r: right) {
                        if (ch == '+') {
                            ans.push_back(l + r);
                        } else if (ch == '-') {
                            ans.push_back(l - r);
                        } else if (ch == '*') {
                            ans.push_back(l * r);
                        }
                    }
                }
            }

        }

        if(ans.empty()) {
            ans.push_back(stoi(expression));
        }
        
        m[expression] = ans;
        return ans;
    }
};