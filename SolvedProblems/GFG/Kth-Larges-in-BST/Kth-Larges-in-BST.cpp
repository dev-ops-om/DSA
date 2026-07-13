/*The Node structure is defined as
struct Node {
    int data;
    Node *left;
    Node *right;

    Node(int val) {
        data = val;
        left = right = NULL;
    }
};
*/

// return the Kth largest element in the given BST rooted at 'root'

void ksum(Node *root,int &sum,int &k){
    if(!root)
    return;
    
   ksum(root->right,sum,k);
    k--;
    if(k==0)
    sum=root->data;
   
      ksum(root->left,sum,k);
}
class Solution {
  public:
    int kthLargest(Node *root, int k) {
     
        int sum=0;
ksum(root,sum,k);
return sum;
    }
};