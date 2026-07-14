class Solution {
  public:
    int kthSmallest(vector<int> &arr, int k) {
     priority_queue<int>p;
     
     for(int i=0;i<k;i++){
         p.push(arr[i]);
         
     }
     for(int i=k;i<arr.size();i++){
         if(arr[i]<p.top()){
             p.pop();
             p.push(arr[i]);
         }
     }
     return p.top();
        
    }
};