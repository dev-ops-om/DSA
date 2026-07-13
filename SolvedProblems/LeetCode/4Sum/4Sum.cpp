class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {

        int n = nums.size();

        set<vector<int>> st;

        for(int i = 0; i < n-3; i++) {

            for(int j = i+1; j < n-2; j++) {

                unordered_map<long long,int> m;

                for(int k = j+1; k < n; k++) {

                    long long need =
                        (long long)target
                        - nums[i]
                        - nums[j]
                        - nums[k];

                    if(m.find(need) != m.end()) {

                        vector<int> quad = {
                            nums[i],
                            nums[j],
                            (int)need,
                            nums[k]
                        };

                        sort(quad.begin(), quad.end());

                        st.insert(quad);
                    }

                    m[nums[k]] = k;
                }
            }
        }

        return vector<vector<int>>(st.begin(), st.end());
    }
};