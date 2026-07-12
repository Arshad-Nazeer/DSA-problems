class Solution {
public:
    int singleNumber(vector<int>& nums) {
        //counting set bits TC:-O(32*n)
        int ans=0;
        for(int i=0; i<32; i++){
            int count=0;
            for(int &k: nums){
                if((k>>i)&1) count++;
            }
            if(count%3!=0){
                ans=ans|(1<<i);
            }
        }
        return ans;
    }
};