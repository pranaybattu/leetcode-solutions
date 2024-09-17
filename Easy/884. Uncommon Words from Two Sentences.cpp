/**
    Problem: https://leetcode.com/problems/uncommon-words-from-two-sentences/

    stringstream: https://www.geeksforgeeks.org/how-to-split-a-string-in-cc-python-and-java/
 */

 class Solution {
public:
    vector<string> uncommonFromSentences(string s1, string s2) {
        string s = s1 + " " + s2;
        stringstream str(s);

        unordered_map<string, int> m;
        string temp;
        while(str >> temp) {
            m[temp]++;
        }

        vector<string> ans;
        for(auto& it: m) {
            if(it.second == 1) {
                ans.push_back(it.first);
            }
        }

        return ans;
    }
};