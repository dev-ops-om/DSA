/*
class Node {
public:
    int data;
    Node* left;
    Node* right;

    Node(int val) {
        data = val;
        left = nullptr;
        right = nullptr;
    }
};
*/

void Lview(Node *root,int level,vector<int>&ans){
    if(!root)
    return;
    
    if(level==ans.size())
    ans.push_back(root->data);
    
    Lview(root->left,level+1,ans);
    Lview(root->right,level+1,ans);
    
}

class Solution {
  public:
    vector<int> leftView(Node *root) {
         vector<int>ans;
         if(!root)
         return ans;
 Lview(root,0,ans);
 
 return ans;
 
    }
};