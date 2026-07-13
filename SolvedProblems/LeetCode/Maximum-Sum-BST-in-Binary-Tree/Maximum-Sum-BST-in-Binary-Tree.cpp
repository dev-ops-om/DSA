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
class box {
public:
    bool BST;
    int sum;
    int min;
    int max;

    box() {
        BST = true;
        sum = 0;
        min = INT_MAX;
        max = INT_MIN;
    }
};

class Solution {
public:
    int maxSum = 0;  // global maximum sum

    box* find(TreeNode* root) {
        if (!root) return new box();

        box* lefthead = find(root->left);
        box* righthead = find(root->right);

        if (lefthead->BST && righthead->BST &&
            lefthead->max < root->val && righthead->min > root->val) {

            box* head = new box();
            head->sum = root->val + lefthead->sum + righthead->sum;
            head->min = min(root->val, min(lefthead->min, righthead->min));
            head->max = max(root->val, max(lefthead->max, righthead->max));

            maxSum = max(maxSum, head->sum);
            return head;
        } else {
            box* head = new box();
            head->BST = false;
            return head;
        }
    }

    int maxSumBST(TreeNode* root) {
        find(root);
        return maxSum;
    }
};