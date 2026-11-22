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
    void reorderList(ListNode* head) {
        if (!head || !head->next){
            return;
        }

        int length = 0;
        ListNode* cur = head;
        while (cur){
            length += 1;
            cur = cur->next;
        }

        ListNode* firstHalfPtr = head;
        cur = head;
        int i = 0;
        while (i < (length - 1)/2){
            cur = cur->next;
            i += 1;
        }
        ListNode* secondHalfPtr = cur->next;
        cur->next = nullptr;
        secondHalfPtr=reverseList(secondHalfPtr);

        while (secondHalfPtr){        
            ListNode* temp1 = firstHalfPtr->next;
            ListNode* temp2 = secondHalfPtr->next;

            firstHalfPtr->next = secondHalfPtr;
            secondHalfPtr->next = temp1;

            firstHalfPtr = temp1;
            secondHalfPtr = temp2;
        }
    }

    ListNode* reverseList(ListNode* head){
        ListNode* cur = head;
        ListNode* prev = nullptr;
        while (cur){
            ListNode* temp = cur->next;
            cur->next = prev;

            prev = cur;
            cur = temp;
        }
        return prev;
    }
};
