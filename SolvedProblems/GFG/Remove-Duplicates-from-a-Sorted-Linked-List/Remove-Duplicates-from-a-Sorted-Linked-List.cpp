/*
struct Node {
  int data;
  struct Node *next;
  Node(int x) {
    data = x;
    next = NULL;
  }
};*/

class Solution {
  public:
    // Function to remove duplicates from sorted linked list.
    Node* removeDuplicates(Node* head) {
      Node *curr=head->next;
      Node *prev=head;
      while(curr){
          if(curr->data==prev->data){
              prev->next=curr->next;
              delete curr;
              curr=prev->next;
          }
          else{
              prev=prev->next;
              curr=curr->next;
          }
      }
      return head;
    }
};