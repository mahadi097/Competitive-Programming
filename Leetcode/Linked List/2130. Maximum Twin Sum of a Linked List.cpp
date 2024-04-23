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
    int pairSum(ListNode* head) {
        int n = 0;

        ListNode *prv = NULL, *cur = head, *head2, *cur2;

        while(1) {
            n++;
            ListNode *nxt = cur->next;
            ListNode *now = new ListNode(cur->val);

            if(prv) now->next = prv;

            if(!nxt) {
                head2 = now;
                break;
            }

            prv = now;
            cur = nxt;
        }

        int i = 0, ans = 0;
        cur = head, cur2 = head2;

        while(i < n/2) {
            ans = max(ans, cur->val+cur2->val);

            cur = cur->next, cur2 = cur2->next;
            i++;
        }

        return ans;
    }
};
