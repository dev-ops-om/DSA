class Solution {
public:
    int maximumPopulation(vector<vector<int>>& logs) {
        vector<pair<int,int>> events;
        for (auto &log : logs) {
            events.push_back({log[0], 1});   // birth
            events.push_back({log[1], -1});  // death
        }

        sort(events.begin(), events.end());

        int sum = 0, maxi = 0, year = 1950;
        for (auto &e : events) {
            sum += e.second;
            if (sum > maxi) {
                maxi = sum;
                year = e.first;
            }
        }
        return year;
    }
};