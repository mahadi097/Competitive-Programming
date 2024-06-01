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
    int mxRight = 0;
    void modifyList(ListNode* node, ListNode* prevNode) {
        if(!node) return;

        modifyList(node->next, node);
        
        mxRight = max(mxRight, node->val);

        if(mxRight > node->val) prevNode->next = node->next;
    }
public:
    ListNode* removeNodes(ListNode* head) {
        ListNode* preHead = new ListNode(0, head);

        modifyList(head, preHead);

        return preHead->next;
    }
};