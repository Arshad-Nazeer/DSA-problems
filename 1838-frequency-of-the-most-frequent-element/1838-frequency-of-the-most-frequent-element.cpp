class Solution {
public:
    int maxFrequency(vector<int>& nums, int k) {
        sort(nums.begin(), nums.end());
        long long sum=0;
        int left=0, result=1;
        for(int right=0; right<nums.size(); right++){
            sum+=nums[right];
            while((long long)(right-left+1)*nums[right]-sum>k){
                sum-=nums[left];
                left++;
            }
            result=max(result, right-left+1);
        }
        return result;
        // int largest=0, i=1, temp=k, count=0, result=0;
        // while(i<nums.size()){
        //     if(largest-nums[i]<=temp) {
        //         temp-=largest-nums[i++];
        //         count++;
        //         result=max(count, result);
        //     }else{
        //         count=0;
        //         largest++;
        //         i=largest+1;
        //     }
        // }
        // return result;
        
    }
};