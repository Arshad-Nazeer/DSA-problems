class Solution {
    public int eraseOverlapIntervals(int[][] intervals) {
        Arrays.sort(intervals, (a, b) -> Integer.compare(a[1], b[1]));
        int end=Integer.MIN_VALUE, count=0; 
        for(int[] interval: intervals){
            if(end>interval[0]) count++;
            else end=interval[1];
        }
        return count;
    }
}