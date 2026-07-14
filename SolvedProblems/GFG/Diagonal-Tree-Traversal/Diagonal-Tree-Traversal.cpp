/* A binary tree node
struct Node
{
    int data;
    Node* left, * right;
}; */

void find(Node*root,int pos,int &l){
    if(!root)
    return;
    l=max(pos,l);
    find(root->left,pos+1,l);
    find(root->right,pos,l);
}
void finddig(Node *root,int pos,vector<vector<int>>&ans){
    if(!root)
    return;
    ans[pos].push_back(root->data);
    finddig(root->left,pos+1,ans);
    finddig(root->right,pos,ans);
}
class Solution {
  public:
    vector<int> diagonal(Node *root) {
    int l=0;
    find(root,0,l);
    vector<vector<int>>ans(l+1);
    finddig(root,0,ans);
    vector<int>temp;
    for(int i=0;i<ans.size();i++){
        for(int j=0;j<ans[i].size();j++)
        {
            temp.push_back(ans[i][j]);
        }
    }
    return temp;
    }
};