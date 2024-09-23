/**
    Problem: https://leetcode.com/problems/lexicographical-numbers/description/
 */

class TrieNode {
public:
    unordered_map<char, TrieNode*> m; 
    bool isWord;
};

class Solution {
private:
    TrieNode* root;
    void buildTrie(vector<string>& dictionary) {
        root = new TrieNode();
        for(string& word: dictionary) {
            TrieNode* node = root;
            for(char& ch: word) {
                if(node->m.find(ch) == node->m.end()) {
                    node->m[ch] = new TrieNode();
                }
                node = node->m[ch];
            }
            node->isWord = true;
        }
    }

    int solve(string& s, vector<int>& dp, int n, int idx) {
        if(idx == n) return 0;

        if(dp[idx] != INT_MAX) return dp[idx];
        TrieNode* node = root;
        dp[idx] = 1+solve(s, dp, n, idx+1);
        for(int i = idx; i < n; ++i) {
            if(node->m.find(s[i]) == node->m.end()) {
                break;
            }
            node = node->m[s[i]];
            if(node->isWord == true) {
                dp[idx] = min(dp[idx], solve(s, dp, n, i+1));
            }
        }

        return dp[idx];
    }

public:
    int minExtraChar(string s, vector<string>& dictionary) {
        int n = s.size();
        buildTrie(dictionary);

        vector<int> dp(n, INT_MAX);
        solve(s, dp, n, 0);
        return dp[0];
    }
};