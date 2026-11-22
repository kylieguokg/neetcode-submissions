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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        // get length
        ListNode* cur = head;
        int length = 0;
        while (cur) {
            length += 1;
            cur = cur->next;
        }

        int nIdx = length - n;
        if (nIdx == 0){
            if (length > 1){
                return head->next;
            } else {
                return nullptr;
            }
        }
        int i = 1;
        cur = head;
        while (i < nIdx) {
            cur = cur->next;
            i += 1;
        }

        ListNode* temp = cur;
        cur = cur->next;
        temp->next = cur->next;
        return head;
    }
};
