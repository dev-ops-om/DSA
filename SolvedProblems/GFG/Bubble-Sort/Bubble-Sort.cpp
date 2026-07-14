class Solution {
  public:
    void bubbleSort(vector<int>& arr) {
       //aproach 1
      int n=arr.size();
      if (n <= 1) return;
    for (int i = n-2; i >= 0; i--) {

    for (int j = 0; j <= i; j++) {
        if (arr[j] > arr[j+1]) {
            swap(arr[j], arr[j+1]);
         
        }
    }
 // array already sorted
}
    }
};