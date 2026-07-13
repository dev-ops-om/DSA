/*struct Node
{
    int data;
    Node *left, *right;
};*/

Node* BSTfromPost(int post[], int &index, int lower, int upper) {
    if (index < 0 || post[index] < lower || post[index] > upper)
        return NULL;

    Node* root = new Node(post[index--]);

    // Important: build right subtree first, then left
    root->right = BSTfromPost(post, index, root->data, upper);
    root->left  = BSTfromPost(post, index, lower, root->data);

    return root;
}

Node* constructTree(int post[], int size) {
    int index = size - 1; // start from last element
    return BSTfromPost(post, index, INT_MIN, INT_MAX);
}
