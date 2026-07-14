/*Complete the function below
Node is as follows:
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
class Solution {
  public:
    bool isCousins(Node* root, int x, int y) {
        if (!root || x == y) return false;

        queue<pair<Node*, Node*>> q; 
        // {current node, parent node}
        q.push({root, NULL});

        Node* px = NULL;
        Node* py = NULL;
        int lx = -1, ly = -1;
        int level = 0;

        while (!q.empty()) {
            int n = q.size();
            while (n--) {
                auto it = q.front();
                q.pop();

                Node* curr = it.first;
                Node* parent = it.second;

                if (curr->data == x && lx == -1) {
                    px = parent;
                    lx = level;
                }
                if (curr->data == y && ly == -1) {
                    py = parent;
                    ly = level;
                }

                if (curr->left)
                    q.push({curr->left, curr});
                if (curr->right)
                    q.push({curr->right, curr});
            }

            if (lx != -1 && ly != -1)
                break;

            level++;
        }

        if (lx == -1 || ly == -1) return false;

        return (lx == ly && px != py);
    }
};
