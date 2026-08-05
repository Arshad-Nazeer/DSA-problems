class Solution {
public:
    // vector<vector<int>> multiplication(vector<vector<int>> &a, vector<vector<int>> &b){
    //     vector<vector<int>> temp(2, vector<int>(2));

    //     for(int i=0; i<2; i++){
    //         for(int j=0; j<2; j++){
    //             for(int k=0; k<2; k++){
    //                 temp[i][j]+=a[i][k]*b[k][j];
    //             }
    //         }
    //     }
    //     return temp;
    // }

    // vector<vector<int>> exponentiation(vector<vector<int>> &base, int n){
    //     vector<vector<int>> result={{1, 0}, {0, 1}};

    //     while(n>0){
    //         if(n%2!=0) result=multiplication(result, base);
    //         base=multiplication(base, base);
    //         n/=2;
    //     }
    //     return result;
    // }

    int dprecur(int n, vector<int> &dp){
        if(n<=1) return n;
        if(dp[n]!=-1) return dp[n];
        dp[n]=dprecur(n-1, dp)+dprecur(n-2, dp);
        return dp[n];
    }

    int fib(int n) {
        //dynamic programming optimized recursion which reduces TC from O(2^n) to O(n)
        vector<int> dp(n+1, -1);
        return dprecur(n, dp);

        // //matrix approach TC:- O(n)
        // if(n<=1) return n;
        // vector<vector<int>> base={{1, 1}, {1, 0}};
        // vector<vector<int>> ans= exponentiation(base, n-1);
        // return ans[0][0];

        // //recursion TC:-O(n^2)
        // if(n<=1) return n;
        // return fib(n-1) +fib(n-2);

        // // Storing in vector
        // if(n<=1) return n;
        // vector<int> v(n+1);
        // v[0]=0;
        // v[1]=1;
        // for(int i=2; i<=n; i++){
        //     v[i]=v[i-1]+v[i-2];
        // }
        // return v[n];

        // //tracking last two terms;
        // if(n<=1) return n;
        // int curr=1, prev=0, ans;
        // for(int i=2; i<=n; i++){
        //     ans=curr+prev;
        //     prev=curr;
        //     curr=ans;
        // }
        // return ans;
    }
};
