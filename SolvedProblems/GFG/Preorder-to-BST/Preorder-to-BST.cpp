// User function template in C++

/*

typedef struct Node
{
    int data;
    struct Node *left, *right;
} Node;


// A utility function to create a new tree node
Node* newNode( int data )
{
    Node* temp = (Node *)malloc( sizeof( Node ) );
    temp->data = data;
    temp->left = temp->right = NULL;
    return temp;
}

*/
Node* BST(int pre[], int &index, int lower, int upper, int size) {
    if (index == size || pre[index] < lower || pre[index] > upper)
        return NULL;

    Node* root = newNode(pre[index++]);  // use utility function

    root->left  = BST(pre, index, lower, root->data, size);
    root->right = BST(pre, index, root->data, upper, size);

    return root;
}

class Solution {
  public:
    // Function that constructs BST from its preorder traversal.
    Node* Bst(int pre[], int size) {
        int index = 0;
        return BST(pre, index, INT_MIN, INT_MAX, size);
    }
};