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
    ListNode* mergeInBetween(ListNode* list1, int a, int b, ListNode* list2) {
        ListNode *cur = list1, *cur2 = list2, *tail2 = list2, *nxt;

        while(1) {
            if(!cur2->next) {
                tail2 = cur2;
                break;
            }
            cur2 = cur2->next;
        }

        int i = -1;
        while(cur) {
            i++;
            nxt = cur->next;

            if(i == a-1) cur->next = list2;
            if(i == b+1) tail2->next = cur;

            cur = nxt;
        }

        return list1;
    }
};
