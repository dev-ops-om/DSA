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

void Rview(Node *root,int level,vector<int>&ans){
    if(!root)
    return;
    
    if(level==ans.size())
    ans.push_back(root->data);
    
  
    Rview(root->right,level+1,ans);
      Rview(root->left,level+1,ans);
    
}

class Solution {
  public:
    vector<int> rightView(Node *root) {
  vector<int>ans;
         if(!root)
         return ans;
 Rview(root,0,ans);
 
 return ans;
        
    }
};