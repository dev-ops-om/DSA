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
Node* reverse(Node* curr, Node *prev) {
    if (curr == NULL) {
        return prev;
    }
    Node *front = curr->next;
    curr->next = prev;
    return reverse(front, curr);
}

class Solution {
  public:
    Node* addTwoLists(Node* head1, Node* head2) {

        head1 = reverse(head1, NULL);
        head2 = reverse(head2, NULL);

        Node* curr1 = head1;
        Node* curr2 = head2;
        Node* head = new Node(0);  // dummy node
        Node* tail = head;

        int carry = 0;
        int sum;

        while (curr1 && curr2) {
            sum = curr1->data + curr2->data + carry;
            tail->next = new Node(sum % 10);
            tail = tail->next;
            carry = sum / 10;
            curr1 = curr1->next;
            curr2 = curr2->next;
        }

        while (curr1) {
            sum = curr1->data + carry;
            tail->next = new Node(sum % 10);
            tail = tail->next;
            carry = sum / 10;
            curr1 = curr1->next;
        }

        while (curr2) {
            sum = curr2->data + carry;   // fixed: no 'int' redeclaration
            tail->next = new Node(sum % 10);
            tail = tail->next;
            carry = sum / 10;
            curr2 = curr2->next;
        }

        while (carry) {
            tail->next = new Node(carry % 10);
            tail = tail->next;
            carry /= 10;
        }

        // reverse the result list (skip dummy first)
        head = reverse(head->next, NULL);

        // remove leading zeros (but leave one node if result is actually zero)
        while (head && head->data == 0 && head->next) {
            head = head->next;
        }

        return head;
    }
};
