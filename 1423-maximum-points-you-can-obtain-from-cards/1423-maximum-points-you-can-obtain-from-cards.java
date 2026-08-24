class Solution {
    // public int recur(int[] cardPoints, int i, int j, int k){
    //     if(k==0) return 0;
    //     return Math.max(cardPoints[i]+recur(cardPoints, i+1, j, k-1), cardPoints[j]+recur(cardPoints, i, j-1, k-1));
    // }

    public int maxScore(int[] cardPoints, int k) {
        // recursion T:-O(2^k)
        // return recur(cardPoints, 0, cardPoints.length-1, k);

        // iterative brute force TC:-O(k^2)
        // int score=0, n=cardPoints.length;
        // for(int i=k; i>=0; i--){
        //     int sum=0;
        //     for(int j=0; j<i; j++) sum+=cardPoints[j];
        //     for(int j=0; j<k-i; j++) sum+=cardPoints[n-1-j];
        //     score=Math.max(sum, score);
        // }
        // return score;

        // sliding window tracking sum of sbarray not taken TC:-O(n)
        // int totalsum=0, winsum=0, minsum=0, n=cardPoints.length;
        // for(int i=0; i<=n-1-k; i++) {
        //     totalsum+=cardPoints[i];
        //     winsum+=cardPoints[i];
        // }
        // minsum=winsum;
        // int left=0;
        // for(int i=n-k; i<n; i++) {
        //     totalsum+=cardPoints[i];
        //     winsum=winsum-cardPoints[left++]+cardPoints[i];
        //     minsum=Math.min(minsum, winsum);
        // }
        // return totalsum-minsum;

        // sliding window tracking sum of taken elements TC:-O(k)
        int winsum=0, score=0, n=cardPoints.length;
        for(int i=0; i<k; i++) winsum+=cardPoints[i];
        score=winsum;
        for(int i=0; i<k; i++) {
            winsum=winsum-cardPoints[k-1-i]+cardPoints[n-1-i];
            score=Math.max(winsum, score);
        }
        return score;
    }
}