class Solution {
    public int findTheWinner(int n, int k) {
        // array approach

        // array approach without removing
        int[] arr=new int[n];
        for(int i=0; i<n; i++) arr[i]=i+1;
        int rounds=1, i=0;
        while(rounds<n){
            int count=1;
            while(count<k){
                if(arr[i]!=0) count++;
                i=(i+1)%n;
            }
            while(arr[i]==0) i=(i+1)%n;
            arr[i]=0;
            i=(i+1)%n;
            rounds++;
        }
        for(int x:  arr){
            if(x!=0) return x;
        }
        return 0;
    }
}