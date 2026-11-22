/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;

    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/

class Solution {
   public:
    Node* copyRandomList(Node* head) {
        if (!head){
            return nullptr;

        }

        Node* cur = head;
        unordered_map<Node*, Node*> copies;

        // create copies
        while (cur) {
            copies[cur] = new Node(cur->val);
            cur = cur->next;
        }

        // copy random next
        cur = head;
        while (cur) {
            Node* newCur = copies[cur];
            newCur->next = copies[cur->next];
            newCur->random = copies[cur->random];

            cur = cur -> next;
        }
        return copies[head];
    }
};
