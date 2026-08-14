class Solution {
public:
    // int edit(int i, int j, string& word1, string& word2, vector<vector<int>>& dp){
    //     if(i<0) return j+1; //insert all
    //     if(j<0) return i+1; //delete all
    //     if(dp[i][j]!=-1) return dp[i][j];
    //     if(word1[i]==word2[j]) return dp[i][j]=edit(i-1, j-1, word1, word2, dp);
    //     return dp[i][j]=1+min(min(edit(i-1, j, word1, word2, dp), edit(i, j-1, word1, word2, dp)), edit(i-1, j-1, word1, word2, dp)); //delete, insert, replace
    // }

    int minDistance(string word1, string word2) {
        //memoization DP
        // vector<vector<int>> dp(word1.size(), vector<int>(word2.size(), -1));
        // return edit(word1.size()-1, word2.size()-1, word1, word2, dp);

        // vector<vector<int>> dp(word1.size()+1, vector<int>(word2.size()+1));     
        // for(int j=0; j<=word2.size(); j++) dp[0][j] = j;   // insert all(base case)
        // for(int i=0; i<=word1.size(); i++) dp[i][0] = i;  // delete all(base case)

        // for(int i=1; i<=word1.size(); i++){
        //     for(int j=1; j<=word2.size(); j++){
        //         if(word1[i-1]==word2[j-1]) dp[i][j]=dp[i-1][j-1];
        //         else dp[i][j]=1+min(min(dp[i-1][j], dp[i][j-1]), dp[i-1][j-1]);
        //     }
        // }   
        // return dp[word1.size()][word2.size()];

        vector<int> prev(word2.size()+1), curr(word2.size()+1);
        for(int i=0; i<=word2.size(); i++) prev[i] = i;

        for(int i=1; i<=word1.size(); i++){
            curr[0]=i;
            for(int j=1; j<=word2.size(); j++){
                if(word1[i-1]==word2[j-1]) curr[j]=prev[j-1];
                else curr[j]=1+min(min(prev[j], curr[j-1]), prev[j-1]);
            }
            prev=curr;               
        }
        return prev[word2.size()];
    }
};