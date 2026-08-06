class Solution {
    public int shipWithinDays(int[] weights, int days) {
        // brute O((sum of weight-max of weights)*number of weights)
        // int high=0, low=Integer.MIN_VALUE, ans;
        // for(int weight: weights) {
        //     high+=weight;
        //     low=Math.max(low, weight);
        // }
        // for(int i=low; i<=high; i++){
        //     int capacity=i, daysTaken=1;
        //     for(int weight: weights){
        //         if(weight<=capacity) capacity-=weight;
        //         else{
        //             daysTaken++;
        //             if (daysTaken > days) break;  
        //             capacity=i-weight;
        //         }
        //     }
        //     if(daysTaken<=days) return i;
        // }
        // return -1;

        // Binary Search O(log(sum of weight-max of weights)*number of weights)
        int high=0, low=Integer.MIN_VALUE, ans=0;
        for(int weight: weights) {
            high+=weight;
            low=Math.max(low, weight);
        }
        while(low<=high){
            int mid=low+(high-low)/2; 
            int capacity=mid, daysTaken=1;
            for(int weight: weights){
                if(capacity>=weight) capacity-=weight;
                else{
                    daysTaken++;
                    if(daysTaken>days) break;
                    capacity=mid-weight;
                }
            }
            if(daysTaken<=days){
                ans=mid;
                high=mid-1;
            }else low=mid+1;
        }
        return ans;
    }
}