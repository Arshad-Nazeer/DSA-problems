class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        vector<vector<string>> ans;
        unordered_map<string, vector<string>> mp;
        for(string s: strs){
            string sorted_s=s;
            sort(sorted_s.begin(), sorted_s.end());
            mp[sorted_s].push_back(s);
        }
        for(auto &k: mp){
            ans.push_back(k.second);
        }
        return ans;
    }
};