// User function Template for C++

class Solution {
  public:
    void rotate(vector<int> &arr) {
        int n=arr.size();
vector<int>temp(n);
for(int i=0;i<n;i++){
    temp[i] = arr[(i+(n-1))%n];
}
arr=temp;
    }
};