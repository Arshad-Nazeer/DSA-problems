class Solution {
public:
    // bool solve(int i, string& s, unordered_set<string>& dict){
        // if(i==s.size()) return true;
        // if(dict.count(s.substr(i))) return true;
        // for(int j=i; j<s.size(); j++){
        //     if(dict.count(s.substr(i, j-i+1)))
        //         if(solve(j+1, s, dict)) return true;
        // }
        // return false;
    // }

    bool wordBreak(string s, vector<string>& wordDict) {
        // // TC is blowing in exponential O(2^n)
        // unordered_set<string> dict(wordDict.begin(), wordDict.end());
        // return solve(0, s, dict);
        
        int maxlen=0;
        for(string &str: wordDict){
            maxlen=max(maxlen, (int)str.size());
        }
        unordered_set<string> dict(wordDict.begin(), wordDict.end());
        vector<bool> dp(s.size()+1);
        dp[0]=1;
        for(int i=1; i<=s.size(); i++){
            for(int j=i-1; j>=i-maxlen && j>=0; j--){
                if(dp[j]==true && dict.count(s.substr(j, i-j))){
                    dp[i]=true;
                    break;
                }
            }
        }
        return dp[s.size()];
    }
};
