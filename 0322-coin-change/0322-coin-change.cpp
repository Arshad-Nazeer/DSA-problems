class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        vector<int> dp(amount+1, INT_MAX);
        dp[0]=0;
        for(int &k: coins){
            if(k>amount) continue;
            for(int j=k; j<=amount; j++){
                if(dp[j-k]!=INT_MAX) dp[j]=min(dp[j], dp[j-k]+1);
            }
        }
        if(dp[amount]==INT_MAX) return -1;
        else return dp[amount];
    }
};