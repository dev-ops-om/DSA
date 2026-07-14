/* Node is as follows:

struct Node
{
    int data, height;
    Node *left, *right;
    Node(int x)
    {
        data = x;
        height = 1;
        left = right = NULL;
    }
};

*/


int getheight(Node *root){
    if(!root)
    return 0;
    return root->height;
}

int getbalance(Node *root){
    return getheight(root->left)-getheight(root->right);

}
Node *rightrotation(Node *root){
Node *child=root->left;
Node*childright=child->right;
child->right=root;
root->left=childright;


root->height=1+max(getheight(root->left),getheight(root->right));
child->height=1+max(getheight(child->left),getheight(child->right));
return child;

}

Node *leftrotation(Node *root){
    Node *child=root->right;
    Node *childleft=child->left;

    child->left=root;
    root->right=childleft;
    root->height=1+max(getheight(root->left),getheight(root->right));
child->height=1+max(getheight(child->left),getheight(child->right));
return child;

}
Node* deleteNode(Node* root, int key) {
if(!root)
return NULL;
if(key<root->data){
    root->left=deleteNode(root->left,key);
}
    else if(key>root->data)
    root->right=deleteNode(root->right,key);
    else{
        if(!root->left && !root->right){
            delete root;
            return NULL;
            
        }
        else if(root->left && !root->right){
            Node *temp=root->left;
            delete root;
            return temp;
        }
        else if(!root->left && root->right){
          Node *temp=root->right;
          delete root;
          return temp;
          
        }
        else{
            Node *curr=root->right;
           while(curr->left){
               curr=curr->left;
               
           }
           root->data=curr->data;
           root->right=deleteNode(root->right,curr->data);
           
        }
    }
    root->height=1+max(getheight(root->left),getheight(root->right));
    
    int balance=getbalance(root);
    if(balance>1){
        if(getbalance(root->left)>=0)
        return rightrotation(root);
        else{
            root->left =leftrotation(root->left);
            return rightrotation(root);
        }
    }
    else if(balance<-1){
        if(getbalance(root->right)<=0)
        return leftrotation(root);
        else{
            root->right=rightrotation(root->right);
            return leftrotation(root);
        }
    }
    else
    return root;
    
}

