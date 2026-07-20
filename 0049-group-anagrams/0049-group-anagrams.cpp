class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        // sorting approach TC:- O(n*klogk)
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


        // Frequency Count + String Key TC:- O(N*K)
        // vector<vector<string>> ans;
        // unordered_map<string, vector<string>> mp;
        // for(string& s: strs){
        //     vector<int> freq(26);
        //     string key;
        //     for(char& c: s){
        //         freq[c-'a']++;
        //     }
        //     for(int& k: freq){  //creating a unique key for anagram
        //         key+='#';
        //         key+=to_string(k);
        //     }
        //     mp[key].push_back(s);
        // }
        // for(auto& k: mp){
        //     ans.push_back(move(k.second));
        // }
        // return ans;
    }
};
