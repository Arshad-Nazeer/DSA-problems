class Solution {
public:
    vector<int> xorQueries(vector<int>& arr, vector<vector<int>>& queries) {
        // //brute TC:-O(q*n)
        // vector<int> ans;
        // for(int i=0;i<queries.size(); i++){
        //     int left=queries[i][0], right=queries[i][1];
        //     int xr=arr[left];
        //     while(left!=right){
        //         xr^=arr[++left];
        //     }
        //     ans.push_back(xr);
        // }   
        // return ans;

        // prefix array TC:-O(q+n) SC:-O(n)
        vector<int> prefix(arr.size()), ans;
        prefix[0]=arr[0];
        for(int i=1; i<arr.size(); i++) prefix[i]=arr[i]^prefix[i-1];

        for(auto &q: queries){
            int left=q[0], right=q[1];
            if(left==0) ans.push_back(prefix[right]);
            else ans.push_back(prefix[right]^prefix[left-1]);
        }
        return ans;
    }
};