class Solution {
public:
   vector<int> findMissingAndRepeatedValues(vector<vector<int>>& grid) {

    long long n = grid.size();
    long long N = n * n;

    long long expectedSum =
        N * (N + 1) / 2;

    long long expectedSq =
        N * (N + 1) * (2 * N + 1) / 6;

    long long actualSum = 0;
    long long actualSq = 0;

    for(auto &row : grid){
        for(auto &x : row){
            actualSum += x;
            actualSq += 1LL * x * x;
        }
    }

    long long D =
        actualSum - expectedSum;      // x-y

    long long E =
        (actualSq - expectedSq) / D;  // x+y

    long long repeating =
        (D + E) / 2;

    long long missing =
        (E - D) / 2;

    return {(int)repeating, (int)missing};
}
};