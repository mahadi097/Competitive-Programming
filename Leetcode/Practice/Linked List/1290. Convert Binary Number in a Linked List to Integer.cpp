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
    int getDecimalValue(ListNode* head) {
        return calDecimal(head)[0];
    }

    vector<int> calDecimal(ListNode *node) {
        if(node->next == NULL) return {node->val, 1};

        auto v = calDecimal(node->next);
        return {(node->val*v[1]*2) + v[0], v[1]*2};
    }
};