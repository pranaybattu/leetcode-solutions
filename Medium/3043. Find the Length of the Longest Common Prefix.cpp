/**
    Problem: https://leetcode.com/problems/lexicographical-numbers/
 */


class TrieNode {
public:
    unordered_map<int, TrieNode*> children;
    bool isNum;
};

class Solution {
private:
    
    TrieNode* bildTrie(vector<int>& arr) {
        TrieNode* root = new TrieNode();

        for(int& num: arr) {
            TrieNode* node = root;
            vector<int> digits;
            while(num > 0) {
                int digit = num%10;
                num = num/10;
                digits.push_back(digit);
            }

            for(int i = digits.size() - 1; i >= 0; --i) {
                int digit = digits[i];
                if(node->children.find(digit) == node->children.end()) {
                    node->children[digit] = new TrieNode();
                }
                node = node->children[digit];
            }

            node->isNum = true;
        }
        return root;
    }
public:
    int longestCommonPrefix(vector<int>& arr1, vector<int>& arr2) {
        TrieNode* root2 = bildTrie(arr2);

        int ans = 0;
        for(int& num: arr1) {
            int prefixLen = 0;
            TrieNode* node = root2;
            vector<int> digits;
            while(num > 0) {
                int digit = num%10;
                num = num/10;
                digits.push_back(digit);
            }
            for(int i = digits.size() - 1; i >= 0; --i) {
                int digit = digits[i];
                if(node->children.find(digit) == node->children.end()) {
                    break;
                }
                node = node->children[digit];
                prefixLen++;
            }
            
            cout<<num<<" "<<prefixLen<<"\n";

            ans = max(ans, prefixLen);
        }

        return ans;
    }
};