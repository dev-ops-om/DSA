/* A binary tree node has data, pointer to left child
   and a pointer to right child
struct Node
{
    int data;
    struct Node* left;
    struct Node* right;

    Node(int x){
        data = x;
        left = right = NULL;
    }
}; */

// Function to return a list containing the level order traversal in spiral form.

void total(Node*root,int &sum){
    if(root==NULL)
    return ;
    
    sum+=root->data;
    total(root->left,sum);
    total(root->right,sum);
}
class Solution {
  public:
    int sumBT(Node* root) {
        int sum=0;
    total(root,sum);
      return sum;
    }
};