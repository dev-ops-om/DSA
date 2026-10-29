class Solution {
public:
    vector<int> getRow(int rowIndex) {
            vector<vector<int>>triangle;

        for(int i=0;i<=rowIndex;i++){
            vector<int>row(i+1,1);

            for(int c=1;c<i;c++){
                row[c]=triangle[i-1][c-1]+triangle[i-1][c];


            }
            triangle.push_back(row);
        }
return triangle[rowIndex];
    }
};