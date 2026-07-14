/*
class Node {
  public:
    int data;
    Node* left;
    Node* right;

    Node(int val) {
        data = val;
        left = NULL;
        right = NULL;
    }
};
*/

void in(Node*root,vector<int>&ans){
    if(root==NULL)
    return;
    
    in(root->left,ans);
     ans.push_back(root->data);
    in(root->right,ans);
}
class Solution {
  public:
    vector<int> inOrder(Node* root) {
       vector<int>ans;
       in(root,ans);
       return ans;
    }
};