class Solution {
public:
    int maxProfit(vector<int> &prices) {
        if (0==prices.size()) return 0;
        int profit=0;
        int start = prices[0];
        for(int i=1;i<prices.size();++i){
            if(prices[i]>prices[i-1]) continue;
            //if(0<prices[i-1]-start){
                profit+=prices[i-1]-start;
            //}
            start=prices[i];
        }
        //if(0<prices[prices.size()-1]-start){
            profit+=prices[prices.size()-1]-start;
        //}
        return profit;
    }
};
