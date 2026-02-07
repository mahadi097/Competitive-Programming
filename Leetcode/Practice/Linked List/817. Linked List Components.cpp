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
    int numComponents(ListNode* head, vector<int>& nums) {
        int ans = 0, prv = 0;

        vector <int> f(10000, 0);
        for(int i = 0; i < nums.size(); i++) f[nums[i]] = 1;

        ListNode *cur = head;
        while(cur) {
            int v = cur->val;

            if(!f[v]) prv = 0;
            else {
                if(!prv) ans++;
                prv = 1;
            }

            cur = cur->next;
        }

        return ans;
    }
};
