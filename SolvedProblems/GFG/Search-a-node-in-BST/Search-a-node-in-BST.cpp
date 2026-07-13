/*
class Node {
    int data;
    Node *left;
    Node *right;

    Node(int x) {
        data = x;
        left = NULL;
        right = NULL;
    }
};
*/

class Solution {
  public:
    bool search(Node* root, int target) {
            if(!root)
    return 0;
    if(root->data==target)
    return 1;


    if(target>root->data)
    return search(root->right,target);
    else 
    return search(root->left,target);
    }
};