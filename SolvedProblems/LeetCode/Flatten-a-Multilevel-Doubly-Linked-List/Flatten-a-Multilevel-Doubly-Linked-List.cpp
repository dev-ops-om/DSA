/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* prev;
    Node* next;
    Node* child;
};
*/

class Solution {
public:
    Node* flatten(Node* head) {
        if (head == NULL) return NULL;

        Node* curr = head;

        while (curr != NULL) {
            if (curr->child != NULL) {
                Node* next = curr->next;

                // Flatten the child list
                Node* child = flatten(curr->child);
                curr->next = child;
                child->prev = curr;
                curr->child = NULL;

                // Move to the end of the flattened child list
                while (curr->next != NULL) {
                    curr = curr->next;
                }

                // Reconnect the next node
                if (next != NULL) {
                    curr->next = next;
                    next->prev = curr;
                }
            }

            curr = curr->next;
        }

        return head;
    }
};