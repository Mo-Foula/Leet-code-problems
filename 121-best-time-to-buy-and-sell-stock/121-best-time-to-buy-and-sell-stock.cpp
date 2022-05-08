class Solution {
public:
    

int maxProfit(vector<int>& prices) {
//https://leetcode.com/problems/best-time-to-buy-and-sell-stock/
    int mn = prices[0];
    int prof = 0;
    for (int i = 1; i <prices.size() ; ++i) {
        if(prices[i] < mn)
            mn = prices[i];
        else{
            prof = max(prof,prices[i] - mn);
        }
    }
    return prof;
}
};