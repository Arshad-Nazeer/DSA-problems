class Solution {
    boolean possible(int[] bloomDay, int day, int m, int k){
        // int counter=0, bouqet=0;
        // for(int x: bloomDay){
        //     if(x<=day) counter++;
        //     else{
        //         bouqet+=(counter/k);
        //         if(bouqet>m) return true;
        //         counter=0;
        //     }
        // }
        // bouqet+=(counter/k);
        // return bouqet>=m ? true: false;
        int counter=0;
        for(int x: bloomDay){
            if(x<=day) {
                counter++;
                if(counter>=(long)k*m) return true;    //early stop
            }
            else counter-=(counter%k);
        }
        // if(counter/k>=m) return true;
        return false;
    }

    public int minDays(int[] bloomDay, int m, int k) {
        // brute force O(n*(max(bloomDay)-min(bloomDay)))
        // if(m*k>bloomDay.length) return -1;
        // int low=Integer.MAX_VALUE, high=Integer.MIN_VALUE;
        // for(int x: bloomDay){
        //     low=Math.min(low, x);    // first flowe to bloom
        //     high=Math.max(high, x);  // final flower to bloom
        // }
        // for(int i=low; i<=high; i++){
        //     if(possible(bloomDay, i, m, k)) return i;
        // }
        // return -1;

        // binary serarch O(n*(log(max(bloomDay)-min(bloomDay))))
        if(m*k>bloomDay.length) return -1;
        int low=Integer.MAX_VALUE, high=Integer.MIN_VALUE, ans=-1;
        for(int x: bloomDay){
            low=Math.min(low, x);    // first flowe to bloom
            high=Math.max(high, x);  // final flower to bloom
        }
        while(low<=high){
            int mid=low+(high-low)/2;
            if(possible(bloomDay, mid, m, k)){
                ans=mid;
                high=mid-1;
            }else low=mid+1;
        }
        return ans;
    }
}