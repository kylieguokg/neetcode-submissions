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
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        ListNode* a = list1;
        ListNode* b = list2;
        ListNode dummy(0);
        ListNode* cur = &dummy;

        while (a != nullptr && b != nullptr){
            if (a->val <= b->val){
                cur->next = a;
                a = a->next;
            } else {
                cur->next = b;
                b = b->next;
            }
            cur = cur->next;
        }

        // take the rest of the remaining list and add it to end of cur
        if (a != nullptr){
            cur->next = a;
        } else {
            cur->next = b;
        }

        return dummy.next;
    }
};
