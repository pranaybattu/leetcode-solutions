/**
Problem: https://leetcode.com/problems/spiral-matrix-iv/
*/

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
private:
    void reduceLimits(int& left, int& right, int& top, int& bottom, int k) {
        if (k == 0) top++;
        else if (k == 1) right--;
        else if (k == 2) bottom--;
        else left++;
    }
public:
    vector<vector<int>> spiralMatrix(int m, int n, ListNode* head) {
        int top = 0;
        int bottom = m-1;
        int left = 0;
        int right = n-1;

        vector<vector<int>> ans(m, vector<int>(n, -1));

        int i = 0, j = 0, k = 0;
        int X[4] = {0, 1, 0, -1};
        int Y[4] = {1, 0, -1, 0};
        while(head != NULL) {
            ans[i][j] = head->val;
            head = head->next;

            if(i +X[k] > bottom || i + X[k] < top || j + Y[k] < left || j + Y[k] > right) {
                reduceLimits(left, right, top, bottom, k);
                k++;
                k = k % 4;
            }
            i = i + X[k];
            j = j + Y[k];
        }

        return ans;
    }
};