class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
       for(int col=0;col<strs[0].size();col++){

        char ch=strs[0][col];

        for(int row=1;row<strs.size();row++){
            if(strs[row].size()<col|| ch!=strs[row][col] ){
                return strs[0].substr(0,col);
            }
        }
       }
       return strs[0];




    }
};
// 2. Sorting Lexicographically (Clever Shortcut)

// When an array of strings is sorted alphabetically, the two strings that differ the most will be placed at the very first index (strs[0]) and the very last index (strs[n - 1]).

// If a prefix is shared between the first and last string after sorting, all intermediate strings are mathematically guaranteed to share it too.

// Simply sort the vector, then compare strs[0] and strs.back() character by character until a mismatch occurs.