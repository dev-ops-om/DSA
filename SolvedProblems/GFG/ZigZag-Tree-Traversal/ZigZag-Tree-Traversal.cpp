/*
class Node
{
    int data;
    Node* left;
    Node* right;

    Node(int x){
        data = x;
        left = right = NULL;
    }
}; */
class Solution {
  public:
    vector<int> findSpiral(Node* root) {
     stack<Node*>s1;  //right to left
     stack<Node*>s2;   //left to right
     if(root == NULL) return {};

        s1.push(root);
        vector<int>ans;
        while(!s1.empty()||!s2.empty()){
             //right to left
             if(!s1.empty()){
            while(!s1.empty()){
                Node*temp=s1.top();
                s1.pop();
                ans.push_back(temp->data);
                if(temp->right)
                s2.push(temp->right);
                if(temp->left)
                s2.push(temp->left);
            }     
             
        }
        else{
            //left to right
              while(!s2.empty()){
                Node*temp=s2.top();
                s2.pop();
                ans.push_back(temp->data);
                if(temp->left)
                s1.push(temp->left);
                if(temp->right)
                s1.push(temp->right);
            }   
            
        }
       
    }
     return ans;
    }
};