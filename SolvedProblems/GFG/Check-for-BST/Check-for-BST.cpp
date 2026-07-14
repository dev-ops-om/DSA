/*
class Node {
public:
    int data;
    Node* left;
    Node* right;

    Node(int val) {
        data = val;
        left = right = nullptr;
    }
};
*/

bool BST(Node *root,int &prev){
    if(!root)
       return 1;
       bool l=BST(root->left,prev);
       if(l==0)
       return 0;
       if(root->data<=prev)
       return 0;
       prev=root->data;
     return BST(root->right,prev);
}

class Solution {
  public:
    bool isBST(Node* root) {
      int prev=INT_MIN;
      return BST(root,prev);
    }
};