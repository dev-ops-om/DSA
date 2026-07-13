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
    Node* insert(Node* root, int target) {
       if(!root){
        Node *temp=new Node( target);
        return temp;

    }
    if(target<root->data){
        root->left=insert(root->left,target);

    }
    else{
        root->right=insert(root->right,target);

    }
    return root;
    }
};