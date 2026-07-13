/*
class Node {
  public:
    int data;
    Node* next;

    Node(int val) {
        data = val;
        next = nullptr;
    }
};
*/
class Solution {
  public:
    void removeLoop(Node* head) {
      Node *slow=head;
      Node *fast=head;
      while(fast!=NULL && fast->next!=NULL){
          slow=slow->next;
          fast=fast->next->next;
          
          if(slow==fast){
            break;
          }
      }
      if(fast==NULL || fast->next==NULL){
          return;
      }
      slow=fast->next;
      int count=1;
      while(slow!=fast){
          count++;
          slow=slow->next;
      }

     slow=head,fast=head;
     while(count--){
         fast=fast->next;
     }
        
        while(slow!=fast){
            slow=slow->next;
            fast=fast->next;
        };
        while(slow->next!=fast){
            slow=slow->next;
        }
            slow->next=NULL;
        
    }
};