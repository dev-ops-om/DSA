/* The structure of the Node is
struct Node
{
    int data;
    Node *left;
    Node *right;
    int height;
};
*/
// class Node{
//     public:
//     int data,height;
//     Node *right,*left;


//     Node(int value){
//         data=value;
//         height=1;
//         left=right=NULL;

//     }
// };

int getheight(Node *root){
    if(!root)
    return 0;
    return root->height;
}

int getbalance(Node *root){
    return getheight(root->left)-getheight(root->right);

}
Node *rightRotation(Node *root){
Node *child=root->left;
Node*childright=child->right;
child->right=root;
root->left=childright;


root->height=1+max(getheight(root->left),getheight(root->right));
child->height=1+max(getheight(child->left),getheight(child->right));
return child;

}

Node *leftRotation(Node *root){
    Node *child=root->right;
    Node *childleft=child->left;

    child->left=root;
    root->right=childleft;
    root->height=1+max(getheight(root->left),getheight(root->right));
child->height=1+max(getheight(child->left),getheight(child->right));
return child;

}
class Solution {
  public:
    // Function to insert a node into AVL tree
    Node* insertToAVL(Node* root, int key) {
        // Step 1: Normal BST insertion
        if (!root) return new Node(key);

        if (key < root->data)
            root->left = insertToAVL(root->left, key);
        else if (key > root->data)
            root->right = insertToAVL(root->right, key);
        else
            return root; // duplicate keys not allowed

        // Step 2: Update height
        root->height = 1 + max(getheight(root->left), getheight(root->right));

        // Step 3: Get balance factor
        int balance = getbalance(root);

        // Step 4: Handle 4 rotation cases

        // Left Left Case
        if (balance > 1 && key < root->left->data)
            return rightRotation(root);

        // Right Right Case
        if (balance < -1 && key > root->right->data)
            return leftRotation(root);

        // Left Right Case
        if (balance > 1 && key > root->left->data) {
            root->left = leftRotation(root->left);
            return rightRotation(root);
        }

        // Right Left Case
        if (balance < -1 && key < root->right->data) {
            root->right = rightRotation(root->right);
            return leftRotation(root);
        }

        return root;
    }
};