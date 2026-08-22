class Solution {
    public int candy(int[] ratings) {
        // // Two pass greedy Tc:-O(n), SC:- O(2*n)
        // int n=ratings.length, ans=0;
        // int[] left=new int[n], right=new int[n];
        
        // left[0]=1;
        // right[n-1]=1;
        // for(int i=1; i<n; i++){
        //     if(ratings[i]>ratings[i-1]) left[i]=left[i-1]+1;
        //     else left[i]=1;

        //     int j=n-i-1;
        //     if(ratings[j]>ratings[j+1]) right[j]=right[j+1]+1;
        //     else right[j]=1;
        // }

        // for(int i=0; i<n; i++){
        //     ans+=Math.max(left[i], right[i]);
        // }
        // return ans;

        // // better two pass greedy TC:-O(n), SC:-O(n)
        // int n=ratings.length, ans=0;
        // int[] left=new int[n];
        
        // left[0]=1;
        // for(int i=1; i<n; i++){
        //     if(ratings[i]>ratings[i-1]) left[i]=left[i-1]+1;
        //     else left[i]=1;
        // }

        // int curr=1;
        // for(int i=n-2; i>=0; i--){
        //     if(ratings[i]>ratings[i+1]) curr=curr+1;
        //     else curr=1;
        //     ans+=Math.max(left[i], curr);
        // }
        // return ans+Math.max(1, left[n-1]);

        // optimal TC:-O(n), Sc:-O(1)
        int sum=1, i=1, n=ratings.length;
        while(i<n){
            if(ratings[i]==ratings[i-1]) {
                sum=sum+1;
                i++;
                continue;
            }  
            int peak=1;
            while(i<n && ratings[i-1]<ratings[i]){
                peak++;
                sum+=peak;
                i++;
            }
            int down=1;
            while(i<n && ratings[i]<ratings[i-1]){
                sum+=down;
                i++;
                down++;
            }
            if(down>peak) sum+=down-peak;
        }
        return sum;
    }
}