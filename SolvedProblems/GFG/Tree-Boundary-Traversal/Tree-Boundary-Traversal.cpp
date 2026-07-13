/*
class Node {
  public:
    int data;
    Node* left;
    Node* right;

    // Constructor to initialize a new node
    Node(int val) {
        data = val;
        left = NULL;
        right = NULL;
    }
};
*/

void leftsub(Node *root,vector<int>&ans){
    
    if(!root || (!root->left &&!root->right))
    return;
    ans.push_back(root->data);
    if(root->left)
    leftsub(root->left,ans);
    else
    leftsub(root->right,ans);
}

void leaf(Node *root,vector<int>&ans){
    if(!root)
    return;
    
    if(!root->left && !root->right){
        ans.push_back(root->data);
        return;
    }
    leaf(root->left,ans);
    leaf(root->right,ans);
}

void rightsub(Node *root,vector<int>&ans){
    if(!root || (!root->left && !root->right))
    return;
    
    if(root->right)
    rightsub(root->right,ans);
    else
    rightsub(root->left,ans);
    
    ans.push_back(root->data);
}

class Solution {
  public:
    vector<int> boundaryTraversal(Node *root) {
       
        vector<int>ans;
        ans.push_back(root->data);
        leftsub(root->left,ans);
        
        if(root->left || root->right)
        leaf(root,ans);
        rightsub(root->right,ans);
        
        return ans;
        
    }
};