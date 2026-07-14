/*
class Node {
public:
    int data;
    Node* next;

    Node(int x) {
        data = x;
        next = NULL;
    }
};
*/

class Solution {
  public:
    Node* intersectPoint(Node* head1, Node* head2) {
        // Step 1: Create a cycle in list1
        Node *curr1 = head1;
        while (curr1->next != NULL) {
            curr1 = curr1->next;
        }
        curr1->next = head1;

        // Step 2: Detect cycle in list2
        Node *slow = head2;
        Node *fast = head2;
        while (fast != NULL && fast->next != NULL) {
            slow = slow->next;
            fast = fast->next->next;

            if (slow == fast) {
                break;
            }
        }

        // Step 3: If no cycle detected, return NULL
        if (fast == NULL || fast->next == NULL) {
            curr1->next = NULL; // Restore original structure
            return NULL;
        }

        // Step 4: Find start of cycle (intersection point)
        slow = head2;
        while (slow != fast) {
            slow = slow->next;
            fast = fast->next;
        }

        curr1->next = NULL; // Restore original structure
        return slow;
    }
};