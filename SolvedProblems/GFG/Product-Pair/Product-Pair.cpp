// User function template for C++

class Solution {
  public:
    bool isProduct(vector<int> arr, long long x) {
        unordered_set<int>st;
        for(int i=0;i<arr.size();i++){
            if(arr[i]==0){
                if(x==0 && st.count(0)){
                    return true;
                }
                st.insert(0);
            }
            else{
                if(x%arr[i]==0){
                    int need=x/arr[i];
                    if(st.count(need)){
                        return true;
                    }
                
                }
                    st.insert(arr[i]);
            }
          
        }
        return false;
    }
};