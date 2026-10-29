class Solution {
public:
    vector<vector<int>> generate(int numRows) {

        vector<vector<int>>triangle;

        for(int i=0;i<numRows;i++){
            vector<int>row(i+1,1);

            for(int c=1;c<i;c++){
                row[c]=triangle[i-1][c-1]+triangle[i-1][c];


            }
            triangle.push_back(row);
        }
return triangle;
    }
};