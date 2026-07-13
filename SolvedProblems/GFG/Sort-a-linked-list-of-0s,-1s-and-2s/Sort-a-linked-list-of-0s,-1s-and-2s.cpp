/* Node is defined as
  class Node {
  public:
    int data;
    Node* next;

    Node(int x) {
        data = x;
        next = nullptr;
    }
};
*/
class Solution {
public:
    Node* segregate(Node* head) {
        if (head == NULL || head->next == NULL)
            return head;

        // Step 1: Create dummy heads for 0s, 1s, and 2s
        Node* head0 = new Node(-1);
        Node* head1 = new Node(-1);
        Node* head2 = new Node(-1);

        // Step 2: Create tail pointers for each list
        Node* tail0 = head0;
        Node* tail1 = head1;
        Node* tail2 = head2;

        // Step 3: Traverse the original list
        Node* curr = head;
        while (curr) {
            if (curr->data == 0) {
                tail0->next = curr;
                tail0 = tail0->next;
            }
            else if (curr->data == 1) {
                tail1->next = curr;
                tail1 = tail1->next;
            }
            else {
                tail2->next = curr;
                tail2 = tail2->next;
            }
            curr = curr->next;
        }

        // Step 4: Connect all three lists together (simplified)
        // Link 0s → 1s
        tail0->next = head1->next;

        // If no 1s, connect 0s → 2s directly
        if (head1->next == NULL)
            tail0->next = head2->next;

        // Link 1s → 2s
        tail1->next = head2->next;

        // Mark the end of the final list
        tail2->next = NULL;

        // Step 5: Set the new head (skip dummy node)
        Node* newHead = head0->next;

        // Step 6: Delete dummy nodes (optional cleanup)
        delete head0;
        delete head1;
        delete head2;

        return newHead;
    }
};
