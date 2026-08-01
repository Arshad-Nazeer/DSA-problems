class Solution {
public:
    int trap(vector<int>& height) {
        //optimal approach(two pointer)
        int ans=0;
        int leftmax=height[0], rightmax=height[height.size()-1];
        int low=1, high=height.size()-2;
        while(low<=high){
            leftmax=max(height[low], leftmax);
            rightmax=max(height[high], rightmax);

            if(leftmax<=rightmax) ans+=leftmax-height[low++];
            else ans+=rightmax-height[high--];
        }
        return ans;

        //prefix array approach
        // int n=height.size();
        // vector<int> lmax(n), rmax(n);
        // int ans=0;
        // lmax[0]=height[0];
        // rmax[n-1]=height[n-1];
        // for(int i=1; i<n; i++){
        //     lmax[i]=max(lmax[i-1], height[i]);
        // }
        // for(int i=n-2; i>=0; i--){
        //     rmax[i]=max(rmax[i+1] ,height[i]);
        // }
        // for(int i=1; i<n-1; i++){
        //     ans+=min(lmax[i], rmax[i])-height[i];
        // }
        // return ans;

        //laand approach(TLE)
        // int ans=0;
        // for(int i=1; i<height.size()-1; i++){
        //     int leftmax=height[0];
        //     for(int j=0; j<=i; j++){
        //         leftmax=max(height[j], leftmax);
        //     }
        //     int rightmax=height[height.size()-1];
        //     for(int j=height.size()-1; j>=i; j--){
        //         rightmax=max(rightmax, height[j]);
        //     }
        //     ans+=min(leftmax, rightmax)-height[i];
        // }
        // return ans;

        //tomfoolery
        // int left, right, low, high, water=0, remove1=0, remove2=0;
        // for(int i=0; i<height.size(); i++){
        //     if(height[i]!=0){
        //         left=i;
        //         right=i+1;
        //         break;
        //     }
        // }
        // for(int i=height.size()-1; i>=0; i--){
        //     if(height[i]!=0){
        //         low=i-1;
        //         high=i;
        //         break;
        //     }
        // }
        // while(right<height.size()){
        //     if(height[right]>=height[left]){
        //         water+=(height[left]*(right-left-1))-remove1;
        //         left=right;
        //         remove1=0;
        //     }else{
        //         if(height[right]!=0) remove1+=height[right];
        //     }
        //     right++;
        // }
        // while(low>=0){
        //     if(height[low]>=height[high]){
        //         water+=(height[high]*(high-low-1))-remove2;
        //         high=low;
        //     }else{
        //         if(height[low]!=0) remove2+=height[low];
        //     }
        //     low--;
        // }
        // return water;
    }
};