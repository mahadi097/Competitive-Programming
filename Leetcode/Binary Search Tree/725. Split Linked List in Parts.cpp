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
    vector<ListNode*> splitListToParts(ListNode* head, int k) {
        vector <ListNode*> ans;
        ListNode* cur = head;
        int n = 0;

        while(cur) n++, cur = cur->next;

        int partSize = n / k;
        int rem = n % k;

        int i = 0, cnt = 0;
        cur = head;
        while(cur) {
            cnt++;
            ListNode* nxt = cur->next;

            if(cnt == 1) {
                i++;
                ans.push_back(cur);
            }

            if((i <= rem and cnt == partSize+1) or (i > rem and cnt == partSize)) {
                cur->next = NULL;
                cnt = 0;
            }

            cur = nxt;
        }

        while(i < k) i++, ans.push_back(NULL);

        return ans;
    }
};
