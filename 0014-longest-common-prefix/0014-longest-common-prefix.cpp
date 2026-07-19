class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        // auto it=find(strs.begin(), strs.end(), "");
        // if(it!=strs.end()) return "";
        // string ans="";
        // for(int j=0; ;j++){
        //     for(int i=1; i<strs.size(); i++){
        //         if(strs[i][j]==strs[i-1][j]) continue;
        //         else return ans;
        //     }
        //     ans.push_back(strs[0][j]);
        // }
        for(int i=0; i<strs[0].size(); i++){
            for(string& s: strs){
                if(i>=s.size() || strs[0][i]!=s[i]) return strs[0].substr(0, i);
            }
        }
        return strs[0];
    }
};