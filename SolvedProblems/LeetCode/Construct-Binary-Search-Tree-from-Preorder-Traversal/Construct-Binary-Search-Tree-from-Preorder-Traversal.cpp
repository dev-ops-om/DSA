/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */

TreeNode *BST(vector<int>preorder,int &index,int lower,int upper){
    if(index==preorder.size()|| preorder[index]<lower || preorder[index]>upper)
    return NULL;

    TreeNode *root=new TreeNode(preorder[index++]);
    root->left=BST(preorder,index,lower,root->val);
    root->right=BST(preorder,index,root->val,upper);

    return root;

}
class Solution {
public:
    TreeNode* bstFromPreorder(vector<int>& preorder) {
int upper=INT_MAX;
int lower=INT_MIN;
int index=0;

return BST(preorder,index,lower,upper);
        
    }
};