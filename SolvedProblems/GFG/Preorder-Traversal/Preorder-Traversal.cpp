/*
class Node
{
    int data;
    Node* left;
    Node* right;

    Node(int x){
        data = x;
        left = right = NULL;
    }
};
*/
void pre(Node*root,vector<int>&ans){
    if(root==NULL)
    return;
    ans.push_back(root->data);
    pre(root->left,ans);
    pre(root->right,ans);
}
class Solution {
  public:
    vector<int> preOrder(Node* root) {
       vector<int>ans;
       pre(root,ans);
       return ans;
    }
};