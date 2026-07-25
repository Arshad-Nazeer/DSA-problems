class Solution {
public:
    int findMaxLength(vector<int>& nums) {
        // TC:- O(n)
        unordered_map<int, int> prefix;
        prefix[0]=-1;
        int sum=0, maxlen=0;
        for(int i=0; i<nums.size(); i++){
            nums[i] ? sum++ : sum--;
            if(prefix.find(sum)!=prefix.end()) maxlen=max(maxlen, i-prefix[sum]);
            else prefix[sum]=i;
        }
        return maxlen;
    }
};