class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        vector<vector<string>> ans;
        vector<string> tmp(strs);
        map<string, int> mp;
        int cnt = 0;
        int i = 0;
        for (auto it = tmp.begin(); it!=tmp.end(); ++it, ++i) {
            sort(it->begin(), it->end()); 
            if (!mp.count(tmp[i])) {
                mp[tmp[i]] = cnt++; // count the number of anagrams 
            }
        }
        // resize vector ans
        ans.resize(cnt);
        for (int i = 0; i < tmp.size(); ++i) {
            // cout << tmp[i] << endl;
            int j = mp[tmp[i]];
            ans[j].push_back(strs[i]); // put str with same id in same vector
        }
        return ans;
    }
};
// running time == 28ms
