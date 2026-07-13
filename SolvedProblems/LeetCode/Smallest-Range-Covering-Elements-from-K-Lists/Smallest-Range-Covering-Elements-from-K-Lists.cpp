class Solution {
public:
    vector<int> smallestRange(vector<vector<int>>& nums) {
        
       priority_queue<
            pair<int, pair<int,int>>,
            vector<pair<int, pair<int,int>>>,
            greater<pair<int, pair<int,int>>>
        > p;

int mini,maxi=INT_MIN;
for(int i=0;i<nums.size();i++){
    p.push(make_pair(nums[i][0],make_pair(i,0)));
    maxi=max(maxi,nums[i][0]);
     
}
mini=p.top().first;
vector<int>ans(2);
ans[0]=mini;
ans[1]=maxi;

pair<int,pair<int,int>>temp;
int row,col,elem;
while(p.size()==nums.size()){
temp=p.top();
p.pop();

elem=temp.first;
row=temp.second.first;
col=temp.second.second;

if(col+1<nums[row].size()){
    col++;
    p.push(make_pair(nums[row][col],make_pair(row,col)));
    maxi=max(maxi,nums[row][col]);
    mini=p.top().first;

   if(maxi-mini<ans[1]-ans[0]){
    ans[0]=mini;
    ans[1]=maxi;

   }

}
}
return ans;
    }
};