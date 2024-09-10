/**
    Problem: https://leetcode.com/problems/insert-greatest-common-divisors-in-linked-list/description/
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
public:
    ListNode* insertGreatestCommonDivisors(ListNode* head) {
        if(!head || !head->next) return head;

        ListNode* curr = head, *next = head->next;
        int gcd = __gcd(curr->val, next->val);
        ListNode* newNode = new ListNode(gcd, next);
        curr->next = newNode;
        insertGreatestCommonDivisors(next);

        return curr;
    }
};