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

class Solution {
public:
    Node* ArrayToBST(vector<int>& arr, int start, int end) {
        if (start > end) return nullptr;

        int mid = start + (end - start) / 2;
        Node* root = new Node(arr[mid]);   // create node with mid element

        root->left = ArrayToBST(arr, start, mid - 1);   // build left subtree
        root->right = ArrayToBST(arr, mid + 1, end);    // build right subtree

        return root;
    }

    Node* sortedArrayToBST(vector<int>& arr) {
        return ArrayToBST(arr, 0, arr.size() - 1);
    }
};
