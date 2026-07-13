// User function Template for C++

class Solution {
  public:
    void flatten(Node *root) {
  
  while(root){
      if(!root->left){
       root=root->right;   
      }
      else{
          Node *curr=root->left;
          while(curr->right)
          curr=curr->right;
          curr->right=root->right;
          root->right=root->left;
          root->left=NULL;
          root=root->right;
      }
  }
        
    }
};