class Solution {
public:
    void backtrack(vector<vector<string>>& result, string& s, int idx, vector<string>& path, int n, vector<vector<bool>>& dp){
        if(idx==n){
            result.push_back(path);
            return;
        }
        for(int i=idx; i<n; i++){
            if(dp[idx][i]){
                path.push_back(s.substr(idx, i-idx+1));
                backtrack(result, s, i+1, path, n, dp);
                path.pop_back();
            }
        }
    }

    vector<vector<string>> partition(string s) {
        // DP/backtracking SC:-O(n^2) TC:- O((n^2)+(n*2^n))
        int n=s.size();
        vector<vector<bool>> dp(n, vector<bool>(n, false));
        for(int i=n-1; i>=0; i--){
            for(int j=i; j<n; j++){
                if(s[i]==s[j]) {
                    if(j-i<=2) dp[i][j]=true;
                    else dp[i][j]=dp[i+1][j-1];
                }
            }
        }

        vector<vector<string>> result;
        vector<string> path;
        backtrack(result, s, 0, path, n, dp);
        return result;
    }
};