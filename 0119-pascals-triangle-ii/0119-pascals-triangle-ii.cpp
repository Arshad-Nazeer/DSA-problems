class Solution {
public:
    vector<int> getRow(int rowIndex) {
        // if(!rowIndex) return {1};
        // vector<int> ans(rowIndex+1, 0);
        // ans[0]=1;
        // ans[1]=1;
        // for(int i=1; i<rowIndex; i++){
        //     int prev=1, temp;
        //     for(int j=1; j<=i; j++){
        //         temp=ans[j]+prev;
        //         prev=ans[j];
        //         ans[j]=temp;
        //     }
        //     ans[i+1]=1;
        // }
        // return ans;

        vector<int> ans(rowIndex+1, 0);
        ans[0]=1;
        
        for(int i=1; i<=rowIndex; i++){
            for(int j=i; j>=1; j--) ans[j]+=ans[j-1];
        }
        return ans;
    }
};