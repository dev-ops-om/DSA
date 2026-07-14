/*
class Node {
public:
    int data;
    Node *left;
    Node *right;

    Node(int x) {
        data = x;
        left = NULL;
        right = NULL;
    }
};
*/
int find(vector<int> &inorder,int target,int start,int end ){
    for(int i=start;i<=end;i++){
        if(inorder[i]==target)
        return i;
    }
    return -1;
}
Node *Tree(vector<int> &inorder, vector<int> &preorder,int start,int end,int index){
    if(start>end)
    return NULL;
    
    Node *root=new Node(preorder[index]);
    int pos=find(inorder,preorder[index],start,end);
    root->left=Tree(inorder,preorder,start,pos-1,index+1);
    root->right=Tree(inorder,preorder,pos+1,end,index+(pos-start)+1);
    
    
    return root;
}

class Solution {
  public:
    Node *buildTree(vector<int> &inorder, vector<int> &preorder) {
        int n=inorder.size();
     return Tree(inorder,preorder,0,n-1,0);  
    }
};