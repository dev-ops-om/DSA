/* BST Node
class Node {
   public:
    int data;
    Node *left;
    Node *right;

    Node(int x){
        data = x;
        left = NULL;
        right = NULL;
    }
};
*/

class Solution {
public:
    vector<Node*> findPreSuc(Node* root, int key) {
        Node* pre = NULL;
        Node* suc = NULL;

        while (root) {
            if (root->data == key) {
                // Predecessor = max in left subtree
                if (root->left) {
                    Node* temp = root->left;
                    while (temp->right) temp = temp->right;
                    pre = temp;
                }
                // Successor = min in right subtree
                if (root->right) {
                    Node* temp = root->right;
                    while (temp->left) temp = temp->left;
                    suc = temp;
                }
                break;
            }
            else if (root->data > key) {
                suc = root;
                root = root->left;
            }
            else {
                pre = root;
                root = root->right;
            }
        }

        return {pre, suc};
    }
};