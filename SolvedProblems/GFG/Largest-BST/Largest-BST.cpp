/* Tree node structure  used in the program

struct Node {
    int data;
    Node *left;
    Node *right;

    Node(int val) {
        data = val;
        left = right = NULL;
    }
};*/

class box{
    public:
    bool BST;
    int size;
    int min;
    int max;
    
    box(){
        BST=1;
        size=0;
        min=INT_MAX;
        max=INT_MIN;
    }
};
box *find(Node *root,int &totalsize){
    
    if(!root){
        return new box();
    }
    
    box *lefthead=find(root->left,totalsize);
    box*righthead=find(root->right,totalsize);
    
    if(lefthead->BST && righthead->BST &&lefthead->max<root->data && righthead->min>root->data ){
        
      box *head = new box();

        head->size=1+lefthead->size+righthead->size;
        head->min=min(root->data,lefthead->min);
        head->max=max(root->data,righthead->max);
        totalsize=max(totalsize,head->size);
        return head;
    }
    else{
        lefthead->BST=0;
        return lefthead;
    }
}

class Solution {
  public:
  
   
    /*You are required to complete this method */
    // Return the size of the largest sub-tree which is also a BST
    int largestBst(Node *root) {
        int totalsize=0;
        find(root,totalsize);
        
        return totalsize;
    }
};