/*

Definition for Binary Tree Node
struct Node
{
    int data;
    struct Node* left;
    struct Node* right;

    Node(int x){
        data = x;
        left = right = NULL;
    }
};
*/
int total(Node* root){
    if(root==NULL)
    return 0;
    
    return (1+total(root->left)+total(root->right));
}
class Solution {
  public:
    int getSize(Node* node) {
        int count=total(node);
     return count;
        
    }
};