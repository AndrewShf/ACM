class Solution {
public:
    vector<int> smallestSufficientTeam(vector<string>& req_skills, vector<vector<string>>& people) {
        unordered_map<int, vector<int>> dp;
        int n = req_skills.size();
        dp.reserve(1<<n);
        dp[0] = {}; // !!!
        map<string, int> mp;
        for (int i = 0; i < n; ++i) {
            mp[req_skills[i]] = i;
        }

        for (int i = 0; i < people.size(); ++i) {
            int cur = 0;
            for (int j = 0; j < people[i].size(); ++j) {
                cur |= (1<<mp[people[i][j]]);
            }
            for (auto it = dp.begin(); it != dp.end(); ++it) {
                int combo = cur|(it->first);
                if (dp.find(combo) == dp.end() || dp[combo].size() > 1+dp[it->first].size()) {
                    dp[combo] = it->second;
                    dp[combo].push_back(i);
                }
            }
        }
        return dp[(1<<n)-1];
    }
};
/* The DP equivalence is different:
   dp[start|current_skill] =
   dp[start|current_skill] > dp[start].size() ? latter:unchange

   we have no need to enumerate the index, we iterate the map.
*/
