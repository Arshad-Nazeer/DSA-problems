class Solution {
public:
    int minEatingSpeed(vector<int>& piles, int h) {
        // Binary Search TC:- O(n*log(max(piles)))
        int low=1, high=*max_element(piles.begin(), piles.end()), ans;
        for(int &k: piles) high=max(k, high);
        while(low<=high){
            int mid=low+(high-low)/2, hours=0;
            for(int &k: piles) {
                // hours+=k/mid+(k%mid ? 1: 0);
                hours+=(k+mid-1)/mid; //simulating ceil()
                if(hours>h) break; // prevent overflow
            }
            if(hours<=h){
                ans=mid;
                high=mid-1;
            }else low=mid+1;
        }
        return ans;
    }
};