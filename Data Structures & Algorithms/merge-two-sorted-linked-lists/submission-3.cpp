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
        if (list1 == nullptr){
            return list2;
        }
        if (list2 == nullptr){
            return list1;
        }

        ListNode* newHead;
        ListNode* a;
        ListNode* b;
        if (list1->val <= list2->val){
            newHead = list1;
            a = list1->next;
            b = list2;
        } else {
            newHead = list2;
            a = list2->next;
            b = list1;
        }
        ListNode* cur = newHead;

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

        return newHead;
    }
};
