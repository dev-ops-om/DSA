class Solution {
public:
    int maxScore(vector<int>& cardPoints, int k) { 
      int n=cardPoints.size();
   int rightsum=0;
   for(int i=0;i<k;i++){
       rightsum+=cardPoints[n-1-i];
   }
   int maxsum=rightsum;
   int currsum=rightsum;
   for(int i=0;i<k;i++){
       currsum+=cardPoints[i]-cardPoints[n+i-k];
       
       maxsum=max(maxsum,currsum);
   }
   return maxsum;
    }
};