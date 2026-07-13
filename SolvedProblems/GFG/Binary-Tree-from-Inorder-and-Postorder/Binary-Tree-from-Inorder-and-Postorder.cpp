/*
class Node {
public:
    int data;
    Node* left;
    Node* right;

    Node(int x) {
        data = x;
        left = right = nullptr;
    }
};
*/
int find(vector<int> &inorder, int target, int start, int end) {
    for (int i = start; i <= end; i++) {
        if (inorder[i] == target)
            return i;
    }
    return -1;
}

Node* Tree(vector<int> &inorder, vector<int> &postorder,
           int start, int end, int index) {
    if (start > end)
        return NULL;

    Node* root = new Node(postorder[index]);

    int pos = find(inorder, postorder[index], start, end);

    // right subtree first
    root->right = Tree(inorder, postorder, pos + 1, end, index - 1);

    // left subtree (correct index)
    root->left = Tree(
        inorder,
        postorder,
        start,
        pos - 1,
        index - (end - pos) - 1
    );

    return root;
}

class Solution {
public:
    Node* buildTree(vector<int> &inorder, vector<int> &postorder) {
        int n = inorder.size();
        return Tree(inorder, postorder, 0, n - 1, n - 1);
    }
};
