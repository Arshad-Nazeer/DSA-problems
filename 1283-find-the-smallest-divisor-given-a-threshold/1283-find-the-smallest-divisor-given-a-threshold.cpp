class Solution {
public:
    int smallestDivisor(vector<int>& nums, int threshold) {
        // // brute force TC:-(n*maxele(nums))
        // // if(nums.size()>threshold) return -1 // not needed
        // int i=1;
        // while(true){
        //     int result=0;
        //     for(int num: nums)
        //         result+=ceil((double)num/i);
        //     if(result<=threshold) return i;
        //     i++;
        // }

        // binary search
        // if(nums.size()>threshold) return -1 // not needed
        int high=INT_MIN, low=1, ans;
        for(int &num: nums) high=max(num, high);
        while(low<=high){
            int mid=low+(high-low)/2, result=0;
            for(int &num: nums) {
                result+=(num+mid-1)/mid;
                // result+=ceil((double)num/mid);
                if(result>threshold) break;
            }
            if(result<=threshold){
                ans=mid;
                high=mid-1;
            }else{
                low=mid+1;
            }
        }
        return ans;
    }
};