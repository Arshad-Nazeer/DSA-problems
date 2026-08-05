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

    // int dprecur(int n, vector<int> &dp){
    //     if(n<=1) return n;
    //     if(dp[n]!=-1) return dp[n];
    //     dp[n]=dprecur(n-1, dp)+dprecur(n-2, dp);
    //     return dp[n];
    // }

    pair<int, int> fastdoubling(int n){
        if(n==0) return {0, 1};

        auto p=fastdoubling(n/2);

        int a=p.first;
        int b=p.second;

        int c=a*(2*b-a); // even identity: F(2k)=F(k)×(2F(k+1)−F(k))
        int d=a*a+b*b;   // odd identity: F(2k+1)=F(k)^2+F(k+1)^2
        
        if(n%2==0) return {c, d};
        else return {d, c+d};
    }

    int fib(int n) {
        // using fast doubling identities TC:- O(log(n)) SC:- O(log(n)) due to recursion stack
        return fastdoubling(n).first;

        // //dynamic programming optimized recursion which reduces TC from O(2^n) to O(n)
        // vector<int> dp(n+1, -1);
        // return dprecur(n, dp);

        // //matrix approach TC:- O(log n)
        // if(n<=1) return n;
        // vector<vector<int>> base={{1, 1}, {1, 0}};
        // vector<vector<int>> result={{1, 0}, {0, 1}};
        // n--;

        // while(n>0){
        //     if(n%2!=0) result=multiplication(result, base);
        //     base=multiplication(base, base);
        //     n=n/2;
        // }

        // return result[0][0];

        // //recursion TC:-O(n^2)
        // if(n<=1) return n;
        // return fib(n-1) +fib(n-2);

        // //tomfoolery
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