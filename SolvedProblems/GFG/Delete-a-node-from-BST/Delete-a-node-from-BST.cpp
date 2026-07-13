/*
class Node {
public:
    int data;
    Node* left;
    Node* right;

    Node(int val) {
        data = val;
        left = right = NULL;
    }
};
*/

class Solution {
  public:
    Node* delNode(Node* root, int target) {
    if(!root)
    return NULL;
    
    if(root->data>target)
  root->left=delNode(root->left,target);
  
 else if(root->data<target)
  root->right=delNode(root->right,target);
  
  else{
      //leaf node
      if(!root->left && !root->right){
          delete root;
          return NULL;
      }
      //one child
    else if(!root->right){
    Node *temp = root->left;
    delete root;
    return temp;
}
else if(!root->left){
    Node *temp = root->right;
    delete root;
    return temp;
}
 //two child
          else{
              Node *child =root->left;
              Node *parent=root;
              while(child->right){
                  parent=child;
                  child=child->right;
                  
              }
              if(root!=parent){
                  parent->right=child->left;
                  child->left=root->left;
                  child->right=root->right;
                  delete root;
                  return child;
                  }
                  else{
                      child->right=root->right;
                      delete root;
                      return child;
                  }
          }
      }
    
    return root;
      
  }
        
    
};