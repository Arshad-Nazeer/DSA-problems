class Solution {
public:
    vector<int> findMissingAndRepeatedValues(vector<vector<int>>& grid) {
        long long n=grid.size();
        n*=n;
        long long sum=(n*(n+1))/2, s=0, sqs=0;
        int diff, sqdiff;
        long long sqsum=(n*(n+1)*(2*n+1))/6;
        for(auto k: grid){
            for(auto j: k){
                s+=j;
                sqs+=j*j;
            }
        }
        diff=(sum-s);
        sum=((sqsum-sqs)/diff);
        return {int((sum-diff)/2), int((sum+diff)/2)};
    }
};