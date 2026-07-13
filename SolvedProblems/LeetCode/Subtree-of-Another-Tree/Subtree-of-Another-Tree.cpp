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
 bool isSameTree(TreeNode* p, TreeNode* q) {
        if(p==NULL && q==NULL)
        return 1;

        if((!p && q ) || ( p&&!q))
        return 0;

        if(p->val !=q->val)
        return 0;

        return isSameTree(p->left,q->left) &&  isSameTree(p->right,q->right);
    }
class Solution {
public:
    bool isSubtree(TreeNode* root, TreeNode* subRoot) {

        if((root ==NULL )|| (subRoot ==NULL))
        return (root==subRoot);
        
        if((root->val ==subRoot->val) && isSameTree(root,subRoot))
        return true;


      return ( isSubtree(root->left,subRoot) || isSubtree(root->right,subRoot));
    }
};