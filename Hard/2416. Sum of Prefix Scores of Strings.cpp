/**
    Problem: https://leetcode.com/problems/lexicographical-numbers/description/
 */


class TrieNode {
public:
    unordered_map<char, TrieNode*> children;
    int counter = 0;
};

class Solution {
private:
    TrieNode* root;
    void buildTrie(vector<string>& words) {
        root = new TrieNode();
        for(string& w: words) {
            TrieNode* node = root;
            for(char& c: w) {
                if(node->children.find(c) == node->children.end()) {
                    node->children[c] = new TrieNode();
                }
                node->children[c]->counter++;
                node = node->children[c];
            }

        }
    }

    vector<int> prefixScores(vector<string>& words) {
        int n = words.size(), i = 0;
        vector<int> ans(n);
        for(string& w: words) {
            TrieNode* node = root;
            int cnt = 0;
            for(char& c: w) {
                cnt += node->children[c]->counter;
                node = node->children[c];
            }

            ans[i++] = cnt;
        }

        return ans;
    }
public:
    vector<int> sumPrefixScores(vector<string>& words) {
        buildTrie(words);
        return prefixScores(words);
    }
};