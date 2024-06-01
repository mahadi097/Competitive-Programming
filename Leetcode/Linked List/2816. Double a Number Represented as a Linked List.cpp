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
    int solve(ListNode* node) {
        if(!node) return 0;
        int carry = solve(node->next);
        int val = (node->val * 2) + carry;
        node->val = val % 10;
        return val >= 10;
    }
public:
    ListNode* doubleIt(ListNode* head) {
        int carry = solve(head);
        if(carry) {
            ListNode* preHead = new ListNode(1, head);
            return preHead;
        }
        return head;
    }
};