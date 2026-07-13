class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        // //Prefix sum Approach
        // int count=0;
        // vector<int> prefix(nums.size());
        // prefix[0]=nums[0];
        // for(int i=1; i<nums.size(); i++){
        //     prefix[i]=prefix[i-1]+nums[i];
        // }

        // unordered_map<int, int> freq;

        // for(int i=0; i<nums.size(); i++){
        //     if(prefix[i]==k) count++;

        //     if(freq.find(prefix[i]-k)!=freq.end()) count+=freq[prefix[i]-k];

        //     freq[prefix[i]]++;
        // }
        // return count;

        //eliminating cummulative sum array
        unordered_map<int, int> freq;
        int sum=0, count=0;

        for(int i=0; i<nums.size(); i++){
            sum+=nums[i];

            if(sum==k) count++;

            if(freq.find(sum-k)!=freq.end()) count+=freq[sum-k];
            freq[sum]++;
        }
        return count;

        // // laand Approach
        // int count=0;
        // for(int i=0; i<nums.size(); i++){
        //     int sum=0;
        //     for(int j=i; j<nums.size(); j++){
        //         sum+=nums[j];
        //         if(sum==k) count++;
        //     }
        // }
        // return count;
    }
};