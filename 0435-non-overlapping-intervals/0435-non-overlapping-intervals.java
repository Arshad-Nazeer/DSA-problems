class Solution {
    public int eraseOverlapIntervals(int[][] intervals) {
        Arrays.sort(intervals, (a, b) -> Integer.compare(a[0], b[0]));
        int count=0, i=0;
        while(i<intervals.length-1){
            if(intervals[i][1]<=intervals[i+1][0]) {
                i++;
                continue;
            }
            count++;
            if(intervals[i][1]<intervals[i+1][1]) intervals[i+1][1]=intervals[i][1];
            i++;
        }
        return count;
    }
}