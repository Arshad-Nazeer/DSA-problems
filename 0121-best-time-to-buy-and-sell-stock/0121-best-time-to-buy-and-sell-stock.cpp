class Solution {
public:
    int maxProfit(vector<int>& prices) {
        // int left=0, right=prices.size()-1;
        // int buy=prices[0], sell=prices[prices.size()-1];
        // while(left<=right){
        //     // if(right==left){
        //     //     if(prices[left]<buy) buy=prices[left]
        //     // }
        //     if(prices[left]<buy) buy=prices[left];
        //     if(prices[right]>sell) sell=prices[right];
        //     left++;
        //     right--;
        // }
        // if(sell-buy>=0) return sell-buy;
        // else return 0;
        int profit=0, mini=100001;
        for(int k: prices){
            // if(k<min) min=k;
            // else profit=max(profit, k-min);
            mini=min(k, mini);
            profit=max(profit, k-mini);
        }
        return profit;
    }
};